/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_cub2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:17:46 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/07 21:22:00 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_cub.h"

int		read_until_newline(char *buffer, int fd,
							char **oneline_string, char **remain_string)
{
	char *remain_string_shadow;

	remain_string_shadow = remain_string[fd];
	if (change_newline_to_zero(buffer))
	{
		*oneline_string = ft_strjoin2(remain_string[fd], buffer);
		remain_string[fd] = ft_strdup2(ft_strchr2(buffer, 0) + 1);
		free(remain_string_shadow);
		return (1);
	}
	remain_string[fd] = ft_strjoin2(remain_string[fd], buffer);
	free(remain_string_shadow);
	return (0);
}

char	**get_datas_linebyline(char *path)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;
	char	**lines;

	i = 0;
	lines = malloc(sizeof(char *) * 500);
	fd = open(path, O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		lines[i] = ft_strdup2(line);
		free(line);
		line = NULL;
		i++;
	}
	lines[i] = ft_strdup2(line);
	free(line);
	line = NULL;
	lines[i + 1] = NULL;
	close(fd);
	return (lines);
}

int		get_free_all_linebyline(char **lines)
{
	int i;

	i = 0;
	if (lines == NULL || *lines == NULL)
		return (-1);
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (1);
}
