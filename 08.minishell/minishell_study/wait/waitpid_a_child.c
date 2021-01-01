#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	// 부모 프로세스 시작
	if (child_pid > 0)
	{
		int ret;
		printf("부모 PID : %ld, Childpid : %d\n", (long)getpid(), child_pid);
		// sleep(3);
		ret = waitpid(child_pid, &status, 0);
		
		printf("부모 종료 %d return : %d  status : %d\n", ret, WIFEXITED(status), WEXITSTATUS(status));
		exit(0);
	}
	else if (child_pid == 0) // 자식 프로세스
	{
		printf("자식 PID : %ld, Childpid : %d\n", (long)getpid(), child_pid);
		for(int i = 0; i<3; i++)
		{
			sleep(1);
			printf("%d\n", i);
		}
		printf("자식 종료\n");
		exit(0);
	}
	else
	{
		perror("fork Fail!\n");
		return (-1);
	}
	return (0);
}