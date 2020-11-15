/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_map_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:13:41 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 12:43:19 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int		fill_map_space(char *config_oneline, t_config *configs, t_index *idx)
{
	int nul;

	nul = 9;
	if (config_oneline[idx->file_j] == '\0')
	{
		while (idx->file_j < configs->map_row)
		{
			configs->map[idx->j][idx->i] = nul;
			idx->j++;
			idx->file_j++;
		}
		return (1);
	}
	else if (config_oneline[idx->file_j] == ' ')
	{
		configs->map[idx->j][idx->i] = 9;
		return (0);
	}
	return (0);
}

void	set_init_posdir(char dir, t_config *configs, t_index *idx)
{
	if (dir == 'E')
	{
		configs->dir_init[X] = 1.0;
		configs->dir_init[Y] = 0.0;
	}
	else if (dir == 'W')
	{
		configs->dir_init[X] = -1.0;
		configs->dir_init[Y] = 0.0;
	}
	else if (dir == 'N')
	{
		configs->dir_init[X] = 0.0;
		configs->dir_init[Y] = -1.0;
	}
	else if (dir == 'S')
	{
		configs->dir_init[X] = 0.0;
		configs->dir_init[Y] = 1.0;
	}
	configs->pos_init[X] = idx->j + 0.5;
	configs->pos_init[Y] = idx->i + 0.5;
}
