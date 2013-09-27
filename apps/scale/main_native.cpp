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
 #include <stdio.h>
#include <xdc/std.h>
#include <ti/sdo/ce/CERuntime.h>
#include <ti/sdo/ce/trace/gt.h>

#include <opencv/highgui.h>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

//#include <QSplashScreen>
//#include <QApplication>
//#include <QLabel>
//#include <QVector>


/*extern "C" 
{
 unsigned char * smain(Int argc, String argv[]);
}*/

extern unsigned char * smain(Int argc, String argv[]);


/* trace info: module name, mask */
GT_Mask curMask = {0,0};

/*
 *  ======== main ========
 */
Int main(Int argc, String argv[])
{
    
    CERuntime_init();

    GT_create(&curMask, "ZZ");

    /* Enable all trace for this "ZZ" module */
    GT_set("ZZ=01234567");

    GT_0trace(curMask, GT_2CLASS, "main> Welcome to app's main().\n");

    



// those code is support Qt display , the RGB display is OK , but grayscale is not my I wish !! because the pixel is error I guess!! 
#if 0     
    /*
    QApplication app(argc,argv,true);
    QLabel label;
    QImage qimage;
    QSplashScreen *splash = new QSplashScreen;
    QVector<QRgb> grayColourTable;
    QRgb *colourtable = new QRgb[256];*/

    unsigned char *frame_buffer_video = (unsigned char*)malloc(300*320*240*3*sizeof(unsigned char));
    unsigned char *frame_buffer_3_channel_gray = (unsigned char*)malloc(320*240*3*sizeof(unsigned char));
    int count , i , j;
    
    //cat the video by the smain function  , the video include 300 frame
    frame_buffer_video  = smain(argc,argv);
  
     
    //show the video capture by using Qt  ,  the video include 300 frame
    
    for(count=0;count<300; count++ )
    {
     
        //  (R1,G1,B1)  ---->  (Gray1,Gray1,Gray1)
	/*for(i=0;i<320*240;i++)
	{    
          for(j=0;j<3;j++)
          {frame_buffer_3_channel[j+i*3] = frame_buffer_video[i + count*320*240];} 
	}*/
    

         //RGB888 to GrayScale 
         for (i=0;i<320*240;i++)
         { 
          for(j=0;j<3;j++)
          {
           (frame_buffer_3_channel_gray[j+i*3]) = ( *(frame_buffer_video + count*320*240*3+i)*0.299 + *(frame_buffer_video + count*320*240*3 +i +1)*0.587  + *(frame_buffer_video + count*320*240*3 +i +2)*0.114);
          }
         }
        qimage =QImage((uchar*)(frame_buffer_3_channel_gray),320,240,QImage::Format_RGB888);



        /*==========================greyscale channel but have a problem================*/
       
        /*for(i=0;i<256;i++)
	{    
          colourtable[i]=qRgb(i,i,i);
          grayColourTable.append(colourtable[i]);
	}*/
        //qimage =QImage((uchar*)(frame_buffer_video + count*320*240),320,240,QImage::Format_Indexed8);
        //qimage.setColorTable(grayColourTable);
	
    splash->setPixmap(QPixmap::fromImage(qimage));  
    splash->show();
    sleep(1);
    }
    
    //free(frame_buffer_video);
    //free(frame_buffer);

#endif
    


    GT_0trace(curMask, GT_2CLASS, "ending by this app.\n");

    
    //return 0 ;
    //return (smain(argc, argv));
    smain(argc, argv);
    return 0 ;
}   
/*
 *  @(#) ti.sdo.ce.examples.apps.scale; 1,0,0,260; 9-20-2010 16:39:55; /db/atree/library/trees/ce/ce-r09x/src/ xlibrary

 */

