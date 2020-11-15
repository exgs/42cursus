/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:51:49 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 13:43:23 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"
#include <stdio.h>

int	map_validation(t_data *data)
{
	char **map;

	map = data->map;
	if (map == NULL)
		return (0);
	if (is_allowed_character(map, data) == 0)
		return (0);
	if (left_right_valid(map, data) == 0 || top_bottom_valid(map, data) == 0)
		return (0);
	if (valid_contaminant(map, data) == 0)
		return (0);
	return (1);
}

int	left_right_valid(char **map, t_data *data)
{
	int j;
	int i;

	i = data->config->map_row;
	j = 0;
	while (j < (data->config->map_column))
	{
		if (map[0][j] != 1 && map[0][j] != 9)
			return (0);
		j++;
	}
	j = 0;
	while (j < (data->config->map_column))
	{
		if (map[i - 1][j] != 1 && map[i - 1][j] != 9)
			return (0);
		j++;
	}
	return (1);
}

int	top_bottom_valid(char **map, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = data->config->map_column;
	while (i < (data->config->map_row))
	{
		if (map[i][0] != 1 && map[i][0] != 9)
			return (0);
		i++;
	}
	i = 0;
	while (i < (data->config->map_row))
	{
		if (map[i][j - 1] != 1 && map[i][j - 1] != 9)
			return (0);
		i++;
	}
	return (1);
}

int	valid_contaminant(char **map, t_data *data)
{
	int end_row;
	int end_column;
	int i;
	int j;

	i = 1;
	end_row = data->config->map_row - 1;
	end_column = data->config->map_column - 1;
	while (i < end_row)
	{
		j = 1;
		while (j < end_column)
		{
			if ((map[i][j] != 1 && map[i][j] != 9))
			{
				if (map[i - 1][j - 1] == 9 || map[i - 1][j] == 9 ||
						map[i - 1][j + 1] == 9 ||
					map[i][j - 1] == 9 || map[i][j + 1] == 9 ||
						map[i + 1][j - 1] == 9 || map[i + 1][j] == 9 ||
							map[i + 1][j + 1] == 9)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_allowed_character(char **map, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->config->map_row)
	{
		j = 0;
		while (j < data->config->map_column)
		{
			if (map[i][j] != 0 && map[i][j] != 1 && map[i][j] != 2
					&& map[i][j] != 9)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
