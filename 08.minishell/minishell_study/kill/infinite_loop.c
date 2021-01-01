#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	while (1)
	{
		printf("back ground\n");
		printf("My PID : %d\n", getpid());
		printf("My Parent's PID : %d\n", getppid());
		
		printf("Group leader called by getpgrp() : %d\n", getpgrp());
		printf("Group leader called by getpgid() : %d\n", getpgid(0));
		sleep(2);
	}
}
