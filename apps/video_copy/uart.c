#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pthread.h>
#define _POSIX_SOURCE 1
#define YES  (1)
#define NO (0)

void uart_init(int fd)
{
        //Setting the uart device parameter
        printf("Setting the uart device parameter\n");
        struct termios serialAttr;
        memset(&serialAttr, 0, sizeof serialAttr); 
        serialAttr.c_iflag = IGNPAR;
        serialAttr.c_cflag = B9600 | HUPCL | CS8 | CREAD | CLOCAL;
        serialAttr.c_cc[VMIN] = 1;

        if (tcsetattr(fd, TCSANOW, &serialAttr)) {
                printf("tcsetattr fail !\n");
				uart_close(fd);
                exit(1);

        }
        printf("uart initial is OK\n");
}


void uart_close(int fd)
{
	close(fd);
}
