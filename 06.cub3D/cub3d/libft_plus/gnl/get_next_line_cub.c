/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_cub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:06:24 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/11 21:32:33 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_cub.h"

int		get_next_line_sub(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*oneline_string;
	static char	*remain_string[1000] = {0, };
	int			validation;

	if (exist_newline_in_remain_string(remain_string, fd, line) == 1)
		return (1);
	ft_memset2(buffer, 0, (BUFFER_SIZE + 1));
	while ((validation = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (read_until_newline(buffer, fd, &oneline_string, remain_string) == 1)
		{
			*line = oneline_string;
			return (1);
		}
		ft_memset2(buffer, 0, BUFFER_SIZE);
	}
	if (validation == -1)
		return (-1);
	*line = ft_strdup2(remain_string[fd]);
	free(remain_string[fd]);
	remain_string[fd] = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int return_value;

	if (BUFFER_SIZE <= 0 || line == NULL)
	{
		return (-1);
	}
	if (1 == (return_value = get_next_line_sub(fd, line)))
		return (1);
	else if (return_value == 0)
		return (0);
	else if (return_value == -1)
		return (-1);
	return (-1);
}

int		exist_newline_in_remain_string(char **remain_string,
										int fd, char **line)
{
	char *remain_string_shadow;
	char *oneline_string;
	char *temp;

	if (fd < 0)
	{
		*line = ft_strdup2("");
		return (0);
	}
	else if (remain_string[fd] == NULL)
		return (0);
	remain_string_shadow = remain_string[fd];
	if (change_newline_to_zero(remain_string[fd]))
	{
		oneline_string = ft_strdup2(remain_string[fd]);
		*line = oneline_string;
		temp = ft_strdup2(ft_strchr2(remain_string[fd], 0) + 1);
		free(remain_string[fd]);
		remain_string[fd] = temp;
		return (1);
	}
	return (0);
}

int		change_newline_to_zero(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
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
