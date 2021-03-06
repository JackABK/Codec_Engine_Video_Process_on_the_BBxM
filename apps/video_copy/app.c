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
#include "v4l2grab.h" 

/*use opencv display yes or no*/
#define USE_OPENCV_DISPLAY

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


/*global uart fd var.*/
struct fd{
	int uart1;
	int uart2;
}fd;


/*function define the here.*/
void read_uart1_task(void *p);
void read_uart2_task(void *p);

extern GT_Mask curMask;

/*=====v4l2 need to used parameter=====*/
typedef int BOOL;
#define  TRUE    1
#define  FALSE    0
#define FILE_VIDEO     "/dev/video0"

#define  IMAGEWIDTH    320
#define  IMAGEHEIGHT   240


/*extern by v4l2 used buffers raw data*/
extern struct buffer{
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


    
#if 0
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
 #endif   


        /*init uart*/
        uart_init(fd.uart1);
		uart_init(fd.uart2);
 
         /*thread*/
         pthread_t thread1 , thread2; 
         pthread_create(&thread1, NULL , &read_uart1_task, NULL);
         pthread_create(&thread2, NULL , &read_uart2_task, NULL);



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
#ifdef USE_OPENCV_DISPLAY
    cvNamedWindow("sobel",CV_WINDOW_AUTOSIZE);
    cvResizeWindow("sobel",320,240);//怕畫面太大讓人看不完,所以顯示視窗設小一點
#endif
    CvSize size=cvSize(320,240);
    frame=cvCreateImage(size,IPL_DEPTH_8U,3);
    frame_gray=cvCreateImage(size,IPL_DEPTH_8U,1);
    frame_Smooth=cvCreateImage(size,IPL_DEPTH_8U,1);
    frame_sobel=cvCreateImage(size,IPL_DEPTH_16S,1);
    frame_sobel_8U=cvCreateImage(size,IPL_DEPTH_8U,1);

    /* v4l2 init */
     int count=0;

     deviceOpen();
     deviceInit();
     /*start capturing*/
     captureStart();


    /*===============v4l2 grab frame by Camera======================*/
    while(1){
        mainLoop(); /*this is the v4l2grab frame*/
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
/************************** decode the frame**************************************/
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


#ifdef CACHE_ENABLED
        /* Writeback the outBuf. */
        Memory_cacheWb(outBuf, OFRAMESIZE);
#endif

        /* write to file */
        //fwrite(encodedBuf, EFRAMESIZE, 1, out);

        frame->imageData =  encoded[0];
        frame_gray->imageData = dst[0];
        //cvCvtColor(frame,frame_gray,CV_BGR2GRAY);

#ifdef USE_OPENCV_DISPLAY
        cvShowImage("sobel",frame_gray);
        int key=cvWaitKey(33);
#endif 
        //cvSaveImage("22.bmp",frame_gray,0);
        printf("the %d frame are completed \n",count);
        count++;

    }/*end while*/

#ifdef USE_OPENCV_DISPLAY
    cvDestroyWindow("sobel"); 
#endif 
    cvReleaseImage(&frame);
    cvReleaseImage(&frame_gray);
    cvReleaseImage(&frame_Smooth);
    cvReleaseImage(&frame_sobel);
    cvReleaseImage(&frame_sobel_8U);

    GT_1trace(curMask, GT_1CLASS, "%d frames encoded/decoded\n", n);
}
/*
 *  @(#) ti.sdo.ce.examples.apps.video_copy; 1, 0, 0,74; 9-20-2010 16:40:32; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */


/*uart1 read task*/
void read_uart1_task(void *p)
{
        int res;
        char buf[256];
        while(1){
                /*receive from uart*/
                res = read(fd.uart1, buf, 255);
                buf[res]=0;
                printf("res=%d buf=%s\n", res, buf);
                if (buf[0] == '@') break;

                /*Send to Arduino*/
                //res=write(fd_usb , buf , sizeof(buf));

                /*else do not somthing*/        
        }
        return NULL;
}

/*uart2 read task*/
void read_uart2_task(void *p)
{
        int res;
        char buf[256];
        while(1){
                /*receive from uart*/
                res = read(fd.uart2, buf, 255);
                buf[res]=0;
                printf("res=%d buf=%s\n", res, buf);
                if (buf[0] == '@') break;

                /*Send to Arduino*/
                //res=write(fd_usb , buf , sizeof(buf));

                /*else do not somthing*/        
        }
        return NULL;
}
