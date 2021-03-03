#include "microshell.h"

size_t ft_strlen(char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void *ft_calloc(size_t size)
{
	char *temp;
	temp = malloc(sizeof(char) * size);
	int i = 0;
	while (i < size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}
