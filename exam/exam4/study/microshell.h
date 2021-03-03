#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

typedef enum
{
	STRING = 0,
	PIPE,
	SEMICOLON
}		t_type;

typedef struct
{
	char	*data;
	t_type	type;
	char	end;
}		t_token;

typedef struct
{
	char	*path;
	char	**argv;
	t_type	type; // 코드에 따라서 들어가는 값은 PIPE, SEMICOLON 그리고 default로 STRING가 있다.
	pid_t	pid;
}		t_program;


size_t ft_strlen(char *str);
void ft_putstr(int fd, char *str);
void *ft_calloc(size_t size);
