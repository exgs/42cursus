
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
	int fd1, ret;
	int fd2;
	char message[32] = {"hi hello there\n"};
	char message_f[32] = {"lalalalal\n"};

	fd1 = open("hi_1.txt", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	
	if (fd1 < 0)
	{
		printf("file open error\n");
		exit(0);
	}
	printf("file open\n");
	// dup2(목적지, fd) 인듯?
	// STDOUT은 fd1과 같은 곳을 바라보아라. fd로 들어간 STDOUT이니 1번 fd가 fd1을 가르키고 있어함.
	// 고로 stdout이 fd1가 가르키는 파일을 수정하게 됨.
	ret = dup2(fd1, STDOUT_FILENO);
	printf("fd1 : %d, ret : 초기화 안됨\n", fd1);

	// fd1은 STDERR가 가르키는 곳을 바라보아라
	ret = dup2(STDERR_FILENO, fd1);
	printf("fd1 : %d, ret : %d\n", fd1, ret);
	write(fd1, message, strlen(message));
	printf("fd1 : %d, ret : %d\n", fd1, ret);
	printf("printf를 썼지만 파일에 기록됨\n");
	
	// STDIN_FILENO인 fd 0번은 fd1을 가리키는 곳(STDERR_FILENO)을 바라보아라
	ret = dup2(fd1, STDIN_FILENO);
	printf("fd1 : %d, ret : %d\n", fd1, ret);
	fd2 = 4;
	ret = dup2(fd1, fd2);
	printf("fd1 : %d, fd : %d, ret : %d\n", fd1, fd2, ret);

	close(fd1);
}