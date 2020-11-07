#include "cub_default.h"

void	my_mlx_pixel_put(t_image *imgdata, int x, int y, int color)
{
    char    *dst;

    dst = imgdata->addr + (y * imgdata->size_line + x * (imgdata->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
	return ;
}

unsigned int	my_mlx_pixel_get(t_image *imgdata, int x, int y)
{
    char			*dst;
	unsigned int	color;
    dst = imgdata->addr + (y * imgdata->size_line + x * (imgdata->bits_per_pixel / 8));
    color = *(unsigned int*)dst;
	return color;
}

int config_to_data(t_data* data, t_config* configs)
{
	default_setting_config_data(configs);
	configs->file = get_datas_linebyline("./srcs/map/map4");
	if (extract_configs(configs->file, configs)== 0)
	{
		ft_putstr_fd("Error : \".cub\" file format doens't fit!\n", 1);
		return (0);
	}
	print_config_data(configs);
	get_free_all_linebyline(configs->file);
	data->win_width = configs->resolution[X];
	data->win_height = configs->resolution[Y];
	data->config= configs;
	data->obj.pos[X] = configs->pos_init[X];
	data->obj.pos[Y] = configs->pos_init[Y];
	data->obj.ray.dir[X] = configs->dir_init[X];
	data->obj.ray.dir[Y] = configs->dir_init[Y];
	data->obj.ray.plane[X] = (data->obj.ray.dir[X]*cos(M_PI/2) -
								sin(M_PI/2)*data->obj.ray.dir[Y]);
	data->obj.ray.plane[Y] = (data->obj.ray.dir[X]*sin(M_PI/2) +
								cos(M_PI/2)*data->obj.ray.dir[Y]);
	data->map = configs->map;
	data->sprite_num = count_sprite(data, configs);
	return (1);
}

int input_newimage(t_data *data, void *new_img)
{
	static int last_img_index = -1;
	if (data == NULL || new_img == NULL)
		return (0);
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	last_img_index++;
	data->imgdata[last_img_index].img = new_img;
	data->imgdata[last_img_index].addr =  mlx_get_data_addr(data->imgdata[last_img_index].img,
						&bits_per_pixel, &size_line, &endian);
	data->imgdata[last_img_index].bits_per_pixel = bits_per_pixel;
	data->imgdata[last_img_index].size_line = size_line;
	data->imgdata[last_img_index].endian = endian;
	return (last_img_index);
}

int input_newimage2(t_data *data, void *new_img, int img_index)
{
	if (data == NULL || new_img == NULL)
		return (0);
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	data->imgdata[img_index].img = new_img;
	data->imgdata[img_index].addr =  mlx_get_data_addr(data->imgdata[img_index].img,
						&bits_per_pixel, &size_line, &endian);
	data->imgdata[img_index].bits_per_pixel = bits_per_pixel;
	data->imgdata[img_index].size_line = size_line;
	data->imgdata[img_index].endian = endian;
	return (1);
}
