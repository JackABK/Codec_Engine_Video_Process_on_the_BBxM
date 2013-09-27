
 //======= app.c but this is run the sobel alg========
 
#include <xdc/std.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/osal/Memory.h>
#include <ti/sdo/ce/examples/extensions/scale/scale.h>
#include <ti/sdo/ce/trace/gt.h>



#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#define NSAMPLES    800*600
#define IFRAMESIZE  (NSAMPLES * sizeof(Int8))  /* raw frame (input) */
#define OFRAMESIZE  (NSAMPLES * sizeof(Int8))  /* scaled frame (output) */

#define APP_SCALEFACTOR 2

static XDAS_Int8 *inBuf;
static XDAS_Int8 *outBuf;


static String progName     = "app";
static String scaleName    = "scale";
static String engineName   = "scale";

static String usage = "%s: input-file output-file\n";

static Void scale(SCALE_Handle algo, FILE *in, FILE *out);

extern GT_Mask curMask;

/*
 *  ======== createInFileIfMissing ========
 */
static void createInFileIfMissing( char *inFileName )
{
    int i;
    FILE *f = fopen(inFileName, "rb");
    if (f == NULL) {
        printf( "Input file '%s' not found, generating one.\n", inFileName );
        f = fopen( inFileName, "wb" );
        for (i = 0; i < 1024; i++) {
            fwrite( &i, sizeof( i ), 1, f );
        }
    }
    fclose( f );
}

/*
 *  ======== smain ========
 */
Int smain(Int argc, String argv[])
{
    Engine_Handle ce = NULL;
    SCALE_Handle codec = NULL;
    SCALE_Params params;
    FILE *in = NULL;
    FILE *out = NULL;
    String inFile, outFile;
    Memory_AllocParams allocParams;

    unsigned char color_table_temp[1024]={0}; 

   //opencv var
    IplImage * frame;
    IplImage * gray_frame = NULL;
    IplImage * BinaryImage =NULL;
    CvCapture *cap=cvCreateCameraCapture(0);
    cvSetCaptureProperty(cap,CV_CAP_PROP_FRAME_WIDTH,320);
    cvSetCaptureProperty(cap,CV_CAP_PROP_FRAME_HEIGHT,240);
    cvSetCaptureProperty(cap,CV_CAP_PROP_FPS,30);



   /*YC added the bmp struct*/
#pragma pack(1)                       //採用1byte為單位對齊(需要讀檔頭)  
    static struct BMP_file_header {   //Total 54 bytes
           unsigned char Identifier[2];                     
           unsigned long  File_Size;            
           unsigned long  Reserved;          
           unsigned long  Bitmap_Data_Offset;  
           unsigned long   Bitmap_Header_Size;   
           unsigned long   Width;
           unsigned long   Height;       
           unsigned short  Planes;        
           unsigned short  Bits_Per_Pixel;      
           unsigned long   Compression;      
           unsigned long   Bitmap_Data_Size;  
           unsigned long   H_Resolution;        
           unsigned long   V_Resolution;         
           unsigned long   Used_Colors;           
           unsigned long   Important_Colors;  
    } BMP_header;  
    #pragma pack()

   static struct BMP_file_header *header_temp; 

    if (argc <= 1) {
        inFile = "./test2_8bit_gray.bmp";
        outFile = "./test2_8bit_sobel.bmp";
        createInFileIfMissing(inFile);
    }
    else if (argc == 3) {
        progName = argv[0];
        inFile = argv[1];
        outFile = argv[2];
    }
    else {
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }

    printf("App-> Application started.\n");

    /* allocate input, encoded, and output buffers */
    allocParams.type = Memory_CONTIGPOOL;
    allocParams.flags = Memory_NONCACHED;
    allocParams.align = Memory_DEFAULTALIGNMENT;
    allocParams.seg = 0;

    inBuf = (XDAS_Int8 *)Memory_alloc(IFRAMESIZE, &allocParams);
    outBuf = (XDAS_Int8 *)Memory_alloc(OFRAMESIZE, &allocParams);
    

    if ((inBuf == NULL) || (outBuf == NULL)) {
        goto end;
    }



    /* open file streams for input and output */
    if ((in = fopen(inFile, "rb")) == NULL) {
        printf("App-> ERROR: can't read file %s\n", inFile);
        goto end;
    }
    if ((out = fopen(outFile, "wb")) == NULL) {
        printf("App-> ERROR: can't write to file %s\n", outFile);
        goto end;
    }

    /* reset, load, and start DSP Engine */
    if ((ce = Engine_open(engineName, NULL, NULL)) == NULL) {
        fprintf(stderr, "%s: error: can't open engine %s\n",
            progName, engineName);
        goto end;
    }


    //copy the Bmp_header
    header_temp=&BMP_header;                                                                    
    fread(header_temp,54,sizeof(unsigned char),in);                        
    fwrite(header_temp,54,sizeof(unsigned char),out);
 
    //copy the color table BGRA total 256*4=1024 bytes                                                                       
    fread(color_table_temp,1024,sizeof(unsigned char),in);
    fwrite(color_table_temp,1024,sizeof(unsigned char),out);  





   //capture video's frame
    frame = cvQueryFrame(cap);
   


    /* initialize scale factor */
    params.size = sizeof(SCALE_Params);
    params.initialScaleFactor = APP_SCALEFACTOR;

    /* allocate and initialize scale algo on the engine */
    codec = SCALE_create(ce, scaleName, &params);
    if (codec == NULL) {
        printf( "App-> ERROR: can't open codec %s\n", scaleName);
        goto end;
    }

    /* use engine to encode, then decode the data */
    scale(codec, in, out);




end:
    /* teardown the codec */
    if (codec) {
        SCALE_delete(codec);
    }

    /* close the engine */
    if (ce) {
        Engine_close(ce);
    }

    /* close the files */
    if (in) {
        fclose(in);
    }
    if (out) {
        fclose(out);
    }

    /* free buffers */
    if (inBuf) {
        Memory_free(inBuf, IFRAMESIZE, &allocParams);
    }
    if (outBuf) {
        Memory_free(outBuf, OFRAMESIZE, &allocParams);
    }

    printf("app done.\n");
    return (0);
}















/*
 *  ======== scale ========
 */
static Void scale(SCALE_Handle codec, FILE *in, FILE *out)
{
    Int                         n;
    Int32                       status;

    SCALE_InArgs                scaleInArgs;
    SCALE_OutArgs               scaleOutArgs;




    
    /*
     * Read complete frames from in, encode, decode, and write to out.
     */
    for (n = 0; fread(inBuf, IFRAMESIZE, 1, in) == 1; n++) {
        printf("App-> Processing frame %d...\n", n);

        scaleInArgs.inBufSize = IFRAMESIZE;
        scaleInArgs.outBufSize = OFRAMESIZE;
        scaleInArgs.inBufValidBytes = IFRAMESIZE;

        /* scale the frame */
        status = SCALE_process(codec, inBuf, outBuf, &scaleInArgs,
            &scaleOutArgs);

        GT_2trace(curMask, GT_2CLASS, "App-> Scaled frame %d (0x%x)\n",
            n, status);

   
        if (status == SCALE_EOK) {
            GT_1trace(curMask, GT_2CLASS, "\toutArgs:  (0x%x)\n",
                scaleOutArgs.outBufValidBytes);
        }
        else {
            /* failure, exit the processing loop */
            break;
        }

        /* write to file */
        fwrite(outBuf, OFRAMESIZE, 1, out);
    }

    
    printf("%d frames scaled\n", n);
}
/*
 *  @(#) ti.sdo.ce.examples.apps.scale; 1,0,0,260; 9-20-2010 16:39:55; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */

