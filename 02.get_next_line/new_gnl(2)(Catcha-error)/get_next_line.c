/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:06:24 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/06 01:50:31 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*connect_string = "\0";
	static int	validation = -2;
	int			temp;

	if (line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (validation == -2)
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
	if (if_newline_remain_in_buffer(buffer, line) == 1)
		return (1);
	connect_string = ft_strdup(buffer);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while ((validation = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if ((temp = read_until_newline(&connect_string, buffer, line)) == 1)
			return (1);
	}
	if (validation == -1)
	{
		free(connect_string);
		return (-1);
	}
	*line = connect_string;
	return (0);
}

int		if_newline_remain_in_buffer(char *buffer, char **line)
{
	if (change_newline_to_zero(buffer))
	{
		*line = ft_strdup(buffer);
		ft_strlcpy_buff(buffer, ft_strchr(buffer, 0) + 1, BUFFER_SIZE + 1);
		return (1);
	}
	return (0);
}

int		read_until_newline(char **connect_string, char *buffer, char **line)
{
	char *connect_string_shadow;

	connect_string_shadow = *connect_string;
	if (change_newline_to_zero(buffer))
	{
		*connect_string = ft_strjoin(connect_string_shadow, buffer);
		ft_strlcpy_buff(buffer, ft_strchr(buffer, 0) + 1, BUFFER_SIZE + 1);
		*line = *connect_string;
		free(connect_string_shadow);
		return (1);
	}
	*connect_string = ft_strjoin(connect_string_shadow, buffer);
	free(connect_string_shadow);
	ft_memset(buffer, 0, BUFFER_SIZE);
	return (0);
}

int		change_newline_to_zero(char *buffer)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = dest;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
