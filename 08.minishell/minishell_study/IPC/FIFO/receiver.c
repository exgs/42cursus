#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MSG_SIZE 80
int main()
{
	char msg[MSG_SIZE];
	int fd;
	int nread;
	if(mkfifo("./fifo",0666) == -1)
	{
		printf("fail to call fifo()\n");
		exit(1);
	}
	if ((fd = open("./fifo", O_RDWR)) < 0)
	{
		printf("fail to call fifo()\n");
		exit(1);
	}
	for(int i = 0; i < 3; i++)
	{
		if ((nread = read(fd, msg, MSG_SIZE)) < 0 )
		{
			printf("fail to call read()\n");
			exit(1);
		}
		printf("recv: %s\n", msg);
	}
	unlink("./fifo");
	return 0;
}
