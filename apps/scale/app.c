
 //======= app.c but this is run the sobel alg========
 


#include <xdc/std.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/osal/Memory.h>
#include <ti/sdo/ce/examples/extensions/scale/scale.h>
#include <ti/sdo/ce/trace/gt.h>



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//opencv header file
#include <opencv/highgui.h>
#include <cv.h>
#include <cxcore.h>





/*v4l2  header file*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <linux/types.h>
#include <linux/videodev2.h>



//#include <QApplication>
//#include <QLabel>

//==================================================

#define NSAMPLES    320*240
#define IFRAMESIZE  (NSAMPLES*2 * sizeof(Int8))  /* raw frame (input) */
#define OFRAMESIZE  (NSAMPLES*3 * sizeof(Int8))  /* scaled frame (output) */

#define APP_SCALEFACTOR 2

static XDAS_Int8 *inBuf;
static XDAS_Int8 *outBuf;
static Int        n;
static Int        i;

static String progName     = "app";
static String scaleName    = "scale";
static String engineName   = "scale";

static String usage = "%s: input-file output-file\n";


static Void scale(SCALE_Handle algo, IplImage *in, IplImage *out);  //opencv used
//static Void scale(SCALE_Handle algo, unsigned char *in, unsigned char *out);  //v4l2 used

extern GT_Mask curMask;




static unsigned char  Video_frame[300][320*240*3];    //300's frame by the 320*240*3 size 





/*=====v4l2 need to used parameter=====*/
typedef int BOOL;
#define  TRUE    1
#define  FALSE    0
#define FILE_VIDEO     "/dev/video0"

#define  IMAGEWIDTH    320
#define  IMAGEHEIGHT   240

static   int      fd;
static   struct   v4l2_capability   cap;
struct v4l2_fmtdesc fmtdesc;
struct v4l2_format fmt,fmtack;
struct v4l2_streamparm setfps;  
struct v4l2_requestbuffers req;
struct v4l2_buffer buf;
enum v4l2_buf_type type;

unsigned char frame_buffer[IMAGEWIDTH*IMAGEHEIGHT*3]; //RGB24 bit
unsigned char frame_buffer_gray[IMAGEWIDTH*IMAGEHEIGHT];// 8 bit
//unsigned char frame_buffer_video[300*IMAGEWIDTH*IMAGEHEIGHT*3]; //access 300 frame of the 8 bit gray


struct buffer
{
    void * start;
    unsigned int length;
} * buffers;

/*====================================*/




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
unsigned char* smain(Int argc, String argv[] )
{
    Engine_Handle ce = NULL;
    SCALE_Handle codec = NULL;
    SCALE_Params params;
    FILE *in = NULL;
    FILE *out = NULL;
    String inFile, outFile;
    Memory_AllocParams allocParams;

   //opencv var
    IplImage *frame;
    IplImage *frame_gray = NULL;
    IplImage *frame_sobel = NULL;
    IplImage *frame_Smooth = NULL;
    IplImage *frame_sobel_8U = NULL;
    IplImage *frame_video = NULL;
    

    

   
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


  



    /* initialize scale factor */
    params.size = sizeof(SCALE_Params);
    params.initialScaleFactor = APP_SCALEFACTOR;

    /* allocate and initialize scale algo on the engine */
    codec = SCALE_create(ce, scaleName, &params);

    if (codec == NULL) {
        printf( "App-> ERROR: can't open codec %s\n", scaleName);
        goto end;
    }






    cvNamedWindow("sobel",CV_WINDOW_AUTOSIZE);
    cvResizeWindow("sobel",320,240);//怕畫面太大讓人看不完,所以顯示視窗設小一點
    CvSize size=cvSize(320,240);
    frame=cvCreateImage(size,IPL_DEPTH_8U,3);
    frame_gray=cvCreateImage(size,IPL_DEPTH_8U,1);
    frame_Smooth=cvCreateImage(size,IPL_DEPTH_8U,1);
    frame_sobel=cvCreateImage(size,IPL_DEPTH_16S,1);
    frame_sobel_8U=cvCreateImage(size,IPL_DEPTH_8U,1);
    frame_video=cvCreateImage(size,IPL_DEPTH_8U,3);







    /*===============v4l2 grab frame by Camera======================*/
        int count=0;
        
        if(init_v4l2() == FALSE) 
        {
            return(FALSE);
        }

        
         /*writer to video avi file*/
         //CvVideoWriter *writer;
         int FPS = 28;
         CvSize AviSize = cvSize(320,240);
         int AviColor = 1;
         CvVideoWriter *writer = cvCreateVideoWriter("out.avi",
                                 CV_FOURCC('M', 'J', 'P', 'G'),
                                 FPS,
                                 AviSize,
                                 AviColor
                                 );

        while(count <  300)
        {

          

            v4l2_grab();

            //yuyv_2_rgb888();  //yuyv to RGB24 
            
            //frame->imageData = frame_buffer;

            
            //RGB888 to GrayScale 
            /*for (i=0;i<IFRAMESIZE;i++)
            { 
            *(frame_buffer_gray+i) = ( *(frame_buffer+i)*30 + *(frame_buffer+i+1)*59  + *(frame_buffer+i+2)*50 ) / 100;
            }*/

            //cvCvtColor(frame,frame_gray,CV_BGR2GRAY);

            //GAUSSIAN's  Smooth
            //cvSmooth(frame_gray , frame_Smooth ,CV_GAUSSIAN,3,0,0,0);

            // cvSobel(frame_Smooth , frame_sobel , 0 , 1 ,3);

            // cvConvertScaleAbs(frame_sobel,frame_sobel_8U,1,0);
           
            scale(codec, frame_gray , frame);
            
            
            memcpy(Video_frame[count] , frame->imageData , 320*240*3);

            //cvSaveImage("rgb24.bmp" , frame,0);
            //cvShowImage("sobel",frame);

                   
            
            //int key=cvWaitKey(33); //once we have displayed th frame,we then wait for 33ms
            printf("the %d frame are completed \n",count);
            count++;
          
        } 



        /*write to avi file by opencv*/
        printf("writing to the avi file\n");
        count = 0 ;
        while(count <  300)
        {
        //write frame to avi video file
        frame_video->imageData = Video_frame[count] ; 
        cvWriteFrame(writer,frame_video);
        count++;
        }
        
    /*=======================================================*/


  






        

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


    close_v4l2();
    cvReleaseImage(&frame_gray);

    
    return (0);
    //return (frame_buffer_video);

    cvDestroyWindow("sobel"); 
    cvReleaseImage(&frame);
    cvReleaseImage(&frame_gray);
    cvReleaseImage(&frame_Smooth);
    cvReleaseImage(&frame_sobel);
    cvReleaseImage(&frame_sobel_8U);
    cvReleaseVideoWriter(&writer);
    cvReleaseVideoWriter(&frame_video);
}










/*
 *  ======== scale ========
 */



//static Void scale(SCALE_Handle codec, unsigned char *in, unsigned char  *out)
static Void scale(SCALE_Handle codec, IplImage *in, IplImage *out)  // opencv used
{
    
    Int32                       status;

    SCALE_InArgs                scaleInArgs;
    SCALE_OutArgs               scaleOutArgs;




    
    /*
     * Read complete frames from in, encode, decode, and write to out.
     */

    //for (n = 0; fread(inBuf, IFRAMESIZE, 1, in) == 1; n++) {
     
  

        memcpy(inBuf,buffers[0].start,IFRAMESIZE);


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

            printf("%d frames processing is complete\n", n);
        }
        else {
            /* failure, exit the processing loop */
            printf("the DSP algorithm is failure ");

        }

        //write to the image data
        out->imageData = outBuf ;
         



}
/*
 *  @(#) ti.sdo.ce.examples.apps.scale; 1,0,0,260; 9-20-2010 16:39:55; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */















int init_v4l2(void)
{
    int i;
    int ret = 0;
    
    //opendev
    if ((fd = open(FILE_VIDEO, O_RDWR)) == -1) 
    {
        printf("Error opening V4L interface\n");
        return (FALSE);
    }

    //query cap
    if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == -1) 
    {
        printf("Error opening device %s: unable to query device.\n",FILE_VIDEO);
        return (FALSE);
    }
    else
    {
         printf("driver:\t\t%s\n",cap.driver);
         printf("card:\t\t%s\n",cap.card);
         printf("bus_info:\t%s\n",cap.bus_info);
         printf("version:\t%d\n",cap.version);
         printf("capabilities:\t%x\n",cap.capabilities);
         
         if ((cap.capabilities & V4L2_CAP_VIDEO_CAPTURE) == V4L2_CAP_VIDEO_CAPTURE) 
         {
            printf("Device %s: supports capture.\n",FILE_VIDEO);
        }

        if ((cap.capabilities & V4L2_CAP_STREAMING) == V4L2_CAP_STREAMING) 
        {
            printf("Device %s: supports streaming.\n",FILE_VIDEO);
        }
    } 
    
    //emu all support fmt
    fmtdesc.index=0;
    fmtdesc.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    printf("Support format:\n");
    while(ioctl(fd,VIDIOC_ENUM_FMT,&fmtdesc)!=-1)
    {
        printf("\t%d.%s\n",fmtdesc.index+1,fmtdesc.description);
        fmtdesc.index++;
    }
    
    //set fmt
        fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;
    fmt.fmt.pix.height = IMAGEHEIGHT;
    fmt.fmt.pix.width = IMAGEWIDTH;
    fmt.fmt.pix.field = V4L2_FIELD_INTERLACED;
    
    if(ioctl(fd, VIDIOC_S_FMT, &fmt) == -1)
    {
        printf("Unable to set format\n");
        return FALSE;
    }     
    if(ioctl(fd, VIDIOC_G_FMT, &fmt) == -1)
    {
        printf("Unable to get format\n");
        return FALSE;
    } 
    {
         printf("fmt.type:\t\t%d\n",fmt.type);
         printf("pix.pixelformat:\t%c%c%c%c\n",fmt.fmt.pix.pixelformat & 0xFF, (fmt.fmt.pix.pixelformat >> 8) & 0xFF,(fmt.fmt.pix.pixelformat >> 16) & 0xFF, (fmt.fmt.pix.pixelformat >> 24) & 0xFF);
         printf("pix.height:\t\t%d\n",fmt.fmt.pix.height);
         printf("pix.width:\t\t%d\n",fmt.fmt.pix.width);
         printf("pix.field:\t\t%d\n",fmt.fmt.pix.field);
    }
    //set fps
    setfps.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    setfps.parm.capture.timeperframe.numerator = 1;
    setfps.parm.capture.timeperframe.denominator = 30;
    if(-1 == ioctl(fd, VIDIOC_S_PARM, setfps)) printf("VIDIOC_S_PARM error");

    printf("numerator: %d, denominator: %d\n",setfps.parm.capture.timeperframe.numerator,setfps.parm.capture.timeperframe.denominator);
    printf("init %s \t[OK]\n",FILE_VIDEO);
        
    return TRUE;
}



int v4l2_grab(void)
{
    unsigned int n_buffers;
    
    //request for 4 buffers 
    req.count=4;
    req.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory=V4L2_MEMORY_MMAP;
    if(ioctl(fd,VIDIOC_REQBUFS,&req)==-1)
    {
        printf("request for buffers error\n");
    }

    //mmap for buffers
    buffers = malloc(req.count*sizeof (*buffers));
    if (!buffers) 
    {
        printf ("Out of memory\n");
        return(FALSE);
    }
    
    for (n_buffers = 0; n_buffers < req.count; n_buffers++) 
    {
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.memory = V4L2_MEMORY_MMAP;
        buf.index = n_buffers;
        //query buffers
        if (ioctl (fd, VIDIOC_QUERYBUF, &buf) == -1)
        {
            printf("query buffer error\n");
            return(FALSE);
        }

        buffers[n_buffers].length = buf.length;
        //map
        buffers[n_buffers].start = mmap(NULL,buf.length,PROT_READ |PROT_WRITE, MAP_SHARED, fd, buf.m.offset);
        if (buffers[n_buffers].start == MAP_FAILED)
        {
            printf("buffer map error\n");
            return(FALSE);
        }
    }
        
    //queue
    for (n_buffers = 0; n_buffers < req.count; n_buffers++)
    {
        buf.index = n_buffers;
        ioctl(fd, VIDIOC_QBUF, &buf);
    } 
    
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ioctl (fd, VIDIOC_STREAMON, &type);
    
    ioctl(fd, VIDIOC_DQBUF, &buf);

    printf("grab yuyv OK\n");
    return(TRUE);
}



int yuyv_2_rgb888(void)
{
    int           i,j;
    unsigned char y1,y2,u,v;
    int r1,g1,b1,r2,g2,b2;
    char * pointer;

    pointer = buffers[0].start;

    for(i=0;i<IMAGEHEIGHT;i++)
    {
    for(j=0;j<IMAGEWIDTH/2;j++)//每次取4个字节，也就是两个像素点，转换rgb，6个字节，还是两个像素点
    {
    y1 = *( pointer + (i*IMAGEWIDTH/2+j)*4);     
    u  = *( pointer + (i*IMAGEWIDTH/2+j)*4 + 1);
    y2 = *( pointer + (i*IMAGEWIDTH/2+j)*4 + 2);
    v  = *( pointer + (i*IMAGEWIDTH/2+j)*4 + 3);

    r1 = y1 + 1.042*(v-128);
    g1 = y1 - 0.34414*(u-128) - 0.71414*(v-128);
    b1 = y1 + 1.772*(u-128);

    r2 = y2 + 1.042*(v-128);
    g2 = y2 - 0.34414*(u-128) - 0.71414*(v-128);
    b2 = y2 + 1.772*(u-128);

    if(r1>255)
    r1 = 255;
    else if(r1<0)
    r1 = 0;

    if(b1>255)
    b1 = 255;
    else if(b1<0)
    b1 = 0;    

    if(g1>255)
    g1 = 255;
    else if(g1<0)
    g1 = 0;    

    if(r2>255)
    r2 = 255;
    else if(r2<0)
    r2 = 0;

    if(b2>255)
    b2 = 255;
    else if(b2<0)
    b2 = 0;    

    if(g2>255)
    g2 = 255;
    else if(g2<0)
    g2 = 0;        
    
    
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6    ) = (unsigned char)b1;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 1) = (unsigned char)g1;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 2) = (unsigned char)r1;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 3) = (unsigned char)b2;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 4) = (unsigned char)g2;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 5) = (unsigned char)r2;
    
    /*
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6    ) = (unsigned char)r1;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 1) = (unsigned char)g1;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 2) = (unsigned char)b1;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 3) = (unsigned char)r2;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 4) = (unsigned char)g2;
    *(frame_buffer + (i*IMAGEWIDTH/2+j)*6 + 5) = (unsigned char)b2;
    */
    }
  }
    printf("change to RGB OK \n");
}


int close_v4l2(void)
{
     if(fd != -1) 
     {
         close(fd);
         return (TRUE);
     }
     return (FALSE);
}

