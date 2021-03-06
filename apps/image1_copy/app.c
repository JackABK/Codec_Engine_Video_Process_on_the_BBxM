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
#include <xdc/cfg/global.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/osal/Memory.h>
#include <ti/sdo/ce/image1/imgdec1.h>
#include <ti/sdo/ce/image1/imgenc1.h>
#include <ti/sdo/ce/trace/gt.h>

#include <stdio.h>
#include <string.h>  /* for memset */
#include <stdlib.h>
#ifdef USE_POWER_MANAGEMENT
#include <unistd.h>
#include <sys/time.h>  /* select() */
#include <sys/types.h>  /* select() */
#include <ti/bios/power/lpm.h>
#endif

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


#define NSAMPLES    1024  /* must be multiple of 128 for cache/DMA reasons */
#define IFRAMESIZE  (NSAMPLES * sizeof(Int8))  /* raw frame (input) */
#define EFRAMESIZE  (NSAMPLES * sizeof(Int8))  /* encoded frame */
#define OFRAMESIZE  (NSAMPLES * sizeof(Int8))  /* decoded frame (output) */
#define MAXVERSIONSIZE 128

static XDAS_Int8 *inBuf;
static XDAS_Int8 *encodedBuf;
static XDAS_Int8 *outBuf;
static XDAS_Int8 *versionBuf;   /* acquire optional version from codecs */

static String progName     = "app";
static String decoderName  = "imgdec1_copy";
static String encoderName  = "imgenc1_copy";
static String engineName   = "image1_copy";
static Int appPause = 0;

static String usage = "%s: input-file output-file\n";

static Void encode_decode(IMGENC1_Handle enc, IMGDEC1_Handle dec, FILE *in,
    FILE *out);

extern GT_Mask curMask;

#ifdef USE_POWER_MANAGEMENT
LPM_Handle lpmHandle = NULL;
#endif


/*
 *  ======== createInFileIfMissing ========
 */
static void createInFileIfMissing(char *inFileName)
{
    int i;
    FILE *f = fopen(inFileName, "rb");
    if (f == NULL) {
        printf("Input file '%s' not found, generating one.\n", inFileName);
        f = fopen( inFileName, "wb" );
        for (i = 0; i < 1024; i++) {
            fwrite(&i, sizeof(i), 1, f);
        }
    }
    fclose(f);
}

/*
 *  ======== smain ========
 */
Int smain(Int argc, String argv[])
{
    Engine_Handle ce = NULL;
    IMGDEC1_Handle dec = NULL;
    IMGENC1_Handle enc = NULL;
    FILE *in = NULL;
    FILE *out = NULL;
    String inFile, outFile;
    Memory_AllocParams allocParams;

    if (argc <= 1) {
        inFile = "./in.dat";
        outFile = "./out.dat";
        createInFileIfMissing(inFile);
    }
    else if (argc >= 3) {
        progName = argv[0];
        inFile = argv[1];
        outFile = argv[2];
    }
    else {
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }

    if ((argc == 4) && (argv[3][0] == '1')) {
        appPause = 1;
    }


    GT_0trace(curMask, GT_1CLASS, "App-> Application started.\n");

    /* allocate buffers */
    allocParams.type = Memory_CONTIGPOOL;
    allocParams.flags = Memory_NONCACHED;
    allocParams.align = BUFALIGN;
    allocParams.seg = 0;

    inBuf = (XDAS_Int8 *)Memory_alloc(IFRAMESIZE, &allocParams);
    encodedBuf = (XDAS_Int8 *)Memory_alloc(EFRAMESIZE, &allocParams);
    outBuf = (XDAS_Int8 *)Memory_alloc(OFRAMESIZE, &allocParams);
    versionBuf = (XDAS_Int8 *)Memory_alloc(MAXVERSIONSIZE, &allocParams);

    if ((inBuf == NULL) || (encodedBuf == NULL) || (outBuf == NULL) ||
        (versionBuf == NULL)) {

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
    dec = IMGDEC1_create(ce, decoderName, NULL);
    if (dec == NULL) {
        printf( "App-> ERROR: can't open codec %s\n", decoderName);
        goto end;
    }

    /* allocate and initialize video encoder on the engine */
    enc = IMGENC1_create(ce, encoderName, NULL);
    if (enc == NULL) {
        fprintf(stderr, "%s: error: can't open codec %s\n",
            progName, encoderName);
        goto end;
    }

#ifdef USE_POWER_MANAGEMENT
    /* open local power manager */
    if (Global_usePowerManagement) {
       LPM_Status  lpmStat = LPM_SOK;
       lpmStat = LPM_open("/dev/lpm0", &lpmHandle);

       if (lpmStat != LPM_SOK) {
            fprintf(stderr, "%s: error: LPM_open() failed\n", progName);
            goto end;
       }
    }
#endif

    /* use engine to encode, then decode the data */
    encode_decode(enc, dec, in, out);

end:
#ifdef USE_POWER_MANAGEMENT
    /* close local power manager */
    if (lpmHandle != NULL) {
       LPM_close(lpmHandle);
    }
#endif

    /* teardown the codecs */
    if (enc) {
        IMGENC1_delete(enc);
    }
    if (dec) {
        IMGDEC1_delete(dec);
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
    if (versionBuf) {
        Memory_free(versionBuf, MAXVERSIONSIZE, &allocParams);
    }

    GT_0trace(curMask, GT_1CLASS, "app done.\n");
    return (0);
}

/*
 *  ======== encode_decode ========
 */
static Void encode_decode(IMGENC1_Handle enc, IMGDEC1_Handle dec, FILE *in,
    FILE *out)
{
    Int                         n;
    Int32                       status;

    IMGDEC1_InArgs              decInArgs;
    IMGDEC1_OutArgs             decOutArgs;
    IMGDEC1_DynamicParams       decDynParams;
    IMGDEC1_Status              decStatus;

    IMGENC1_InArgs              encInArgs;
    IMGENC1_OutArgs             encOutArgs;
    IMGENC1_DynamicParams       encDynParams;
    IMGENC1_Status              encStatus;

    XDM1_BufDesc                inBufDesc;
    XDM1_BufDesc                encodedBufDesc;
    XDM1_BufDesc                outBufDesc;

    /* initialize the buffer descriptors */
    inBufDesc.numBufs = encodedBufDesc.numBufs = outBufDesc.numBufs = 1;
    inBufDesc.descs[0].bufSize = encodedBufDesc.descs[0].bufSize =
        outBufDesc.descs[0].bufSize = NSAMPLES;

    inBufDesc.descs[0].buf      = inBuf;
    encodedBufDesc.descs[0].buf = encodedBuf;
    outBufDesc.descs[0].buf     = outBuf;

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
     * Note that we use versionBuf in both the encoder and decoder.  In this
     * application, this is okay, as there is always only one user of
     * the buffer.  Not all applications can make this assumption.
     */
    encStatus.data.buf     = decStatus.data.buf     = versionBuf;
    encStatus.data.bufSize = decStatus.data.bufSize = MAXVERSIONSIZE;

    /* if the codecs support it, dump their versions */
    status = IMGDEC1_control(dec, XDM_GETVERSION, &decDynParams, &decStatus);
    GT_1trace(curMask, GT_1CLASS, "Decoder version:  %s\n",
        (status == IMGDEC1_EOK ? ((char *)decStatus.data.buf) : "[unknown]"));

    status = IMGENC1_control(enc, XDM_GETVERSION, &encDynParams, &encStatus);
    GT_1trace(curMask, GT_1CLASS, "Encoder version:  %s\n",
        (status == IMGENC1_EOK ? ((char *)encStatus.data.buf) : "[unknown]"));

    /*
     * This app expects the encoder to accept 1 buf in and get 1 buf out,
     * and the buf sizes of the in and out buffer must be able to handle
     * NSAMPLES bytes of data.
     */
    status = IMGENC1_control(enc, XDM_GETBUFINFO, &encDynParams, &encStatus);
    if (status != IMGENC1_EOK) {
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

    status = IMGDEC1_control(dec, XDM_GETBUFINFO, &decDynParams, &decStatus);
    if (status != IMGDEC1_EOK) {
        /* failure, report error and exit */
        GT_1trace(curMask, GT_7CLASS, "decode control status = 0x%x\n", status);
        return;
    }

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
    for (n = 0; fread(inBuf, IFRAMESIZE, 1, in) == 1; n++) {

        if (appPause) {
            printf("About to start frame %d. Press Enter to continue...\n", n);
            appPause = ('c' == getchar() ? 0 : 1);
        }

        /* Deal with cache issues, if necessary */
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

        GT_1trace(curMask, GT_1CLASS, "App-> Processing frame %d...\n", n);

        /* encode the frame */
        status = IMGENC1_process(enc, &inBufDesc, &encodedBufDesc, &encInArgs,
            &encOutArgs);

        GT_2trace(curMask, GT_2CLASS,
            "App-> Encoder frame %d process returned - 0x%x)\n",
            n, status);

#ifdef CACHE_ENABLED
        /* Writeback this outBuf from the previous call.  Also, as encodedBuf
         * is an inBuf to the next process call, we must invalidate it also, to
         * clean buffer lines.
         */
        Memory_cacheWbInv(encodedBuf, EFRAMESIZE);

        /* Per DMA Rule 7, our output buffer cache lines must be cleaned */
        Memory_cacheInv(outBuf, OFRAMESIZE);
#endif

        if (status != IMGENC1_EOK) {
            GT_3trace(curMask, GT_7CLASS,
                "App-> Encoder frame %d processing FAILED, status = 0x%x, "
                "extendedError = 0x%x\n", n, status, encOutArgs.extendedError);
            break;
        }

        /* decode the frame */
        decInArgs.numBytes = encOutArgs.bytesGenerated;
        status = IMGDEC1_process(dec, &encodedBufDesc, &outBufDesc, &decInArgs,
           &decOutArgs);

        GT_2trace(curMask, GT_2CLASS,
            "App-> Decoder frame %d process returned - 0x%x)\n",
            n, status);

        if (status != IMGDEC1_EOK) {
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
        fwrite(outBuf, OFRAMESIZE, 1, out);

#ifdef USE_POWER_MANAGEMENT
        if (Global_usePowerManagement) {
            if (appPause) {
                printf("About to hibernate. Press Enter to continue...\n");
                appPause = ('c' == getchar() ? 0 : 1);
            }

            LPM_Status  lpmStat = LPM_SOK;
            GT_0trace(curMask, GT_2CLASS, "Turning DSP off\n");
            lpmStat = LPM_setPowerState(lpmHandle, LPM_HIBERNATE);
            if (lpmStat != LPM_SOK) {
                fprintf(stderr, "Error: LPM_setPowerState() failed\n");
                return;
            }

            if (appPause) {
                printf("DSP is off: Press Enter to continue...\n");
                appPause = ('c' == getchar() ? 0 : 1);
            }
            else {
                struct timeval tv;
                tv.tv_sec = 0;
                tv.tv_usec = 200000;  /* 200 msec */

                if (select(0, NULL, NULL, NULL, &tv) == -1) {
                    fprintf(stderr, "Error: select() failed\n");
                    return;
                }
            }

            GT_0trace(curMask, GT_1CLASS, "Turning DSP on\n");
            lpmStat = LPM_resume(lpmHandle);
            if (lpmStat != LPM_SOK) {
                fprintf(stderr, "Error: LPM_resume() failed\n");
                return;
            }

            if (appPause) {
                printf("DSP is on: Press Enter to continue...\n");
                appPause = ('c' == getchar() ? 0 : 1);
            }
        }
#endif
    }

    GT_1trace(curMask, GT_1CLASS, "%d frames encoded/decoded\n", n);
}
/*
 *  @(#) ti.sdo.ce.examples.apps.image1_copy; 1, 0, 0,260; 9-20-2010 16:39:48; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */

