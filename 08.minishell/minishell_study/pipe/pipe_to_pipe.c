#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
# define READ 0
# define WRITE 1
int main(int argc, char *argv[], char **envp)
{
	int pid;
	int status;
	int dup_temp;
	int fds[2];
	int dfs[2];
	char *str[3] =
	{
		"grep",
		"p",
		NULL
	};
	pipe(fds);
	write(fds[WRITE], "pipe\nhello\n", 11);
	pipe(dfs);
	dup_temp = dup(dfs[1]);
	dup2(fds[1], dfs[1]);
	pid = fork();
	int temp;
	if (pid == 0)
	{
		dup2(fds[READ], STDIN_FILENO);
		temp = dup2(dfs[WRITE], STDOUT_FILENO); // 문제가 되는 코드
		printf("%d\n",temp);
		close(fds[READ]);
		close(dfs[WRITE]);
		close(fds[WRITE]);
		execve("/usr/bin/grep", str, envp);
		exit(0);
	}
	else
	{
		close(fds[WRITE]);
		wait(NULL);
	}
	dup2(dup_temp, dfs[1]);
	close(dfs[WRITE]);
	printf("=============main=============\n");
	char buf[199];
	read(fds[READ], buf , 199);
	printf("%s\n", buf);
	return (1);
}