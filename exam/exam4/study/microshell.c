#include "microshell.h"

# define TRUE 1
# define FALSE 0

int g_tokens_count;
t_token *g_tokens = NULL;
int g_programs_count = 1;
t_program *g_programs = NULL;

char ** g_envp;
int main(int argc, char *argv[], char *envp[])
{
	if (argc == 1)
		return (1);
	g_envp = envp;
	/* argv -> tokens */
	g_tokens = ft_calloc(sizeof(t_token) * (g_tokens_count = argc - 1));
	for (size_t i = 1; i < argc; i++)
	{
		int j = i - 1;
		t_token *this = &g_tokens[j];
		this->data = argv[i];
		if (strcmp("|", argv[i]) == 0)
		{
			this->type = PIPE;
			g_programs_count++;
		}
		else if (strcmp(";", argv[i]) == 0)
		{
			this->type = SEMICOLON;
			// 내가 추가해준 부분. 이렇게되면, 맨 마지막에 ";" 오는 경우를 배제해도 됨
			if (i != argc - 1)
				g_programs_count++;
		}
		else
			this->type = STRING;
		if (i == argc - 1)
			this->end = TRUE;
		else
			this->end = FALSE;
	}
	
	// 무조껀 체크해줘야함
	// for (size_t i = 0; i < g_tokens_count; i++)
	// {
	// 	printf("%s\n", g_tokens[i].data);
	// 	printf("%d\n", g_tokens[i].type);
	// 	printf("%d\n", g_tokens[i].end);
	// }
	// printf("%d\n", g_programs_count);

	/*token -> program */
	g_programs = ft_calloc(sizeof(t_program) * (g_programs_count));
	int j = 0;
	for (size_t i = 0; i < g_programs_count; i++)
	{
		t_program *this_program = &g_programs[i];
		int start = j;
		// printf("%d\n", j);
		while (j < g_tokens_count) // 마지막에 ";" 가 온다면, 윗 코드와 더불어서 세그폴트나기 너무 좋음
		{
			t_token *token = &(g_tokens[j++]);
			// printf("%s\n", token->data);
			if (token->type != STRING)
			{
				this_program->type = token->type;
				break;
			}
		}
		int program_size = j - start; // ";"로 끝나는 경우도 g_programs_count가 늘어나지 않게 함. 그래서 뒤에 안 붙어도 될 것 같음
		this_program->argv = malloc(sizeof(char *) * (program_size + 1));
		for (size_t z = 0; z < program_size; z++)
		{
			this_program->argv[z] = g_tokens[start + z].data;
		}
		this_program->argv[program_size] = NULL;
		this_program->path = this_program->argv[0];
		// this_program->type = g_tokens[start + program_size] // 마지막엔 기호가 없는걸
		// 게다가 ";" 로 끝나는 경우는 어떻게 해결해야하지?
	}


	for (size_t i = 0; i < g_programs_count; i++)
	{
		t_program *this = &g_programs[i];
		printf("path:%s\n", this->path);
		for (size_t z = 0; this->argv[z]; z++)
		{
			printf("argv[%d]: %s\n", z, this->argv[z]);
		}
		printf("type:%d\n", this->type);
	}
	

	return (1);
}
