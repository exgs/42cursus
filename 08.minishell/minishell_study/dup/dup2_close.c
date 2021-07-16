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
	fd1 = open("dup.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	if (fd1 < 0)
	{
		printf("file open error\n");
		exit(0);
	}
	dup2(fd1, fd2);
	printf("fd1 : %d fd2 : %d \n", fd1, fd2);

	close(fd2); // 위에서 fd2로 접근 못하는거지 fd1으로는 접근 가능함!
	int ret = read(fd1, buf, sizeof(buf));
	write(1, buf, sizeof(buf));
	printf("\nret %d\n", ret);
	perror("");

	// 위에서 fd2를 close 했기 때문에 못 가져옴
	int ret2 = read(fd2, buf, sizeof(buf));
	write(1, buf, sizeof(buf));
	printf("\nret %d\n", ret);
	perror("");
	
	//
	close(fd1);
	close(fd2);
}
