#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd1, fd2;
	char buf[4];
	char message[32] = {"hi\n"};
	// 여기서 fd1이 성공적으로 생성 된다면, fd1으로 부터 복사된 fd2.
	fd1 = open("dup.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	if (fd1 < 0)
	{
		printf("file open error\n");
		exit(0);
	}
	fd2 = dup(fd1);
	printf("fd1 : %d fd2 : %d \n", fd1, fd2);
	read(fd1, buf, sizeof(buf));
	write(1, buf, sizeof(buf));
	read(fd2, buf, sizeof(buf));
	write(1, buf, sizeof(buf));
	printf("\nfd1 : %d fd2 : %d \n", fd1, fd2);
	close(fd1);
	close(fd2);
}
