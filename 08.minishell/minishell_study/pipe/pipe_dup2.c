/*
	https://12bme.tistory.com/226
	쉘에서 많이 사용하는 명령의 형태인
	ps -ef | grep telnet 동작을 구현
*/

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
	pid_t pid;

	/* 파이프를 생성한다. */
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
		/*
		자식 프로세스가 해야할 일은 부모 프로세스가 파이프로
		출력되는 ps -ef 명령의 결과를 받아 grep telnet
		명령을 수행하는 것이다.
		따라서 파이프의 출력 부분이 필요없으므로 fd[1]을 닫는다.
		*/
		case 0: /* child */
			close(fd[WRITE]);
			if (fd[READ] != 0)
			{
				dup2(fd[READ], 0);
				close(fd[READ]);
			}
			/*
			자식 프로세스가 grep 명령을 exec 함수로 호출한다.
			이렇게 하면 grep 명령은 표준 입력을 통해 데이터를 읽어들이려 한다.
			이미 위쪽에 표준 입력으로 파이프의 입력 파일 기술자를 복사했으므로
			결과적으로 파이프를 통해 데이터를 읽어들인다.
			첫 번째 grep 은 프로그램 이름, 두 번째 grep 은 명령어 이름이다.
			NULL로 파라미터 입력을 끝낸다.
			*/
			execlp("grep", "grep", "telnet", (char *)NULL);
			exit(1);
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
			wait(NULL);
			break ;
	}
	return (0);
}