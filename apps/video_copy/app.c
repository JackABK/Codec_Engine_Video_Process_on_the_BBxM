/* 
 * Copyright (c) 2010, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
/*
 *  ======== app.c ========
 */
#include <xdc/std.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/osal/Memory.h>


#include <ti/sdo/ce/video/viddec.h>
#include <ti/sdo/ce/video/videnc.h>
#include <ti/sdo/ce/trace/gt.h>

#include <string.h>  /* for memset */

#include <stdio.h>
#include <stdlib.h>



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

/*
 * If an XDAIS algorithm _may_ use DMA, buffers provided to it need to be
 * aligned on a cache boundary.
 */

#ifdef CACHE_ENABLED

/*
 * If buffer alignment isn't set on the compiler's command line, set it here
 * to a default value.
 */
#ifndef BUFALIGN
#define BUFALIGN 128
#endif
#else

/* Not a cached system, no buffer alignment constraints */
#define BUFALIGN Memory_DEFAULTALIGNMENT

#endif


/*Image Display ??*/
#define USE_IMAGE_DISPLAY



#define NSAMPLES    320*240  /* must be multiple of 128 for cache/DMA reasons */
#define IFRAMESIZE  (NSAMPLES * 2 * sizeof(Int8))  /* raw frame (input) */
#define EFRAMESIZE  (NSAMPLES * 3 * sizeof(Int8))  /* encoded frame */
#define OFRAMESIZE  (NSAMPLES * sizeof(Int8))  /* decoded frame (output) */



static XDAS_Int8 *inBuf;
static XDAS_Int8 *encodedBuf;
static XDAS_Int8 *outBuf;

static String progName     = "app";
static String decoderName  = "viddec_copy";
static String encoderName  = "videnc_copy";
static String engineName   = "video_copy";

static String usage = "%s: input-file output-file\n";

static Void encode_decode(VIDENC_Handle enc, VIDDEC_Handle dec, FILE *in,
    FILE *out);

extern GT_Mask curMask;




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




//opencv var
IplImage *frame;
IplImage *frame_gray = NULL;
IplImage *frame_sobel = NULL;
IplImage *frame_Smooth = NULL;
IplImage *frame_sobel_8U = NULL;



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
    VIDDEC_Handle dec = NULL;
    VIDENC_Handle enc = NULL;
    FILE *in = NULL;
    FILE *out = NULL;
    String inFile, outFile;
    Memory_AllocParams allocParams;

    if (argc <= 1) {
        inFile = "./in.dat";
        outFile = "./out.dat";
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

    GT_0trace(curMask, GT_1CLASS, "App-> Application started.\n");

    /* allocate input, encoded, and output buffers */
    allocParams.type = Memory_CONTIGPOOL;
    allocParams.flags = Memory_NONCACHED;
    allocParams.align = BUFALIGN;
    allocParams.seg = 0;

    inBuf = (XDAS_Int8 *)Memory_alloc(IFRAMESIZE, &allocParams);
    encodedBuf = (XDAS_Int8 *)Memory_alloc(EFRAMESIZE, &allocParams);
    outBuf = (XDAS_Int8 *)Memory_alloc(OFRAMESIZE, &allocParams);

    if ((inBuf == NULL) || (encodedBuf == NULL) || (outBuf == NULL)) {
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

    /* allocate and initialize video decoder on the engine */
    dec = VIDDEC_create(ce, decoderName, NULL);
    if (dec == NULL) {
        printf( "App-> ERROR: can't open codec %s\n", decoderName);
        goto end;
    }

    /* allocate and initialize video encoder on the engine */
    enc = VIDENC_create(ce, encoderName, NULL);
    if (enc == NULL) {
        fprintf(stderr, "%s: error: can't open codec %s\n",
            progName, encoderName);
        goto end;
    }

    /* use engine to encode, then decode the data */
    encode_decode(enc, dec, in, out);

end:
    /* teardown the codecs */
    if (enc) {
        VIDENC_delete(enc);
    }
    if (dec) {
        VIDDEC_delete(dec);
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
    if (encodedBuf) {
        Memory_free(encodedBuf, EFRAMESIZE, &allocParams);
    }
    if (outBuf) {
        Memory_free(outBuf, OFRAMESIZE, &allocParams);
    }

    GT_0trace(curMask, GT_1CLASS, "app done.\n");
    return (0);
}

/*
 *  ======== encode_decode ========
 */
static Void encode_decode(VIDENC_Handle enc, VIDDEC_Handle dec, FILE *in,
    FILE *out)
{
    Int                         n;
    Int32                       status;

    VIDDEC_InArgs               decInArgs;
    VIDDEC_OutArgs              decOutArgs;
    VIDDEC_DynamicParams        decDynParams;
    VIDDEC_Status               decStatus;

    VIDENC_InArgs               encInArgs;
    VIDENC_OutArgs              encOutArgs;
    VIDENC_DynamicParams        encDynParams;
    VIDENC_Status               encStatus;

    XDM_BufDesc                 inBufDesc;
    XDAS_Int8                  *src[XDM_MAX_IO_BUFFERS];
    XDAS_Int32                  inBufSizes[XDM_MAX_IO_BUFFERS];

    XDM_BufDesc                 encodedBufDesc;
    XDAS_Int8                  *encoded[XDM_MAX_IO_BUFFERS];
    XDAS_Int32                  encBufSizes[XDM_MAX_IO_BUFFERS];

    XDM_BufDesc                 outBufDesc;
    XDAS_Int8                  *dst[XDM_MAX_IO_BUFFERS];
    XDAS_Int32                  outBufSizes[XDM_MAX_IO_BUFFERS];

    /* clear and initialize the buffer descriptors */
    memset(src,     0, sizeof(src[0])     * XDM_MAX_IO_BUFFERS);
    memset(encoded, 0, sizeof(encoded[0]) * XDM_MAX_IO_BUFFERS);
    memset(dst,     0, sizeof(dst[0])     * XDM_MAX_IO_BUFFERS);

    src[0]     = inBuf;
    encoded[0] = encodedBuf;
    dst[0]     = outBuf;

    inBufDesc.numBufs = encodedBufDesc.numBufs = outBufDesc.numBufs = 1;
   


    inBufDesc.bufSizes      = inBufSizes;
    encodedBufDesc.bufSizes = encBufSizes;
    outBufDesc.bufSizes     = outBufSizes;

    //Note , this declaration is tell the memtab how much need to  allocate the buf sizes  
    inBufSizes[0] = IFRAMESIZE;
    encBufSizes[0] = EFRAMESIZE;
    outBufSizes[0] = OFRAMESIZE;

    inBufDesc.bufs      = src;
    encodedBufDesc.bufs = encoded;
    outBufDesc.bufs     = dst;

    /* initialize all "sized" fields */
    encInArgs.size    = sizeof(encInArgs);
    decInArgs.size    = sizeof(decInArgs);
    encOutArgs.size   = sizeof(encOutArgs);
    decOutArgs.size   = sizeof(decOutArgs);
    encDynParams.size = sizeof(encDynParams);
    decDynParams.size = sizeof(decDynParams);
    encStatus.size    = sizeof(encStatus);
    decStatus.size    = sizeof(decStatus);

    /*
     * Query the encoder and decoder.
     * This app expects the encoder to provide 1 buf in and get 1 buf out,
     * and the buf sizes of the in and out buffer must be able to handle
     * NSAMPLES bytes of data.
     */
    status = VIDENC_control(enc, XDM_GETSTATUS, &encDynParams, &encStatus);
    if (status != VIDENC_EOK) {
        /* failure, report error and exit */
        GT_1trace(curMask, GT_7CLASS, "encode control status = 0x%x\n", status);
        return;
    }

    /* Validate this encoder codec will meet our buffer requirements */
    if ((inBufDesc.numBufs < encStatus.bufInfo.minNumInBufs) ||
        (IFRAMESIZE < encStatus.bufInfo.minInBufSize[0]) ||
        (encodedBufDesc.numBufs < encStatus.bufInfo.minNumOutBufs) ||
        (EFRAMESIZE < encStatus.bufInfo.minOutBufSize[0])) {

        /* failure, report error and exit */
        GT_0trace(curMask, GT_7CLASS,
            "Error:  encoder codec feature conflict\n");
        return;
    }


//#if 0
    status = VIDDEC_control(dec, XDM_GETSTATUS, &decDynParams, &decStatus);
    if (status != VIDDEC_EOK) {
        /* failure, report error and exit */
        GT_1trace(curMask, GT_7CLASS, "decode control status = 0x%x\n", status);
        return;
    }
//#endif


    /* Validate this decoder codec will meet our buffer requirements */
    if ((encodedBufDesc.numBufs < decStatus.bufInfo.minNumInBufs) ||
        (EFRAMESIZE < decStatus.bufInfo.minInBufSize[0]) ||
        (outBufDesc.numBufs < decStatus.bufInfo.minNumOutBufs) ||
        (OFRAMESIZE < decStatus.bufInfo.minOutBufSize[0])) {

        /* failure, report error and exit */
        GT_0trace(curMask, GT_7CLASS,
            "App-> ERROR: decoder does not meet buffer requirements.\n");
        return;
    }



    /*
     * Read complete frames from in, encode, decode, and write to out.
     */


    /* opencv create init image */
	#ifdef USE_IMAGE_DISPLAY
    //cvNamedWindow("sobel",CV_WINDOW_AUTOSIZE);
    //cvResizeWindow("sobel",320,240);//怕畫面太大讓人看不完,所以顯示視窗設小一點
	#endif
    CvSize size=cvSize(320,240);
    frame=cvCreateImage(size,IPL_DEPTH_8U,3);
    frame_gray=cvCreateImage(size,IPL_DEPTH_8U,1);
    frame_Smooth=cvCreateImage(size,IPL_DEPTH_8U,1);
    frame_sobel=cvCreateImage(size,IPL_DEPTH_16S,1);
    frame_sobel_8U=cvCreateImage(size,IPL_DEPTH_8U,1);

    /* v4l2 init */
     int count=0;

        
     if(init_v4l2() == FALSE) 
     {
        return(FALSE);
     }


    //for (n = 0; fread(inBuf, IFRAMESIZE, 1, in) == 1; n++) {

    /*===============v4l2 grab frame by Camera======================*/
	 while(count <  300){

			 v4l2_grab();
			 //inBuf = (XDAS_Int8*) buffers[0].start; //buffers[0] access the yuv422 raw data
			 memcpy(inBuf,buffers[0].start,IFRAMESIZE);

#ifdef CACHE_ENABLED
#ifdef xdc_target__isaCompatible_64P
			 /*
			  *  fread() on this processor is implemented using CCS's stdio, which
			  *  is known to write into the cache, not physical memory.  To meet
			  *  xDAIS DMA Rule 7, we must writeback the cache into physical
			  *  memory.  Also, per DMA Rule 7, we must invalidate the buffer's
			  *  cache before providing it to any xDAIS algorithm.
			  */
			 Memory_cacheWbInv(inBuf, IFRAMESIZE);
#else
#error Unvalidated config - add appropriate fread-related cache maintenance
#endif
			 /* Per DMA Rule 7, our output buffer cache lines must be cleaned */
			 Memory_cacheInv(encodedBuf, EFRAMESIZE);
#endif

			 GT_1trace(curMask, GT_1CLASS, "App-> Processing frame %d...\n", count);

			 /* encode the frame */
			 status = VIDENC_process(enc, &inBufDesc, &encodedBufDesc, &encInArgs,
							 &encOutArgs);

			 GT_2trace(curMask, GT_2CLASS,
							 "App-> Encoder frame %d process returned - 0x%x)\n",
							 count, status);

#ifdef CACHE_ENABLED
			 /* Writeback this outBuf from the previous call.  Also, as encodedBuf
			  * is an inBuf to the next process call, we must invalidate it also, to
			  * clean buffer lines.
			  */
			 Memory_cacheWbInv(encodedBuf, EFRAMESIZE);

			 /* Per DMA Rule 7, our output buffer cache lines must be cleaned */
			 Memory_cacheInv(outBuf, OFRAMESIZE);
#endif

			 if (status != VIDENC_EOK) {
					 GT_3trace(curMask, GT_7CLASS,
									 "App-> Encoder frame %d processing FAILED, status = 0x%x, "
									 "extendedError = 0x%x\n", count, status, encOutArgs.extendedError);
					 break;
			 }



			 /***************************decode part (Unuse)***********************************/
			 /* decode the frame */
			 //#if 0
			 status = VIDDEC_process(dec, &encodedBufDesc, &outBufDesc, &decInArgs,
							 &decOutArgs);

			 GT_2trace(curMask, GT_2CLASS,
							 "App-> Decoder frame %d process returned - 0x%x)\n",
							 n, status);

			 if (status != VIDDEC_EOK) {
					 GT_3trace(curMask, GT_7CLASS,
									 "App-> Decoder frame %d processing FAILED, status = 0x%x, "
									 "extendedError = 0x%x\n", n, status, decOutArgs.extendedError);
					 break;
			 }
			 //#endif


#ifdef CACHE_ENABLED
			 /* Writeback the outBuf. */
			 Memory_cacheWb(outBuf, OFRAMESIZE);
#endif




			 /* write to file */
			 //fwrite(encodedBuf, EFRAMESIZE, 1, out);

			 frame->imageData =  encoded[0];
			 frame_gray->imageData = dst[0];
			 //cvCvtColor(frame,frame_gray,CV_BGR2GRAY);

#ifdef USE_IMAGE_DISPLAY
#endif

			 //cvSaveImage("22.bmp",frame_gray,0);

			 cvShowImage("sobel",frame_gray);
			 int key=cvWaitKey(33);
			 printf("the %d frame are completed \n",count);
			 count++;
	 }//end while 

    cvReleaseImage(&frame);
    cvReleaseImage(&frame_gray);
    cvReleaseImage(&frame_Smooth);
    cvReleaseImage(&frame_sobel);
    cvReleaseImage(&frame_sobel_8U);
	#ifdef USE_IMAGE_DISPLAY
    cvDestroyWindow("sobel"); 
	#endif    

    GT_1trace(curMask, GT_1CLASS, "%d frames encoded/decoded\n", n);
}
/*
 *  @(#) ti.sdo.ce.examples.apps.video_copy; 1, 0, 0,74; 9-20-2010 16:40:32; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

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
    
    //request for 4 buffers , but I only need to used one buffers , since I only used one camera. 
    req.count=4;
    req.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory=V4L2_MEMORY_MMAP;
    if(ioctl(fd,VIDIOC_REQBUFS,&req)==-1)
    {
        printf("request for buffers error\n");
        return(FALSE);
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
			/*not return*/
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


	#if 0
	buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;
	//buf.index = 0;

    //queue
	for (n_buffers = 0; n_buffers < req.count; n_buffers++)
	{
			buf.index = n_buffers;
			if(-1 == ioctl(fd, VIDIOC_QBUF, &buf))
			{
					perror("Query Buffer");
					return(FALSE);
			}
	} 

	if(-1 == ioctl(fd, VIDIOC_STREAMON, &buf.type))
	{
			perror("Start Capture");
			return(FALSE);
	}
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(fd, &fds);
	struct timeval tv = {0};
	tv.tv_sec = 2;
	int r = select(fd+1, &fds, NULL, NULL, &tv);
	if(-1 == r)
	{
			perror("Waiting for Frame");
			return(FALSE);
	}
	if(-1 == ioctl(fd, VIDIOC_DQBUF, &buf))
	{
			perror("Retrieving Frame");
			return(FALSE);
	}
	#endif


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
