#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <sys/wait.h>
# include <string.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdbool.h>


# define FD_IN 0 // STDIN_FILENO
# define FD_OUT 1 // STDOUT_FILENO
# define FD_ERR 2 // STDERR_FILENO

typedef enum
{
	TT_STRING = 0,
	TT_PIPE,
	TT_SEMICOLON
} t_ttype;

typedef struct
{
	t_ttype type;
	char *data;
	bool end;
} t_token;

typedef struct
{
	char *path;
	char **args;
	bool piped;
	bool semicoloned;
	pid_t pid;
} t_program;

// utiliy.c
void*	ft_calloc(int i);
int		ft_strlen(char *str);
void	ft_putstr(int fd, char *str);

#endif
