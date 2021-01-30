#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

extern char **ft_split(char *str, char c);

char *g_str;

typedef struct	s_data {
	char **cmd_splited;
	char *cmd_trimed;
	char ***cmd_redirect;
	char *symbol_array;
	char **envp;
}				t_data;

t_data *get_param()
{
	static t_data param;
	return (&param);
}

int main(int argc, char *argv[], char **envp)
{
	pid_t pid;
	get_param()->cmd_trimed = malloc(100);
	strlcpy(get_param()->cmd_trimed, "what is going on?\n", 100);
	get_param()->cmd_splited = ft_split(get_param()->cmd_trimed, ' ');
	g_str = malloc(100);
	char *str[5] =
	{
		"a",
		"-l",
		NULL
	};
	pid = fork();
	if (pid == 0)
	{
		int pid2;
		pid2 = fork();
		if (pid2 == 0)
			execve("/bin/ls", str, envp);
		else
		{
			waitpid(pid2, NULL, 0);
		}
		printf("---child---\n");
		exit(0);
	}
	else
	{
		waitpid(pid, NULL, 0);
		printf("---parent---\n");
	}
	printf("---main---\n");
	get_param()->cmd_trimed = NULL;
	get_param()->cmd_splited = NULL;
	free(g_str);
	g_str = NULL;
	// system("leaks a.out");
}