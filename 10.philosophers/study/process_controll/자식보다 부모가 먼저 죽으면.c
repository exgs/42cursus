#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int n= 10;
	pid_t child_pid, wpid; int status = 0;
	for (int i=0; i < n; i++)
	{
		if ((child_pid = fork()) == 0)
		{
			sleep(2);
			printf("test %d\n", i);
			exit(0);
		}
	}
	exit(0);
	while ((wpid = waitpid(-1, &status, 0)) > 0); //이 방법으로 아버지는 모든 자식 프로세스를 기다립니다
	printf("parent\n");
	return (1);
}
