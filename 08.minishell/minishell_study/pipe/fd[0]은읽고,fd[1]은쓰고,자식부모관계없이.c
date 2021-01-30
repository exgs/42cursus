#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
	
# define BUFSIZE 200
int main()
{
	int fd[2];
	int dup_stdout;
	int dup_stdin;
	int state, pid;
	char buffer[200];
	int temp;
	state = pipe(fd);
	pid = fork();
	dup_stdout = dup(STDOUT_FILENO);
	dup_stdin = dup(STDIN_FILENO);
	
	if (pid == 0) //자식 프로세스
	{
		printf("child start\n");
		// close(fd[0]);
		write(fd[1], "Good!", 6); // 2번
		// read(fd[1], buffer, BUFSIZE); // 값을 가져오지못함
		read(fd[0], buffer, 11); // 계속 stdin을 받는 상태가 됨
		printf("자식 프로세스 출력 : %s \n\n", buffer); // 3번
		exit(0);
	}
	else //부모 프로세스의 경우 
	{
		printf("parent start\n");
		temp = write(fd[1], "Really Good", 11); // 1번
		temp = dup2(fd[1], STDOUT_FILENO);
		temp = dup2(fd[0], STDIN_FILENO);
		wait(&temp);
		// sleep(3);
		write(fd[1], "more", 4);
		dup2(dup_stdout, STDOUT_FILENO);
		if (-1 == read(fd[0], buffer, 6)) // 4번
			printf("Read Error \n");
		printf("부모 프로세스 출력 : %s \n", buffer);
	}
	// write(fd[1], "out of fork()", 12); // 5번
	if (-1 == read(fd[0], buffer, BUFSIZE))
		printf("Read Error \n");
	printf("main 프로세스 출력 : %s \n", buffer);
}