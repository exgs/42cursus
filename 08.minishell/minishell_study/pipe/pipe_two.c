#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 30
#define READ 0
#define WRITE 1

int main(int argc, char *argv[])
{
	int fd1[2], fd2[2];
	char buffer[BUFSIZE];
	pid_t pid;

	if (pipe(fd1) == -1 || pipe(fd2) == -1)
	{
		puts("pipe() error");
		exit(1);
	}

	pid = fork();

	if (pid == -1)
	{
		puts("fork() error");
		exit(1);
	}
	else if (pid == 0)//자식 프로세스
	{
		write(fd1[WRITE], "연결성공!!\n", 25);
		read(fd2[READ], buffer, BUFSIZE);
		printf("Output of child process : %s \n\n", buffer);
	}
	else // 부모 프로세스
	{
		read(fd1[READ], buffer, BUFSIZE);
		printf("Output of parent process : %s\n\n", buffer);
		write(fd2[WRITE], "정말 좋아!!", 25);
		sleep(1); //부모 프로세스를 나중에 끝내주기 위해서
	}
	return (0);
}
