#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define MSG_SIZE 80

int main()
{
    char msg[MSG_SIZE];
    int fd;
    if((fd = open("./fifo", O_WRONLY)) < 0)
	{
        printf("fail to call open()\n");
        exit(1);
    }
    for(int i=0; i<3; i++)
	{
        printf("input a message : ");
        gets(msg);
        msg[MSG_SIZE - 1] = '\0';
        if(write(fd, msg, MSG_SIZE)==-1)
		{
            printf("fail to call write()\n");
            exit(1);
        }
        sleep(1);
    }
}