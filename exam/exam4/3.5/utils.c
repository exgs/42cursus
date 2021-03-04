#include "micro.h"

size_t ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}

void *ft_calloc(int cnt)
{
	char *str;
	str = malloc(sizeof(char) * cnt);
	int i = 0;
	while (i < cnt)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

void ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void exit_fatal()
{
	ft_putstr(2, "error: fatal\n");
	free_all();
	exit(1);
}

void free_all()
{
	free(g_tokens);
	for (size_t i = 0; i < g_programs_count; i++)
		free(g_programs[i].argv);	
	free(g_programs);
	// int i = 0;
	// while (i)
	// {
	// 	close(i++);
	// }
}

int ft_cd(char **argv)
{
	int i = 0;
	while (argv[i])
		i++;
	if (i == 2)
	{
		ft_putstr(2, "error: cd: bad arguments\n");
		return (FALSE);
	}
	if (chdir(argv[1]) == -1)
	{
		ft_putstr(2, "error: cd: cannot change directory to ");
		ft_putstr(2, argv[1]);
		ft_putstr(2, "\n");
		return (FALSE);
	}
	return (TRUE);
}
