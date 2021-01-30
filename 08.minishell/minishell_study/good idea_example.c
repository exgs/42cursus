#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

# define READ 0
# define WRITE 1
# define PULL 0
# define PUSH 1

int main(int argc, char *argv[], char **envp)
{
	pid_t pid;
	int child[2];
	int parent[2];
	int dup_stdin;
	int dup_stdout;
	dup_stdout = dup(STDOUT_FILENO);
	dup_stdin = dup(STDIN_FILENO);
	pipe(child); pipe(parent);
	pid = fork();
	if (pid == 0)//child
	{
		close(parent[PUSH]);
		close(child[PULL]);
		dup2(parent[PULL], STDIN_FILENO);
		dup2(child[PUSH], STDOUT_FILENO);
		execlp("/bin/ls", "ls");
	}
	else//parent
	{
		wait(NULL);
		close(parent[PULL]);
		close(child[PUSH]);
		dup2(parent[PUSH], STDOUT_FILENO);
		dup2(child[PULL], STDIN_FILENO);
		
		char *argvp[] =
		{
			"grep",
			"te",
			NULL
		};
		// char buf[200];
		// read(child[PULL], buf, 200);
		// printf("%s\n", buf);
		int e;
  		char *bb[] = { NULL };
  		char *aa[] = { "/bin/ls", "-l", NULL };

  		// e = execve("/bin/ls", aa, bb);
		execve("/usr/bin/grep", argvp, envp);
		// execlp("grep", "grep", "te", (char *)NULL);
		
		dup2(dup_stdout, STDOUT_FILENO);
		dup2(dup_stdin, STDIN_FILENO);
	}
	printf("End of main\n");
}