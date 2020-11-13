/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:56:57 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/13 21:14:13 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_loop_hook.h"

void	set_deltadist(struct s_data *data, t_raycasting *r)
{
	if (r->raydir_y == 0)
		r->deltadist_x = 0;
	else if (r->raydir_x == 0)
		r->deltadist_x = 1;
	else
		r->deltadist_x = fabs(1 / r->raydir_x);
	if (r->raydir_x == 0)
		r->deltadist_y = 0;
	else if (r->raydir_y == 0)
		r->deltadist_y = 1;
	else
		r->deltadist_y = fabs(1 / r->raydir_y);
}

void	set_sidedist(struct s_data *data, t_raycasting *r)
{
	double pos_x;
	double pos_y;

	pos_x = data->obj.pos[X];
	pos_y = data->obj.pos[Y];
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (pos_x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = ((r->map_x + 1) - pos_x) * r->deltadist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (pos_y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = ((r->map_y + 1) - pos_y) * r->deltadist_y;
	}
}

void	until_hit_wall(struct s_data *data, t_raycasting *r)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (data->map[(char)r->map_x][(char)r->map_y] == 1)
			r->hit = 1;
	}
	return ;
}

void	wallx_from_perpwalldist(struct s_data *data, t_raycasting *r)
{
	double	wall_x;

	if (r->side == 0)
		r->perpwalldist = ((r->map_x + (1 - r->step_x) / 2) - data->obj.pos[X])
							/ r->raydir_x;
	else
		r->perpwalldist = ((r->map_y + (1 - r->step_y) / 2) - data->obj.pos[Y])
							/ r->raydir_y;
	r->lineheight = (int)(data->win_height / r->perpwalldist);
	r->drawstart = (int)(data->win_height / 2 - r->lineheight / 2);
	r->drawend = (int)(data->win_height / 2 + r->lineheight / 2);
	if (r->drawstart < 0)
		r->drawstart = 0;
	if (r->drawend >= data->win_height)
		r->drawend = data->win_height - 1;
	if (r->side == 0)
		wall_x = data->obj.pos[Y] + r->perpwalldist * r->raydir_y;
	else
		wall_x = data->obj.pos[X] + r->perpwalldist * r->raydir_x;
	wall_x -= (int)wall_x;
	r->tex_x = (int)(wall_x * (double)TEXWIDTH);
	if (r->side == 0 && r->raydir_x < 0)
		r->tex_x = TEXWIDTH - r->tex_x - 1;
	if (r->side == 1 && r->raydir_y > 0)
		r->tex_x = TEXWIDTH - r->tex_x - 1;
}

void	textured_wall_paint(struct s_data *data, t_raycasting *r, int win_x)
{
	int color;
	int w;
	int h;

	w = data->win_width;
	h = data->win_height;
	r->tex_step = 1 * (double)TEXHEIGHT / r->lineheight;
	r->tex_pos = (r->drawstart - h / 2 + r->lineheight / 2) * r->tex_step;
	while (r->drawstart < r->drawend)
	{
		r->tex_y = (int)r->tex_pos & (TEXHEIGHT - 1);
		r->tex_pos += r->tex_step;
		if (r->side == 0 && r->raydir_x > 0)
			color = my_mlx_pixel_get(&data->imgdata[1], r->tex_x, r->tex_y);
		else if (r->side == 0 && r->raydir_x < 0)
			color = my_mlx_pixel_get(&(data->imgdata[2]), r->tex_x, r->tex_y);
		else if (r->side == 1 && r->raydir_y > 0)
			color = my_mlx_pixel_get(&(data->imgdata[3]), r->tex_x, r->tex_y);
		else if (r->side == 1 && r->raydir_y < 0)
			color = my_mlx_pixel_get(&(data->imgdata[4]), r->tex_x, r->tex_y);
		my_mlx_pixel_put(&(data->imgdata[0]), win_x, r->drawstart, color);
		r->drawstart++;
	}
	data->zbuffer[win_x] = r->perpwalldist;
	return ;
}
