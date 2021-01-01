#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
	
# define BUFSIZE 200
int main()
{
	int fd[2];
	int state, pid;
	char buffer[200];
	int temp;
	state = pipe(fd);
	pid = fork();
	if (pid == 0) //자식 프로세스
	{
		printf("child start\n");
		write(fd[1], "Good!", 6);
		// sleep(1);
		// sleep을 주석처리하면, 바로 밑에 있는 read(fd[0], buffer, BUFSIZE); 에서 읽을 가능성이 있음.
		read(fd[1], buffer, BUFSIZE);
		printf("자식 프로세스 출력 : %s \n\n", buffer);
		read(fd[0], buffer, BUFSIZE);
		printf("자식 프로세스 출력 : %s \n\n", buffer);
	}
	else //부모 프로세스의 경우 
	{
		printf("parent start\n");
		wait(&temp);
		if (-1 == read(fd[0], buffer, BUFSIZE))
			printf("Read Error \n");
		printf("부모 프로세스 출력 : %s \n", buffer);
		write(fd[1], "Really Good", 12);
	}
}