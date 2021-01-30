#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
	int fd;
	int cls;
	int wrt;
	
	fd = open("./hello", O_RDWR | O_CREAT | O_APPEND, 0755);
	printf("%d\n",fd);
	wrt = write(fd, "hellO! :", 8);
	cls = close(fd);
	printf("================\n");
	fd = open("./hello",O_RDWR | O_APPEND, 0755);
	printf("%d\n",fd);	
	wrt = write(fd, "world!\n", 7);
	cls = close(fd);
	return (1);
}