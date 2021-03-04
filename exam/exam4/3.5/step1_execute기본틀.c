#include "micro.h"

g_programs_count = 1;

int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
		return (1);
	/* argv to token */
	g_tokens = ft_calloc(sizeof(t_token) * (g_tokens_count = argc - 1));
	for (int i = 1; i < argc; i++)
	{
		int j = i - 1;
		g_tokens[j].data = argv[i];
		if (strcmp(";", argv[i]) == 0)
		{
			g_tokens[j].type = SEMICOLON;
			/* 꼭 기억하기 */
			if (i != argc - 1)
				g_programs_count++;
			/************/
		}
		else if (strcmp("|", argv[i]) == 0)
		{
			g_tokens[j].type = PIPE;
			g_programs_count++;
		}
		else
		{
			g_tokens[j].type = STRING;
		}
		if (i == argc -1)
			g_tokens[j].end = 1;
		else
			g_tokens[j].end = 0;
	}

	// for (size_t i = 0; i < g_tokens_count; i++)
	// {
	// 	printf("%s\n", g_tokens[i].data);
	// 	printf("%d\n", g_tokens[i].type);
	// 	printf("%d\n", g_tokens[i].end);
	// }
	

	/* token to programs */
	g_programs = ft_calloc(sizeof(t_program) * g_programs_count);
	int j = 0;
	for (int i = 0; i < g_programs_count; i++)
	{
		t_token *token;
		t_program *program = &g_programs[i];
		int start = j;
		// printf("%d\n", start);
		/* 이 while문 구조 익히기 !!*/
		while (j < g_tokens_count)
		{
			token = &g_tokens[j];
			if (token->type != STRING)
			{
				program->type = token->type;
				break;
			}
			j++;
		}
		/**********************************/
		int argv_size = j - start;
		program->argv = ft_calloc(sizeof(char *) * (argv_size + 1));
		for (size_t k = 0; k < argv_size; k++)
		{
			program->argv[k] = g_tokens[start + k].data;
		}
		program->argv[argv_size] = NULL;
		program->path = program->argv[0];
		j++; // 까먹기 쉬운 듯
	}

	// for (size_t i = 0; i < g_programs_count; i++)
	// {
	// 	t_program *program = &g_programs[i];
	// 	printf("path:%s\n", program->path);
	// 	for (size_t j = 0; program->argv[j]; j++)
	// 		printf("argv[%d]:%s\n", j, program->argv[j]);
	// 	printf("type:%d\n", program->type);
	// }
	
	/* Execute */
	// 일딴은 노베이스에서 짜볼까???
	int fds[2] = {0, 0};
	int fd_in = 0;
	int ret;
	int status;

	for (size_t i = 0; i < g_programs_count; i++)
	{
		t_program *program = &g_programs[i];
		// if (strcmp("cd", program->path) == 0)
		// {
		// 	ft_cd(program->argv);
		// 	continue;
		// }
		pipe(fds); // cd에서는 파이프를 이용하지 않으니깐 밑에 있어도 괜찮아.
		if (-1 == (program->pid = fork()))
			return (0);
		else if (program->pid == 0)
		{
			dup2(fd_in, 0);
			close(fds[0]);
			if (program->type == PIPE)
				dup2(fds[1], 1);
			execve(program->path, program->argv, envp);
			//여기도 if문 걸어주고
		}
		else
		{
			waitpid(program->pid, &status, 0);
			fd_in = fds[0];
			close(fds[1]);
		}
	}
}
