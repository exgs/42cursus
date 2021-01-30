#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

# define READ 0
# define WRITE 1


int main(int argc, char *argv[], char **envp)
{
	int pid;
	int fds[2];
	char *str[3] =
	{
		"grep",
		"a",
		NULL
	};
	pipe(fds);
	// write(fds[WRITE], "", 9);
	pid = fork();
	int temp;
	if (pid == 0)
	{
		// dup2(fds[READ], STDIN_FILENO);
		// temp = dup2(fds[WRITE], STDOUT_FILENO); // 1. STDOUT을 바꾸어도 문제가 발생함
		printf("%d\n",temp);
		// close(fds[READ]); 4. 얘는 필요없음
		close(fds[WRITE]); //3. 얘도 닫아줘야함
		// execve("/bin/ls", str, envp);
		execve("/usr/bin/grep", str, envp);

	}
	else
	{
		close(fds[WRITE]); // 2. 이 위치에 안 써주면 문제 발생함.
		wait(NULL);
	}
	printf("=============main=============\n");
	return (1);
}