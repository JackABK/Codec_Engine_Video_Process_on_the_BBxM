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
#include <ti/sdo/ce/vidanalytics/vidanalytics.h>
#include <ti/sdo/ce/trace/gt.h>

#include <string.h>  /* for memset */

#include <stdio.h>
#include <stdlib.h>

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
#define OFRAMESIZE  (NSAMPLES * sizeof(Int8))  /* decoded frame (output) */
#define MAXVERSIONSIZE 128

static XDAS_Int8 *inBuf;
static XDAS_Int8 *outBuf;
static XDAS_Int8 *versionBuf;   /* acquire optional version from codecs */

static String progName     = "app";
static String analyzerName  = "vidanalytics_copy";
static String engineName   = "vidanalytics";

static String usage = "%s: input-file output-file\n";

static Void analyze(VIDANALYTICS_Handle analyzer, FILE *in, FILE *out);

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
    VIDANALYTICS_Handle analyzer = NULL;
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
    outBuf = (XDAS_Int8 *)Memory_alloc(OFRAMESIZE, &allocParams);
    versionBuf = (XDAS_Int8 *)Memory_alloc(MAXVERSIONSIZE, &allocParams);

    if ((inBuf == NULL) || (outBuf == NULL) || (versionBuf == NULL)) {
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

    /* allocate and initialize video analyzer on the engine */
    analyzer = VIDANALYTICS_create(ce, analyzerName, NULL);
    if (analyzer == NULL) {
        printf( "App-> ERROR: can't open codec %s\n", analyzerName);
        goto end;
    }

    /* use engine to encode, then decode the data */
    analyze(analyzer, in, out);

end:
    /* teardown the codec */
    if (analyzer) {
        VIDANALYTICS_delete(analyzer);
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
    if (versionBuf) {
        Memory_free(versionBuf, MAXVERSIONSIZE, &allocParams);
    }

    GT_0trace(curMask, GT_1CLASS, "app done.\n");
    return (0);
}

/*
 *  ======== analyze ========
 */
static Void analyze(VIDANALYTICS_Handle analyzer, FILE *in, FILE *out)
{
    Int                         n;
    Int32                       result;

    VIDANALYTICS_InArgs         inArgs;
    VIDANALYTICS_OutArgs        outArgs;
    VIDANALYTICS_DynamicParams  dynParams;
    VIDANALYTICS_Status         status;

    XDM1_BufDesc                inBufDesc;
    XDM1_BufDesc                outBufDesc;

    /* clear and initialize the buffer descriptors */
    inBufDesc.numBufs = outBufDesc.numBufs = 1;

    inBufDesc.descs[0].bufSize = outBufDesc.descs[0].bufSize = NSAMPLES;

    inBufDesc.descs[0].buf = inBuf;
    outBufDesc.descs[0].buf = outBuf;

    /* initialize all "sized" fields */
    inArgs.size    = sizeof(inArgs);
    outArgs.size   = sizeof(outArgs);
    dynParams.size = sizeof(dynParams);
    status.size    = sizeof(status);

    /* if the codecs support it, dump their versions */
    status.data.numBufs = 1;
    status.data.descs[0].buf = versionBuf;
    status.data.descs[0].bufSize = MAXVERSIONSIZE;

    result = VIDANALYTICS_control(analyzer, XDM_GETVERSION, &dynParams,
        &status);
    GT_1trace(curMask, GT_1CLASS, "Analyzer version:  %s\n",
        (result == VIDANALYTICS_EOK ?
            ((char *)status.data.descs[0].buf) : "[unknown]"));

    /*
     * This app expects the analyzer to accept 1 buf in and provide 1 buf out,
     * and the buf sizes of the in and out buffer must be able to handle
     * NSAMPLES bytes of data.
     */
    status.data.numBufs = 0;
    status.data.descs[0].buf = NULL;
    result = VIDANALYTICS_control(analyzer, XDM_GETBUFINFO, &dynParams,
        &status);
    if (result != VIDANALYTICS_EOK) {
        /* failure, report error and exit */
        GT_1trace(curMask, GT_7CLASS, "VIDANALYTICS control status = %ld\n",
            status);
        return;
    }

    /* Validate this analyzer will meet our buffer requirements */
    if ((inBufDesc.numBufs < status.bufInfo.minNumInBufs) ||
        (IFRAMESIZE < status.bufInfo.minInBufSize[0]) ||
        (outBufDesc.numBufs < status.bufInfo.minNumOutBufs) ||
        (OFRAMESIZE < status.bufInfo.minOutBufSize[0])) {

        /* failure, report error and exit */
        GT_0trace(curMask, GT_7CLASS,
            "Error:  analyzer codec feature conflict\n");
        return;
    }

    /*
     * Read complete frames from in, analyze, and write to out.
     */
    for (n = 0; fread(inBuf, IFRAMESIZE, 1, in) == 1; n++) {

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
        Memory_cacheInv(outBuf, OFRAMESIZE);
#endif

        GT_1trace(curMask, GT_1CLASS, "App-> Processing frame %d...\n", n);

        /*
         * Analyze the frame.
         */
        result = VIDANALYTICS_process(analyzer, &inBufDesc, &outBufDesc,
            &inArgs, &outArgs);

        GT_2trace(curMask, GT_2CLASS,
            "App-> Analyzer frame %d process returned - 0x%x)\n", n, result);

        if (result != VIDANALYTICS_EOK) {
            GT_3trace(curMask, GT_7CLASS,
                "App-> Analyzer frame %d processing FAILED, result = 0x%x, "
                "extendedError = 0x%x\n", n, result, outArgs.extendedError);
            break;
        }

#ifdef CACHE_ENABLED
        /*
         * Conditionally writeback the analyzed buf from the previous
         * call.
         */
        if (XDM_ISACCESSMODE_WRITE(outBufDesc.descs[0].accessMask)) {
            Memory_cacheWb(outBuf, OFRAMESIZE);
        }
#endif

        /* write to file */
        fwrite(outBufDesc.descs[0].buf, OFRAMESIZE, 1, out);
    }

    GT_1trace(curMask, GT_1CLASS, "%d frames analyzed\n", n);
}
/*
 *  @(#) ti.sdo.ce.examples.apps.vidanalytics; 1, 0, 0,209; 9-20-2010 16:40:20; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */

