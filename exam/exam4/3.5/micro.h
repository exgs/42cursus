#include <stdio.h>
#include <unistd.h> //open close fork pipe
#include <sys/wait.h> //wait함수
#include <stdlib.h> // malloc
#include <string.h> // strcmp

# define TRUE 1
# define FALSE 0

typedef enum
{
	STRING = 0,
	PIPE,
	SEMICOLON
}		t_type;

typedef struct
{
	char *data;
	t_type type;
	char end;
}		t_token;

typedef struct 
{
	char *path;
	char **argv;
	t_type type;
	pid_t pid;
}		t_program;

int g_programs_count;
t_program *g_programs;
int g_tokens_count;
t_token *g_tokens;

size_t ft_strlen(char *str);
void *ft_calloc(int cnt);
void ft_putstr(int fd, char *str);
void exit_fatal();
void free_all();
int ft_cd(char **argv);
