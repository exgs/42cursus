#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int pid;
	int status;
	pid_t pid_wait;

	pid = fork();
	// pid = 2;
	if (pid < 0)
	{
		perror("FORK ERROR :");
		exit(0);
	}
	if (pid == 0)
	{
		int i;
		for (i = 0; i < 5; i++) 
		{
			printf("Child : %d\n", i);
			sleep(1);
		}
		exit(3);
	}
	else
	{
		
		printf("I wait Child(%d)\n", pid);
		// sleep(2);
		pid_wait = wait(&status);
		printf("Child is exit (%d)\n", status >> 8);
		printf("Child is exit (%d)\n", WEXITSTATUS(status));
		printf("pid_wait: %d\n", pid_wait);
	}
}