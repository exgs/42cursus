/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:09:55 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 15:26:06 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int		extract_map_data(char **config_lines, t_config *configs, int *map_start)
{
	int		max_row;
	int		max_column;
	int		i;
	int		len;
	char	**map;

	if (get_mapsize(config_lines, configs, *map_start) == 0)
		return (0);
	max_row = configs->map_row;
	max_column = configs->map_column;
	i = 0;
	map = malloc(sizeof(char *) * (max_row + 1));
	while (i < max_row)
	{
		map[i] = malloc(sizeof(char *) * (max_column + 1));
		map[i][max_column] = 0;
		i++;
	}
	map[max_row] = NULL;
	configs->map = map;
	if (fill_map(config_lines, configs, *map_start) == 0)
		return (0);
	*map_start = *map_start + max_column;
	return (1);
}

int		get_mapsize(char **config_lines, t_config *configs, int map_start)
{
	int	max_row;
	int	max_column;
	int	i;
	int	len;

	max_row = 0;
	max_column = 0;
	i = map_start;
	while (config_lines[i] != NULL && config_lines[i][0] != '\0' &&
										config_lines[i][0] != '\n')
	{
		len = ft_strlen(config_lines[i]);
		if (max_row < len)
			max_row = len;
		max_column++;
		i++;
	}
	if (max_row < 3 || max_column < 3)
	{
		configs->map = NULL;
		return (0);
	}
	configs->map_row = max_row;
	configs->map_column = max_column;
	return (1);
}

int		fill_map(char **config_lines, t_config *configs, int map_start)
{
	t_index	idx;

	idx.nswd_cnt = 0;
	idx.file_i = map_start;
	idx.i = 0;
	idx.j = 0;
	while (config_lines[idx.file_i] != NULL &&
			config_lines[idx.file_i][0] != '\0' &&
				config_lines[idx.file_i][0] != '\n')
	{
		idx.j = 0;
		idx.file_j = 0;
		if (fill_map_read(config_lines[idx.file_i], configs, &idx) == 0)
		{
			ft_putstr_fd("Error : fill_map_read\n", 1);
			return (0);
		}
		idx.file_i++;
		idx.i++;
	}
	if (idx.nswd_cnt != 1)
		return (0);
	return (1);
}

int		fill_map_read(char *config_oneline, t_config *configs, t_index *idx)
{
	char *str;

	str = config_oneline;
	while (idx->j < configs->map_row)
	{
		if (fill_map_space(str, configs, idx) == 1)
			break ;
		else if (str[idx->file_j] >= '0' && str[idx->file_j] <= '9')
			configs->map[idx->j][idx->i] = str[idx->file_j] - 48;
		else if (str[idx->file_j] == 'N' || str[idx->file_j] == 'S' ||
					str[idx->file_j] == 'W' || str[idx->file_j] == 'E')
		{
			configs->map[idx->j][idx->i] = 0;
			set_init_posdir(str[idx->file_j], configs, idx);
			idx->nswd_cnt++;
		}
		else if (str[idx->file_j] != ' ')
			return (0);
		(idx->file_j) = (idx->file_j) + 1;
		(idx->j) = (idx->j) + 1;
	}
	return (1);
}
