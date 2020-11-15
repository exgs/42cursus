/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utility_sub_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:43:23 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 15:43:49 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utility.h"
#include <stdio.h>

static void	print_map_data(t_config *configs)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = configs->map;
	if (map != NULL)
	{
		while (i < configs->map_column)
		{
			j = 0;
			while (j < configs->map_row)
			{
				printf("%d ", map[j][i]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
	return ;
}

void		print_config_data(t_config *configs)
{
	printf("R %d %d\n", configs->resolution[X], configs->resolution[Y]);
	printf("NO %s\n", configs->north_texture);
	printf("SO %s\n", configs->south_texture);
	printf("WE %s\n", configs->west_texture);
	printf("EA %s\n", configs->east_texture);
	printf("S %s\n", configs->sprite_texture);
	printf("F %d\n", configs->floor_color);
	printf("C %d\n", configs->ceiling_color);
	printf("-----------map-----------\n");
	print_map_data(configs);
}
