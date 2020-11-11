/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:56:57 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/07 21:44:55 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_loop_hook.h"

void	set_deltadist(struct s_data *data, t_raycasting *r)
{
	if (r->rayDirY == 0)
		r->deltaDistX = 0;
	else if (r->rayDirX == 0)
		r->deltaDistX = 1;
	else
		r->deltaDistX = fabs(1 / r->rayDirX);
	if (r->rayDirX == 0)
		r->deltaDistY = 0;
	else if (r->rayDirY == 0)
		r->deltaDistY = 1;
	else
		r->deltaDistY = fabs(1 / r->rayDirY);
}

void	set_sidedist(struct s_data *data, t_raycasting *r)
{
	double pos_x;
	double pos_y;

	pos_x = data->obj.pos[X];
	pos_y = data->obj.pos[Y];
	if (r->rayDirX < 0)
	{
		r->stepX = -1;
		r->sideDistX = (pos_x - r->mapX) * r->deltaDistX;
	}
	else
	{
		r->stepX = 1;
		r->sideDistX = ((r->mapX + 1) - pos_x) * r->deltaDistX;
	}
	if (r->rayDirY < 0)
	{
		r->stepY = -1;
		r->sideDistY = (pos_y - r->mapY) * r->deltaDistY;
	}
	else
	{
		r->stepY = 1;
		r->sideDistY = ((r->mapY + 1) - pos_y) * r->deltaDistY;
	}
}

void	until_hit_wall(struct s_data *data, t_raycasting *r)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->sideDistX < r->sideDistY)
		{
			r->sideDistX += r->deltaDistX;
			r->mapX += r->stepX;
			r->side = 0;
		}
		else
		{
			r->sideDistY += r->deltaDistY;
			r->mapY += r->stepY;
			r->side = 1;
		}
		if (data->map[(char)r->mapX][(char)r->mapY] == 1)
			r->hit = 1;
	}
	return ;
}

void	wallx_from_perpwalldist(struct s_data *data, t_raycasting *r)
{
	double	wall_x;

	if (r->side == 0)
		r->perpWallDist = ((r->mapX + (1 - r->stepX) / 2) - data->obj.pos[X])
							/ r->rayDirX;
	else
		r->perpWallDist = ((r->mapY + (1 - r->stepY) / 2) - data->obj.pos[Y])
							/ r->rayDirY;
	r->lineHeight = (int)(data->win_height / r->perpWallDist);
	r->drawStart = (int)(data->win_height / 2 - r->lineHeight / 2);
	r->drawEnd = (int)(data->win_height / 2 + r->lineHeight / 2);
	if (r->drawStart < 0)
		r->drawStart = 0;
	if (r->drawEnd >= data->win_height)
		r->drawEnd = data->win_height - 1;
	if (r->side == 0)
		wall_x = data->obj.pos[Y] + r->perpWallDist * r->rayDirY;
	else
		wall_x = data->obj.pos[X] + r->perpWallDist * r->rayDirX;
	wall_x -= (int)wall_x;
	r->tex_x = (int)(wall_x * (double)TEXWIDTH);
	if (r->side == 0 && r->rayDirX < 0)
		r->tex_x = TEXWIDTH - r->tex_x - 1;
	if (r->side == 1 && r->rayDirY > 0)
		r->tex_x = TEXWIDTH - r->tex_x - 1;
}

void	textured_wall_paint(struct s_data *data, t_raycasting *r, int win_x)
{
	int color;
	int w;
	int h;

	w = data->win_width;
	h = data->win_height;
	r->tex_step = 0.9 * (double)TEXHEIGHT / r->lineHeight;
	r->tex_pos = (r->drawStart - h / 2 + r->lineHeight / 2) * r->tex_step;
	while (r->drawStart < r->drawEnd)
	{
		r->tex_y = (int)r->tex_pos & (TEXHEIGHT - 1);
		r->tex_pos += r->tex_step;
		if (r->side == 0 && r->rayDirX > 0)
			color = my_mlx_pixel_get(&data->imgdata[1], r->tex_x, r->tex_y);
		else if (r->side == 0 && r->rayDirX < 0)
			color = my_mlx_pixel_get(&(data->imgdata[2]), r->tex_x, r->tex_y);
		else if (r->side == 1 && r->rayDirY > 0)
			color = my_mlx_pixel_get(&(data->imgdata[3]), r->tex_x, r->tex_y);
		else if (r->side == 1 && r->rayDirY < 0)
			color = my_mlx_pixel_get(&(data->imgdata[4]), r->tex_x, r->tex_y);
		my_mlx_pixel_put(&(data->imgdata[0]), win_x, r->drawStart, color);
		r->drawStart++;
	}
	data->zbuffer[win_x] = r->perpWallDist;
	return ;
}
