#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
    int N = 5;
 
    pid_t pid[N]; /* process id */
    int childStatus;
    int i;
 
    for (i = 0; i < N; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            printf("pid : %d , Now pid[%d] is die\n",pid[i],i);
            exit(100+i);
        }        
        // Create multiple child processes
    }
 
    for (i = 0; i < N; i++)
    {
		childStatus = 0xff;
        // pid_t terminatedChild = wait(&childStatus);
		pid_t terminatedChild = waitpid(-1,&childStatus,0);
 
        if (WIFEXITED(childStatus))
        {
            // The child process has termindated normall
			printf("Child %d has terminated with exit status %d", terminatedChild, WEXITSTATUS(childStatus));
			printf("(== childStatus: %d)\n", childStatus >> 8);
        }
        else
            printf("Child %d has terminated abnormally\n", terminatedChild);
    }
	
	// pid_t terminatedChild = waitpid(-1,&childStatus,0);
	printf("waitpid one time\n");
}
