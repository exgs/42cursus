#include "microshell.h"

# include <stdio.h>


char **g_envp = NULL;

size_t g_token_count = 0;
t_token *g_tokens = NULL;

size_t g_program_count = 1;
t_program *g_programs = NULL;

int terminate(char *msg, bool asErr)
{
	if (msg)
	{
		ft_putstr(STDERR_FILENO, msg);
		ft_putstr(STDERR_FILENO, "\n");
	}
	for (size_t i = 0; i < g_program_count; i++)
	{
		free(g_programs[i].args);
	}
	free(msg);
	free(g_tokens);
	free(g_programs);
	exit(asErr);
	return (0);
}

int terminate_errno(char *origin)
{
	ft_putstr(STDERR_FILENO, "microshell: ");
	if (origin)
	{
		ft_putstr(STDERR_FILENO, origin);
		ft_putstr(STDERR_FILENO, ": ");
	}
	ft_putstr(STDERR_FILENO, strerror(errno));
	ft_putstr(STDERR_FILENO, "\n");
	return (terminate(NULL, true));
}

int main(int argc, char **argv, char **envp)
{
	g_envp = envp;
	if (argc == 1)
		return (0);
	g_tokens = ft_calloc(sizeof(t_token) * (g_token_count = argc - 1));
	/* 토큰, string값, 그리고 마지막인지 판단하는 bool 을
		g_tokens 라는 동적할당된 token 배열에 넣어줌 */

	/* Arguments to tokens */
	for (int i = 1; i < argc; i++)
	{
		t_token *tok = &(g_tokens[i - 1]);
		char *curr = tok->data = argv[i];
		tok->end = (i == argc - 1);
		if (strcmp(";", curr) == 0)
			tok->type = TT_SEMICOLON; // 2
		else if (strcmp("|", curr) == 0)
			tok->type = TT_PIPE; // 1
		else
			tok->type = TT_STRING; // 0
		if (tok->type != TT_STRING)
			g_program_count++;
	}
	//g_programs 초기값을 1로 설정해두긴했음

	g_programs = ft_calloc(sizeof(t_program) * g_program_count); // 팡

	/* Tokens to 'program' struct */
	{
		size_t j = 0;
		for (size_t i = 0; i < g_program_count; i++)
		{
			t_program *pr = &(g_programs[i]);
			size_t start = j++; // start = 0
			t_token *tok = NULL;
			while (j < g_token_count)
			{
				tok = &(g_tokens[j++]); // j = 1 -> j = 2
				if (tok->type != TT_STRING)
				{
					pr->piped = (tok->type == TT_PIPE);
					pr->semicoloned = (tok->type == TT_SEMICOLON);
					break;
				}
			}
			size_t args_size = j - start - (tok != NULL && tok->type != TT_STRING);
			pr->args = ft_calloc(sizeof(char *) * (args_size + 1));
			
			for (size_t k = 0; k < args_size; k++)
			{
				pr->args[k] = g_tokens[start + k].data;
			}
			pr->path = pr->args[0];	
		}
	}
		/* Dump. */
	for (size_t i = 0; i < g_program_count; ++i)
	{
		t_program *pr = &(g_programs[i]);

		printf("\n\npath = %s\n", pr->path);
		printf("piped = %s\n", pr->piped ? "true" : "false");
		printf("semicoloned = %s\n", pr->semicoloned ? "true" : "false");
		for (size_t j = 0; pr->args[j]; ++j)
			printf("arg[%zu] = %s\n", j, pr->args[j]);
	}


}
