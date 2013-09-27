#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <cvaux.h>
#include <QSplashScreen>
#include <QApplication>
#include <QLabel>

int Qt_Gui_by_ABK (int a,char *b[])
{
 CvCapture *capture ;
 IplImage *frame=0;
 capture = cvCreateCameraCapture(0);
 int n = 0;
 //resoulution
// cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH,1024);
 //cvSetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT,768);

 
 QApplication app(a,b,true);
 QLabel label ;
 QSplashScreen * splash = new QSplashScreen;
 
 while(1)
 {
 frame = cvQueryFrame(capture);
 printf("the camera resoulution is %dx%d\n",frame->width,frame->height);
 cvCvtColor(frame,frame,CV_BGR2RGB);
 QImage image =QImage((uchar*)frame->imageData,frame->width,frame->height,QImage::Format_RGB888);

 splash->setPixmap(QPixmap::fromImage(image));
 splash->show();
 //label.update();
 n++;
 }
 return app.exec();


}

