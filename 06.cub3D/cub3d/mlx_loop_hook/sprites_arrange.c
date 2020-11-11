/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_arrange.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:39:10 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/08 19:53:33 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_loop_hook.h"

void	sort_order(struct s_pair *orders, int amount)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;

	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}

int		find_sprite(struct s_data *data, struct s_config *config)
{
	char	**map;
	int		i;
	int		count;

	i = 0;
	count = 0;
	map = data->map;
	if (data == NULL || map[i] == NULL)
		return (-1);
	while (data->map[i] != NULL)
	{
		count_sprite(i, data, config, &count);
		i++;
	}
	data->sprite_num = count;
	return (count);
}

void		count_sprite(int i, struct s_data *data, struct s_config *config, int *count)
{
	int		j;
	char	*str;

	j = 0;
	str = data->map[i];
	while (j < config->map_column)
	{
		if (str[j] > 1 && str[j] < 9)
		{
			data->spritedata[*count].x = i + 0.5;
			data->spritedata[*count].y = j + 0.5;
			data->spritedata[*count].texture = data->map[i][j] + 3;
			(*count)++;
		}
		j++;
	}
	return ;
}
