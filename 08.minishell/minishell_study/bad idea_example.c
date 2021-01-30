#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main()
{
	pid_t childpid;
	int fds[2];
	int dup2_value;
	int stat; int temp;
	int old_in = dup(STDIN_FILENO);
	int old_out = dup(STDOUT_FILENO);
	
	pipe(fds);
	if ((childpid = fork()) != 0)//parent
	{
		wait(&stat);
		dup2_value = dup2(fds[0], STDIN_FILENO);
		dup2_value = dup2(fds[1], STDOUT_FILENO);
		/* 위 코드를 주석처리를 하면 stdout으로 잘 출력되고, 해제하면 계속 입력받는 상태가 됨.*/
		// close(fds[0]);
		// close(fds[1]);
		close(old_in);
		close(old_out);
		// close(STDIN_FILENO);
		// close(STDOUT_FILENO);
		perror("ERROR : ");
		system("grep h -a");
		// system("grep in chmod.c");
		dup2_value = dup2(old_in, STDIN_FILENO);
		printf("%d\n", dup2_value);
		dup2_value = dup2(old_out, STDOUT_FILENO);
		printf("%d\n", dup2_value);
	}
	else if (childpid == 0)
	{
		close(fds[0]);
		write(fds[1], "hello how are you\nhi how are you\n", 100);
		close(fds[1]);
		exit(0);
		// return 0;
	}
	printf("====================\n");
	char buf[190];
	read(fds[0],buf,180);
	printf("%s\n",buf);
	return 0;
}

// minishell에서 pipe, dup2, grep에서 질문이 있습니다.