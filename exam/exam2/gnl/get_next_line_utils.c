#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str) //str==NULL이여도, 빈문자열 반환
{
	char	*dup;
	int		len;
	int		i;
	
	i = 0;
	if (str == NULL)
	{
		dup = malloc(1);
		dup[0] = '\0';
		return (dup);
	}
	len = ft_strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void ft_memset(char *memory, int c, int size)
{
	int i;

	i = 0;
	if (memory == NULL)
		return;
	while (i < size)
	{
		memory[i] = c;
		i++;
	}
	return ;
}

char *ft_strchr(char *str, char c)
{
	int i;
	
	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	else
		return (NULL);
}

char *ft_strjoin(char *head, char *tail)
{
	char *join;
	int total_len;
	int head_len;
	int i;

	if (head == NULL && tail == NULL)
		return (NULL);
	else if (head == NULL)
		return (ft_strdup(tail));
	else if (tail == NULL)
		return (ft_strdup(head));
	i = 0;
	total_len = ft_strlen(head) + ft_strlen(tail);
	head_len = ft_strlen(head);
	join = malloc(sizeof(char) * (total_len + 1));
	while (i < total_len)
	{
		if (i < head_len)
			join[i] = head[i];
		else
			join[i] = tail[i - head_len];
		i++;
	}
	join[i] = '\0';
	return (join);
}