//처음에 argument to token

#include "microshell.h"

char **g_env;
int g_cnt = 1;

int main(int argc, char *argv[], char **envp)
{
	g_env = envp;
	int i = 1;
	// 토큰에 넣으러 가자/
	t_token *tokens = malloc(sizeof(t_token) * (argc - 1));
	while (i < argc)
	{
		int j = i - 1;
		tokens[j].data = argv[i];
		if (strcmp(";", argv[i]) == 0)
		{
			tokens[j].type = TT_SEMICOLON;
			g_cnt++;
		}
		else if (strcmp("|", argv[i]) == 0)
		{
			tokens[j].type = TT_PIPE;
			g_cnt++;
		}
		else
			tokens[j].type = TT_STRING;
		if (argv[i + 1] == NULL)
			tokens[j].end = 1;
		else
			tokens[j].end = 0;
		i++;
	}

	// i = 0;
	// while (tokens[i].end == 0)
	// {
	// 	printf("%s\n", tokens[i].data);
	// 	i++;
	// }
	
	t_program *programs = malloc(sizeof(t_program) * g_cnt);
	// //프로그램안에 넣으러 가자.
	i = -1;
	int j = 0;
	while (j < g_cnt)
	{
		i++;
		programs[j].path = tokens[i].data;
		int start = i;
		while (tokens[i].type == TT_STRING)
		{
			if (tokens[i].end)
			{
				i++; //이 부분에서 문제가 있었다. i가 가리키는 곳은 TT_STRING이 아닌데여 하기 때문에 ++
				break;
			}
			i++;
		}
		size_t args_size = i - start;
		programs[j].args = malloc(sizeof(char *) * (args_size + 1));
		printf("%d\n", args_size);
		int z = 0;
		while (z < args_size)
		{
			programs[j].args[z] = tokens[start + z].data;
			z++;
		}
		programs[j].args[z] = NULL;

		if (tokens[i].type == TT_SEMICOLON)
		{
			programs[j].piped = 0;
			programs[j].semicoloned = 1;
		}
		if (tokens[i].type == TT_PIPE)
		{
			programs[j].piped = 1;
			programs[j].semicoloned = 0;
		}
		else if (tokens[i].end == 1)
		{
			programs[j].piped = 0;
			programs[j].semicoloned = 0; //이렇다고하자.
		}
		j++;
	}

	/* dump */
	for (size_t i = 0; i < g_cnt; ++i)
	{
		t_program *pr = &(programs[i]);

		printf("\n\npath = %s\n", pr->path);
		printf("piped = %s\n", pr->piped ? "true" : "false");
		printf("semicoloned = %s\n", pr->semicoloned ? "true" : "false");
		for (size_t j = 0; pr->args[j]; ++j)
			printf("arg[%zu] = %s\n", j, pr->args[j]);
	}
	
	return (1);
}
