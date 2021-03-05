#include "microshell.h"

int g_programs_count = 1;

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
			//마지막에 ";" 로 끝나는 경우, 세미콜론이 있더라도 뒤에 명령어가 없기 때문에 g_programs_count를 늘리면 안됨
			if (i != argc - 1)
				g_programs_count++;
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

	// debug 1
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
		int argv_size = j - start;
		program->argv = ft_calloc(sizeof(char *) * (argv_size + 1));
		for (size_t k = 0; k < argv_size; k++)
		{
			program->argv[k] = g_tokens[start + k].data;
		}
		program->argv[argv_size] = NULL;
		program->path = program->argv[0];
		j++; // 까먹지말고 기입하기
	}

	// debug 2
	// for (size_t i = 0; i < g_programs_count; i++)
	// {
	// 	t_program *program = &g_programs[i];
	// 	printf("path:%s\n", program->path);
	// 	for (size_t j = 0; program->argv[j]; j++)
	// 		printf("argv[%d]:%s\n", j, program->argv[j]);
	// 	printf("type:%d\n", program->type);
	// }
	
	/* Execute program */
	int fds[2] = {0, 0};
	int fd_in = 0;
	int status;

	for (size_t i = 0; i < g_programs_count; i++)
	{
		t_program *program = &g_programs[i];
		//segfault 안 나도록 함.  ex) a.out ";" ";" /bin/echo hello 이런 경우
		if (program->path == NULL)
			continue;
		if (strcmp("cd", program->path) == 0)
		{
			// ft_cd안에 있는 chdir함수에서 에러가 나더라도, 이후에 있는 명령어는 계속 실행되야함.
			ft_cd(program->argv);
			continue;
		}
		if (-1 == pipe(fds))
			exit_fatal();
		if (-1 == (program->pid = fork())) //에러처리
		{
			exit_fatal();
		}
		else if (program->pid == 0)
		{
			if (-1 == dup2(fd_in, 0))
				exit(2);
			close(fds[0]);
			if (program->type == PIPE) //파이프가 있을 때, STDOUT -> 파이프로 연결
			{
				if (-1 == dup2(fds[1], 1))
					exit(2);
			}
			if (-1 == execve(program->path, program->argv, envp)) // 에러처리
			{
				ft_putstr(2, "error: cannot execute ");
				ft_putstr(2, program->path);
				ft_putstr(2, "\n");
				exit(0);
			}
		}
		else
		{
			waitpid(program->pid, &status, 0);
			if (status / 256 == 2) // 자식 프로세스 내에서 syscall error가 났을 때, exit(2) 이기 때문에 status로 받아옴
				exit_fatal();
			if (fd_in != 0)
				close(fd_in);
			if (program->type == SEMICOLON || i == g_programs_count - 1)
			{
				fd_in = 0;
				close(fds[0]);
			}
			else
				fd_in = fds[0];
			close(fds[1]);
		}
	}
	free_all();
	// while(1); lsof -c a.out 사용하기위해서, 프로그램이 종료되지 않게 무한루프
	return (1);
}
