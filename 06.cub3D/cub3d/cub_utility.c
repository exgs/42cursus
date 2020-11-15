/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:15:00 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 12:49:47 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utility.h"

void			my_mlx_pixel_put(t_image *imgdata, int x, int y, int color)
{
	char	*dst;

	dst = imgdata->addr
		+ (y * imgdata->size_line + x * (imgdata->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

unsigned int	my_mlx_pixel_get(t_image *imgdata, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = imgdata->addr
		+ (y * imgdata->size_line + x * (imgdata->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
}

int				config_to_data(t_data *data, t_config *configs)
{
	default_setting_config_data(configs);
	if (NULL == (configs->file = get_datas_linebyline(data->filename)))
		return (0);
	if (extract_configs(configs->file, configs) == 0)
	{
		ft_putstr_fd("Error : \".cub\" file format doens't fit!\n", 1);
		return (0);
	}
	get_free_all_linebyline(configs->file);
	data->win_width = configs->resolution[X];
	data->win_height = configs->resolution[Y];
	data->config = configs;
	data->obj.pos[X] = configs->pos_init[X];
	data->obj.pos[Y] = configs->pos_init[Y];
	data->obj.ray.dir[X] = configs->dir_init[X];
	data->obj.ray.dir[Y] = configs->dir_init[Y];
	data->obj.ray.plane[X] = (data->obj.ray.dir[X] * cos(M_PI / 2) -
								sin(M_PI / 2) * data->obj.ray.dir[Y]);
	data->obj.ray.plane[Y] = (data->obj.ray.dir[X] * sin(M_PI / 2) +
								cos(M_PI / 2) * data->obj.ray.dir[Y]);
	data->map = configs->map;
	if (find_sprite(data, configs) == -1)
		return (0);
	return (1);
}

int				input_newimage(t_data *data, void *new_img, int img_index)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	if (data == NULL || new_img == NULL)
		return (0);
	data->imgdata[img_index].img = new_img;
	data->imgdata[img_index].addr =
		mlx_get_data_addr(data->imgdata[img_index].img,
							&bits_per_pixel, &size_line, &endian);
	data->imgdata[img_index].bits_per_pixel = bits_per_pixel;
	data->imgdata[img_index].size_line = size_line;
	data->imgdata[img_index].endian = endian;
	return (1);
}
