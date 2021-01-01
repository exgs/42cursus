#include <stdio.h>
#include "../../libft/libft.h"
#include "../../gnl/get_next_line.h"

/*
ft_split을 linked_list로 구현?
*/
// 아무튼 각설하고..
/*
제목: 명령문 나누기
첫 번째) line을 띄어쓰기로 나눈다.

*/
// split으로 나눈 cmd들... 명령어 실행 이후에 free 해주어야함
void parse_cmd(char *line)
{
	char **cmd;
	int i; int j;

	cmd = ft_split(line, ' ');
	i = 0;
	while (cmd[i] != '\0')
	{
		ft_putstr_fd(cmd[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	j = 0;
	while (j <= i)
	{
		free(cmd[j]);
		j++;
	}
	free(cmd);
}

int main(int argc, char *argv[], char **envp)
{
	t_list *cmd;		cmd = NULL;
	char *line;

	ft_putstr_fd("bash-3.2$ ", 1);
	/* gnl이 정상적으로 받을 때 까지.. */
	while (1 == get_next_line(0, &line))
	{
		parse_cmd(line);
		ft_putstr_fd("bash-3.2$ ", 1);
		free(line);
	}
	return (0);
}
