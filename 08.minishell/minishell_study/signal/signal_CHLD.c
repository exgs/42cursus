/*https://twinjh.tistory.com/7*/
//https://stackoverflow.com/questions/14266485/understanding-sigchld-when-the-child-process-terminates
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int delay;
void child_handler()
{
	printf("Children die\n");
}

int main(int argc, char *argv[], char *envp[])
{
	int pid[4];
	scanf("%d", &delay);
	signal(SIGCHLD, child_handler);

	// pid = fork();
	// pid = fork();
	// pid = fork();
	// pid = fork();
	for (size_t i = 0; i < 4; i++)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			// char *argvs[] = {"ls","-a",NULL};
			// execve("/bin/ls", argvs, envp);
			// perror("Limit");
			exit(0);
		}
	}
		
	for (size_t i = 0; i < 4; i++)
	{
		printf("Child : time left %d\n", sleep(delay));
	}
	printf("End of main\n");
}
