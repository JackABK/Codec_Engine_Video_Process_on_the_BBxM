void errno_exit(const char* s);

int xioctl(int fd, int request, void* argp);

int frameRead(void);  

void mainLoop(void); 

void captureStop(void); 

void captureStart(void);

void deviceUninit(void);

void readInit(unsigned int buffer_size);

void mmapInit(void); 

void userptrInit(unsigned int buffer_size); 

void deviceInit(void); 

void deviceClose(void);

void deviceOpen(void);

void my_usage(FILE* fp, int argc, char** argv);

void YUV422toRGB888(int width, int height, unsigned char *src, unsigned char *dst);

void imageProcess(const void* p);
