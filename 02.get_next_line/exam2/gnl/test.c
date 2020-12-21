#include "get_next_line.h"

int get_next_line_initial_error(int fd, char **line)
{
	char buf[1];
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0 || line == NULL)
		return (1);
	return (0);
}

int change_newline_to_zero2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

int check_read_before(char **remain, char **line)
{
	char *remain_temp;
	if (change_newline_to_zero2(*remain) == 1)
	{
		remain_temp = *remain;
		*line = ft_strdup(*remain);
		*remain = ft_strdup(ft_strchr(*remain, 0) + 1);
		free(remain_temp);
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE];
	char *remain_temp;
	static char *remain;
	int ret;

	if (get_next_line_initial_error(fd, line) == 1)
		return (-1);
	if (remain != NULL && check_read_before(&remain, line) == 1)
	// remain이 NULL이면, check_read_before를 실행시키지않음, 실행시키면, newline to zero에서 segfault
		return (1);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		remain_temp = remain;
		remain = ft_strjoin(remain, buf);
		free(remain_temp);
		if (check_read_before(&remain, line) == 1)
			return (1);
		ft_memset(buf, 0, BUFFER_SIZE + 1);
	}
	*line = ft_strdup(remain);
	free(remain);
	return (0);
}