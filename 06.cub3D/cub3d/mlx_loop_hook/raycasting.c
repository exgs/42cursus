/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:38:06 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/13 16:54:04 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_loop_hook.h"

int		raycasting(void *param)
{
	t_data			*data;
	t_raycasting	r;

	data = param;
	floor_ceiling_paint(data);
	walls_raycasting(data);
	sprites_raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->imgdata[0].img, 0, 0);
	return (1);
}

void	walls_raycasting(struct s_data *data)
{
	t_raycasting	r;
	int				x;
	int				w;

	w = data->win_width;
	x = 0;
	while (x < w)
	{
		r.map_x = (int)data->obj.pos[X];
		r.map_y = (int)data->obj.pos[Y];
		r.camerax = 2 * x / (double)w - 1;
		r.raydir_x = data->obj.ray.dir[X] + data->obj.ray.plane[X] * r.camerax;
		r.raydir_y = data->obj.ray.dir[Y] + data->obj.ray.plane[Y] * r.camerax;
		set_deltadist(data, &r);
		set_sidedist(data, &r);
		until_hit_wall(data, &r);
		wallx_from_perpwalldist(data, &r);
		textured_wall_paint(data, &r, x);
		x++;
	}
}

void	floor_paint(struct s_data *data)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = data->config->floor_color;
	while (i < data->win_width)
	{
		j = data->win_height / 2;
		while (j < data->win_height)
		{
			my_mlx_pixel_put(&data->imgdata[0], i, j, color);
			j++;
		}
		i++;
	}
}

void	ceiling_paint(struct s_data *data)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = data->config->ceiling_color;
	while (i < data->win_width)
	{
		j = 0;
		while (j < data->win_height / 2)
		{
			my_mlx_pixel_put(&data->imgdata[0], i, j, color);
			j++;
		}
		i++;
	}
}

void	floor_ceiling_paint(struct s_data *data)
{
	floor_paint(data);
	ceiling_paint(data);
}
