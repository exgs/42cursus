	#include <stdio.h>
	#include <unistd.h>
	#include <stdlib.h>
	int	main(int argc, char *argv[], char **env)
	{
		long	test;
		int		status;
		pid_t	pid;
		int base = 0;
		// char *argvment[] =
		// {
		// 	"ls",
		// 	"!!!@",
		// 	NULL
		// };
		char *argvment[] =
		{
			"cd",
			"aaaa",
			NULL
		};
		if (!(pid = fork()))
		{
			printf("children %d\n", base);
			base++;
			execve("/usr/bin/cd", argvment, env);
			// execve("/bin/ls", argvment, env);
			// exit(2); // -> g_status에 영향을 줌
		}
		waitpid(pid, &status, 0);
		printf("parent : %d\n", base);
		printf("status : %d\n", status);
		return (0);
	}
