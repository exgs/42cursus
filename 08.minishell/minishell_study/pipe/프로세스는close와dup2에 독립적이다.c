#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define READ 0
#define WRITE 1
#define CHILD 0

int main(void)
{
	int fd[2];
	int dup_stdout;
	dup_stdout = dup(STDOUT_FILENO);
	pid_t pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	switch(pid = fork())
	{
		case -1:
			perror("fork");
			exit(1);
			break ;
		case 0: /* child */
			close(fd[WRITE]);
			if (fd[READ] != 0)
			{
				dup2(fd[READ], 0);
				close(fd[READ]);
			}
			printf("-----각 프로세스는 close나 dup2에 독립적이다.----\n");
			execlp("grep", "grep", "telnet", (char *)NULL);
			// exit(1);
			break ;
		default: /* parent */
			close(fd[READ]);
			if (fd[WRITE] != 1)
			{
				dup2(fd[WRITE], 1);
				close(fd[WRITE]);
			}
			/* exec 함수를 사용해 ps -ef 명령을 실행한다. ps -ef 명령은
			표준 출력으로 결과가 파이프로 출력된다. 이 출력결과를 자식 프로세스가
			읽어들인다.*/
			execlp("ps", "ps", "-ef", (char *)NULL);
			break ;
	}
	return (0);
}