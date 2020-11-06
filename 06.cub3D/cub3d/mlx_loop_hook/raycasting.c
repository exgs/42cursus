#include "mlx_loop_hook.h"

void	raycasting(void *param)
{
	t_data			*data;
	t_raycasting	r;

	data = param;
	floor_ceiling_paint(data);
	walls_raycasting(data);
	sprites_raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->imgdata[0].img, 0, 0);
}


void	floor_paint(struct s_data *data)
{
	int i;
	int j;
	int color;

	i = 0;
	j = 0;
	color = data->config->floor_color;
	while (i < WIDTH)
	{
		j = HEIGHT / 2;
		while (j < HEIGHT)
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
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT / 2)
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
