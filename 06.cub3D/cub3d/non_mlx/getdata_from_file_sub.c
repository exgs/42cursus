/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_from_file_sub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:58:51 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/14 02:12:16 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int		free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = 0;
		i++;
	}
	free(map);
	return (1);
}

int		default_setting_config_data(t_config *config_data)
{
	if (config_data == NULL)
		return (0);
	else
	{
		config_data->resolution[X] = 1000;
		config_data->resolution[Y] = 1000;
		ft_bzero(config_data->north_texture, 100);
		ft_bzero(config_data->south_texture, 100);
		ft_bzero(config_data->west_texture, 100);
		ft_bzero(config_data->east_texture, 100);
		ft_bzero(config_data->sprite_texture, 100);
		config_data->map = NULL;
		config_data->ceiling_color = 0;
		config_data->floor_color = 0xffffff;
		return (1);
	}
}
