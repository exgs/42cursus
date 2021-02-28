#include <unistd.h>
#include <stdlib.h>

void * ft_calloc(int i)
{
	char *temp;

	if (i <= 0)
		return (malloc(sizeof(char)));
	else
	{
		int j = 0;
		temp = malloc(sizeof(char) * i);
		while (j < i)
		{
			temp[j] = 0;
			j++;
		}
	}
	return (temp);
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

