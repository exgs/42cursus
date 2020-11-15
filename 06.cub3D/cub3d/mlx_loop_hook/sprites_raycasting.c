/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:43:37 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 12:41:16 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_loop_hook.h"

void	sprites_raycasting(struct s_data *data)
{
	t_spritecasting	r;
	int				i;
	double			spr_x;
	double			spr_y;

	i = 0;
	while (i < data->sprite_num)
	{
		spr_x = data->spritedata[i].x;
		spr_y = data->spritedata[i].y;
		data->sprite_order[i] = i;
		data->sprite_distance[i] =
			(data->obj.pos[X] - spr_x) * (data->obj.pos[X] - spr_x)
				+ (data->obj.pos[Y] - spr_y) * (data->obj.pos[Y] - spr_y);
		i++;
	}
	sort_sprites(data->sprite_order, data->sprite_distance, data->sprite_num);
	i = 0;
	while (i < data->sprite_num)
	{
		camera_matrix_setting(data, &r, i);
		sprites_paint(data, &r, i);
		i++;
	}
}

void	camera_matrix_setting(struct s_data *data, t_spritecasting *r, int i)
{
	int w;
	int h;

	w = data->win_width;
	h = data->win_height;
	r->sprite_x = data->spritedata[data->sprite_order[i]].x - data->obj.pos[X];
	r->sprite_y = data->spritedata[data->sprite_order[i]].y - data->obj.pos[Y];
	r->invdet = (double)1.0 / (data->obj.ray.plane[X] * data->obj.ray.dir[Y] -
					data->obj.ray.dir[X] * data->obj.ray.plane[Y]);
	r->transform_x = r->invdet * (data->obj.ray.dir[Y] * r->sprite_x -
									data->obj.ray.dir[X] * r->sprite_y);
	r->transform_y = r->invdet * (-data->obj.ray.plane[Y] * r->sprite_x +
									data->obj.ray.plane[X] * r->sprite_y);
	r->spritescreen_x = (int)((w / 2) * (1 + r->transform_x / r->transform_y));
	r->spriteheight = (int)fabs((h / (r->transform_y)));
	r->drawstart_y = -r->spriteheight / 2 + h / 2;
	limit_draw_startend(data, r);
}

void	limit_draw_startend(struct s_data *data, t_spritecasting *r)
{
	int w;
	int h;

	w = data->win_width;
	h = data->win_height;
	if (r->drawstart_y < 0)
		r->drawstart_y = 0;
	r->drawend_y = r->spriteheight / 2 + h / 2;
	if (r->drawend_y >= h)
		r->drawend_y = h - 1;
	r->spritewidth = (int)fabs((h / (r->transform_y)));
	r->drawstart_x = -r->spritewidth / 2 + r->spritescreen_x;
	if (r->drawstart_x < 0)
		r->drawstart_x = 0;
	r->drawend_x = r->spritewidth / 2 + r->spritescreen_x;
	if (r->drawend_x >= w)
		r->drawend_x = w - 1;
	return ;
}

void	sprites_paint(struct s_data *data, t_spritecasting *r, int num)
{
	int stripe;
	int sprite_serial_num;

	sprite_serial_num = data->spritedata[data->sprite_order[num]].texture;
	stripe = r->drawstart_x;
	while (stripe < r->drawend_x)
	{
		if (stripe > 0 && stripe < data->win_width && r->transform_y > 0 &&
								r->transform_y < data->zbuffer[stripe])
		{
			sprites_paint2(data, r, stripe, sprite_serial_num);
		}
		stripe++;
	}
}

void	sprites_paint2(struct s_data *data, t_spritecasting *r,
						int stripe, int sprite_serial_num)
{
	int y;

	r->tex_x = (int)(256 * (stripe - (-r->spritewidth / 2 + r->spritescreen_x))
					* TEXWIDTH / r->spritewidth / 256);
	y = r->drawstart_y;
	while (y < r->drawend_y)
	{
		r->d = (y * 256) - (data->win_height * 128) + (r->spriteheight * 128);
		r->tex_y = ((r->d * TEXHEIGHT) / r->spriteheight) / 256;
		r->color = my_mlx_pixel_get(&(data->imgdata[sprite_serial_num]),
										r->tex_x, r->tex_y);
		if ((r->color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&(data->imgdata[0]), stripe, y, r->color);
		y++;
	}
}
