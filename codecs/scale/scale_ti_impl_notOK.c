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
 *  ======== scale.c ========
 *  "Scale" algorithm.
 *
 *  This file contains an implementation of the IALG interface
 *  required by XDAS.
 */
#include <xdc/std.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "iscale.h"
#include "scale_ti.h"
#include "scale_ti_priv.h"

/* buffer definitions */
#define MININBUFS       1
#define MINOUTBUFS      1
#define MININBUFSIZE    1
#define MINOUTBUFSIZE   1






//void YUVToRGB24_1(XDAS_Int8*, XDAS_Int8*, XDAS_Int8 , XDAS_Int8 );







extern IALG_Fxns SCALE_TI_IALG;

#define IALGFXNS  \
    &SCALE_TI_IALG,     /* module ID */                         \
    NULL,               /* activate */                          \
    SCALE_TI_alloc,     /* alloc */                             \
    NULL,               /* control (NULL => no control ops) */  \
    NULL,               /* deactivate */                        \
    SCALE_TI_free,      /* free */                              \
    SCALE_TI_initObj,   /* init */                              \
    NULL,               /* moved */                             \
    NULL                /* numAlloc (NULL => IALG_MAXMEMRECS) */

/*
 *  ======== SCALE_TI_ISCALE ========
 *  This structure defines TI's implementation of the ISCALE interface
 *  for the SCALE_TI module.
 */
ISCALE_Fxns SCALE_TI_SCALE = {
    {IALGFXNS},
    SCALE_TI_process,
    SCALE_TI_control,
};

/*
 *  ======== SCALE_TI_IALG ========
 *  This structure defines TI's implementation of the IALG interface
 *  for the SCALECOPY_TI module.
 */
#ifdef _TI_

asm("_SCALE_TI_IALG .set _SCALE_TI_SCALE");

#else

/*
 *  We duplicate the structure here to allow this code to be compiled and
 *  run non-DSP platforms at the expense of unnecessary data space
 *  consumed by the definition below.
 */
IALG_Fxns SCALE_TI_IALG = {      /* module_vendor_interface */
    IALGFXNS
};

#endif

/*
 *  ======== SCALE_TI_alloc ========
 */
Int SCALE_TI_alloc(const IALG_Params *algParams,
    IALG_Fxns **pf, IALG_MemRec memTab[])
{
    /* Request memory for my object */
    memTab[0].size = sizeof(SCALE_TI_Obj);
    memTab[0].alignment = 0;
    memTab[0].space = IALG_EXTERNAL;
    memTab[0].attrs = IALG_PERSIST;

    return (1);
}

/*
 *  ======== SCALE_TI_free ========
 */
Int SCALE_TI_free(IALG_Handle handle, IALG_MemRec memTab[])
{
    SCALE_TI_alloc(NULL, NULL, memTab);
    return (1);
}

/*
 *  ======== SCALE_TI_initObj ========
 */
Int SCALE_TI_initObj(IALG_Handle handle,
    const IALG_MemRec memTab[], IALG_Handle p,
    const IALG_Params *algParams)
{
    SCALE_TI_Obj *inst = (SCALE_TI_Obj *)handle;
    ISCALE_Params *params = (ISCALE_Params *)algParams;

    if (params == NULL) {
        inst->scaleFactor = 2; /* default scale is 1 */
    }
    else {
        inst->scaleFactor = params->initialScaleFactor;
    }

    return (IALG_EOK);
}

/*
 *  ======== SCALE_TI_process ========
 */
XDAS_Int32 SCALE_TI_process(ISCALE_Handle handle, XDAS_Int8 *inBuf,
    XDAS_Int8 *outBuf, ISCALE_InArgs *inArgs, ISCALE_OutArgs *outArgs)
{
   
    SCALE_TI_Obj *inst = (SCALE_TI_Obj *)handle;
    //int i,j;
    //int h=600;
    //int w=800;
    XDAS_Int32 i,j;
    XDAS_Int32 frame_count;
    XDAS_Int32 h = 240;
    XDAS_Int32 w = 320;
    //XDAS_Int32 threshold = 140;
    //XDAS_Int32 MAX_value = 255;
    //XDAS_Int32 MIN_value = 0;
    //XDAS_Int8 inBuf_temp[600][800];
    //XDAS_Int8 outBuf_temp[600][800];
    

    //inBuf  = (XDAS_Int8 *) inBuf_temp; 
    //outBuf = (XDAS_Int8 *) outBuf_temp;

    
    /*for(j=0;j<h-1;j++){
        for(i=0;i<w-1;i++){
            inBuf_temp[j][i]  = *(j*h + inBuf + i);  //careful the overflow on the dsp core 
        }
    }*/

   /*for(j=0;j<h-1;j++){
        for(i=0;i<w-1;i++){
            inBuf_temp[j][i]  = 0;  //careful the overflow on the dsp core 
        }
    }
   */
   /************************Sobel Algorithm*************************************/
   /*for (j=0;j<=h-1;j++){
     for (i=0;i<=w-1;i++){

        if(j==0 || j==h-1)  //image boundaries 
        {
         outBuf_temp[j][i]=0;
        }
        else if(i==0 || i==w-1)
        {
         outBuf_temp[j][i]=0;
        }
       
        else 
        {
          //-------X + Y GRADIENT APPROXIMATION------
          outBuf_temp[j][i] = abs((inBuf_temp[j+1][i-1] + 2*inBuf_temp[j+1][i] + inBuf_temp[j+1][i+1]) 
                           -(inBuf_temp[j-1][i-1] + 2*inBuf_temp[j-1][i] + inBuf_temp[j-1][i+1]))
                           +abs((inBuf_temp[j-1][i-1] + 2*inBuf_temp[j][i-1] + inBuf_temp[j+1][i-1])
                           -(inBuf_temp[j-1][i+1] + 2*inBuf_temp[j][i+1] + inBuf_temp[j+1][i+1]));     

                        
        }

        if(outBuf_temp[j][i] > 255)
        {
          outBuf_temp[j][i]=255;
        }
        else if (outBuf_temp[j][i] < 0)
        {
          outBuf_temp[j][i]=0;
        }     
     }  
   }*/
/**********************end Sobel Algorithm*********************************/ 





    //YUVToRGB24_1((unsigned char *)inBuf,(unsigned char *)outBuf, 320, 240);


    /*for(j=0;j<h-1;j++){
        for(i=0;i<w-1;i++){
            outBuf_temp[j][i] = *(j*h + outBuf + i);
        }
    }
    */
    
    for (i = 0; i < inArgs->inBufValidBytes; i++) {
      outBuf[i] = inBuf[i] * inst->scaleFactor;
    }
    

    /*for(j=0;j<h-1;j++){
        for(i=0;i<w-1;i++){
            outBuf_temp[j][i] = 0;
        }
    }*/
    




    //sobel  algorithm  , this function is testing OK by YinChen
#if 0        
   for(frame_count=0 ; frame_count < 1; frame_count++){     
    for (i = 0; i < inArgs->inBufValidBytes; i++) {
       
           //image boundaries  [down,left,right,up]
           if (( i%w ==0)||( (i+1)%w==0)||(i<=w-1)||(i>=w*h-w))
           {
              outBuf[i] = 255;
           }
           else
           {
              outBuf[i] =  (  (-(   (inBuf[i+w-1])           +         (inBuf[i+w])*2              +        (inBuf[i+w+1]))

                                 +//     (inBuf[i-1])           +         (inBuf[i])                   +         (inBuf[i+1])              

                                 (   (inBuf[i-w-1])            +        (inBuf[i-w])*2               +       (inBuf[i-w+1]))    )



                                 +


                            ( (   -(inBuf[i+w-1])           +         /*(inBuf[i+w])>>1  */                (inBuf[i+w+1]))

                                 + (-((inBuf[i-1])*2)          +        /*(inBuf[i])       */                (inBuf[i+1])*2 )             

                                 + (   -(inBuf[i-w-1])           +         /*(inBuf[i-w])>>1  */                (inBuf[i-w+1]))  )   )  ;             



                if(outBuf[i] > 255)
                {
                  outBuf[i]=255;
                }
                else if (outBuf[i] < 0)
                {
                  outBuf[i]=0;
                }  

                } 
      }
    }
#endif

    /*for (i = 0; i < inArgs->inBufValidBytes; i++) {
        outBuf[i] = inBuf[i] << 1;
        //outBuf[i] = (XDAS_Int8)*(outBuf_temp[0] + i );
       //outBuf[i] = test_buf[i];
    }*/

    

    /*for (j=0;j<=h-1;j++){
        for (i=0;i<=w-1;i++){
            //outBuf[i+j*w] =  outBuf_temp[j][i];
            outBuf[i+j*w] =  255;
        }
    }*/

   /* for (i = 0; i < inArgs->inBufValidBytes; i++) {
      outBuf[i] = 255;
    }*/
    


    /* Fill outArgs , current i is 4096*/
    outArgs->outBufValidBytes = i ;
   
    
    return (ISCALE_EOK);
}

/*
 *  ======== SCALE_TI_control ========
 */
XDAS_Int32 SCALE_TI_control(ISCALE_Handle handle, ISCALE_Cmd id,
    ISCALE_DynamicParams *params)
{
    XDAS_Int32 retVal;
    SCALE_TI_Obj *inst = (SCALE_TI_Obj *)handle;

    switch (id) {
        case ISCALE_SETPARAMS:
            inst->scaleFactor = params->scaleFactor;

            retVal = ISCALE_EOK;

            break;

        default:
            /* unsupported cmd */
            retVal = ISCALE_EFAIL;

            break;
    }

    return (retVal);
}
/*
 *  @(#) ti.sdo.ce.examples.codecs.scale; 1, 0, 0,258; 9-20-2010 16:40:53; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */












/**********************************myself function**************************************/

  /*void yuv_to_rgb24(XDAS_Int8 y, XDAS_Int8 u, XDAS_Int8 v,  
        XDAS_Int8 *rgb) {  
  
    XDAS_Int8 r, g, b;  
  
  
    r = (1192 * (y - 16) + 1634 * (v - 128)) >> 10;  
    g = (1192 * (y - 16) - 833 * (v - 128) - 400 * (u - 128)) >> 10;  
    b = (1192 * (y - 16) + 2066 * (u - 128)) >> 10;  
  
    r = r > 255 ? 255 : r < 0 ? 0 : r;  
    g = g > 255 ? 255 : g < 0 ? 0 : g;  
    b = b > 255 ? 255 : b < 0 ? 0 : b;  
  
    *rgb = r;  
    rgb++;  
    *rgb = g;  
    rgb++;  
    *rgb = b;  
  
  
  
#if 0  
    rgb16 = (int) (((r >> 3) << 11) | ((g >> 2) << 5) | ((b >> 3) << 0));  
  
    *rgb = (unsigned char) (rgb16 & 0xFF);  
    rgb++;  
    *rgb = (unsigned char) ((rgb16 & 0xFF00) >> 8);  
#endif  
    
} */

/*void YUVToRGB24_1(XDAS_Int8 *buf, XDAS_Int8 *rgb, XDAS_Int8 width, XDAS_Int8 height) {  
  
  
    XDAS_Int8  y = 0;  
    XDAS_Int8 j = 0;  
    XDAS_Int8 blocks;  
  
    blocks = (width * height) * 2;  
  
  
    for (y = 0; y < blocks; y += 4) {  
        XDAS_Int8 Y1, Y2, U1, V1;  
  
        Y1 = buf[y + 0];  
        U1 = buf[y + 1];  
        Y2 = buf[y + 2];  
        V1 = buf[y + 3];  
  
  
        yuv_to_rgb24(Y1, U1, V1, &rgb[j]);  
        yuv_to_rgb24(Y2, U1, V1, &rgb[j + 3]);  
        j +=6;  
    }  
  
}*/


