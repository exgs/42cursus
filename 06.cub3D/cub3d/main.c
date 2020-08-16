#include "cub_default.h"

int input_newimage(t_data *data, void *new_img)
{
	static int last_img_index = -1;
	if (data == NULL || new_img == NULL)
		return (-1);
	last_img_index++;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	data->imgdata[last_img_index].img = new_img;
	data->imgdata[last_img_index].addr =  mlx_get_data_addr(data->imgdata[last_img_index].img,
						&bits_per_pixel, &size_line, &endian);
	data->imgdata[last_img_index].bits_per_pixel = bits_per_pixel;
	data->imgdata[last_img_index].size_line = size_line;
	data->imgdata[last_img_index].endian = endian;
	return (last_img_index);
}

void key_press(int keycode, void *param)
{
	t_data *data = param;
	if (keycode == 53)//esc
	{
		exit(0);
	}
	else if (keycode == 0)
	{
		// mlx_clear_window(data->mlx, data->win);
		printf("a\n");
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0x000000);
		data->obj.pos[X] -= 20;
		if (data->obj.pos[X] < 0 + 100 || data->obj.pos[Y] < 0 + 100 || data->obj.pos[X] > data->win_width - 100 || data->obj.pos[Y] > data->win_height - 100)
		{
			data->obj.pos[X] += 20;
			return ;
		}
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0xffffff);
		
	}
	else if (keycode == 0x0d)
	{	
		printf("w\n");
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0x000000);
		data->obj.pos[Y] -= 20;
		if (data->obj.pos[X] < 0 + 100 || data->obj.pos[Y] < 0 + 100 || data->obj.pos[X] > data->win_width - 100 || data->obj.pos[Y] > data->win_height - 100)
		{
			data->obj.pos[Y] += 20;
			return ;
		}
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0xffffff);
	}
	else if (keycode == 2)
	{
		printf("d\n");
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0x000000);
		data->obj.pos[X] += 20;
		if (data->obj.pos[X] < 0 + 100 || data->obj.pos[Y] < 0 + 100 || data->obj.pos[X] > data->win_width - 100 || data->obj.pos[Y] > data->win_height - 100)
		{
			data->obj.pos[X] -= 20;
			return ;
		}
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0xffffff);
	}
	else if (keycode == 1)
	{
		printf("s\n");
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0x000000);
		data->obj.pos[Y] += 20;
		if (data->obj.pos[X] < 0 + 100 || data->obj.pos[Y] < 0 + 100 || data->obj.pos[X] > data->win_width - 100 || data->obj.pos[Y] > data->win_height - 100)
		{
			data->obj.pos[Y] -= 20;
			return ;
		}
		mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0xffffff);
	}
}

int free_imgname(char **img_names)
{
	if (img_names == NULL)
		return (0); //-1
	for (size_t i = 0; img_names[i] != NULL; i++)
	{
		free(img_names[i]);
		img_names[i] = NULL;
	}
	return (1);
}

void loop_hook(void *param)
{
	// t_data *data = param;
	// mlx_pixel_put(data->mlx, data->win, data->obj.pos[X], data->obj.pos[Y], 0xffffff);
}

void map_pixel_put(t_data *data)
{

}
//움직일 때마다 background
// void background

int     main(void)
{
	t_config config;
	if (default_setting_config_data(&config) == 1)
		printf("setting good config\n");
	else
	{
		printf("setting bad config\n");
		return (0);
	}
	config.file = get_datas_linebyline("./srcs/map/map1");
	extract_configs_from_line(config.file, &config);
	print_config_data(&config);
	free_map(&config);
	get_free_all_linebyline(config.file);

	t_data  data;
	data.win_width = 1000;
	data.win_height = 1000;
	
	data.obj.pos[X] = data.win_width / 2;
	data.obj.pos[Y] = data.win_height / 2;

	int img_idx;
	char *img_names[10];
	img_names[9] = NULL;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Hello world!");

	img_idx = input_newimage(&data, mlx_new_image(data.mlx, 250, 250));
	printf("img_idx : %d\n", img_idx);
	img_names[img_idx] = ft_strdup("zero");

	for (size_t i = 0; i < 250; i++)
		my_mlx_pixel_put(&data.imgdata[0], i, 249, 0xffffff);
	for (size_t i = 0; i < 250; i++)
		my_mlx_pixel_put(&data.imgdata[0], 249, i, 0xffffff);
	//
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, "./srcs/item/42.xpm",
					&data.imgdata[1].width, &data.imgdata[1].height));
	printf("img_idx : %d\n", img_idx);
	img_names[img_idx] = ft_strdup("one");
	//
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, "./srcs/wall/벽.xpm",
					&data.imgdata[2].width, &data.imgdata[2].height));
	// printf("%d\n", data.imgdata[2].size_line);
	// printf("%d\n", data.imgdata[2].width);
	// printf("%d\n", data.imgdata[2].height);
	int interval_width= data.win_width / config.map_row;
	int interval_height= data.win_height / config.map_column;
	for (size_t i = 0; i < interval_width; i++)
	{
		mlx_put_image_to_window(data.mlx, data.win, data.imgdata[2].img, 0 + i * 100, 0);	
	}
	for (size_t i = 0; i < interval_height; i++)
	{
		mlx_put_image_to_window(data.mlx, data.win, data.imgdata[2].img, 0, 0 + i * 100);	
	}
	for (size_t i = 0; i < interval_width; i++)
	{
		mlx_put_image_to_window(data.mlx, data.win, data.imgdata[2].img, 0 + i * 100, data.win_height - 100);	
	}
	for (size_t i = 0; i < interval_height; i++)
	{
		mlx_put_image_to_window(data.mlx, data.win, data.imgdata[2].img, data.win_width - 100, 0 + i * 100);	
	}


	mlx_put_image_to_window(data.mlx, data.win, data.imgdata[0].img, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.imgdata[1].img, 0, 0);
	

	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_loop_hook(data.mlx, loop_hook ,&data);
	free_imgname(img_names);
	mlx_loop(data.mlx);
	return (1);
}
