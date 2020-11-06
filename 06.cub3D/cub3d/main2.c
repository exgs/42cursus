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
int		shut_down(t_data *data)
{
	free_map(data->map);
	exit(0);
}

char init_NSWE(t_data *data)
{
	char c;
	if (data == NULL)
		return 0;
	if (data->obj.ray.dir[X] == 1)
	{
		c = 'E';
		data->obj.ray.nswe = 'E';
	}
	else if (data->obj.ray.dir[X] == -1)
	{
		c = 'W';
		data->obj.ray.nswe = 'W';
	}
	else if (data->obj.ray.dir[Y] == 1)
	{
		c = 'S';
		data->obj.ray.nswe = 'S';
	}
	else if (data->obj.ray.dir[Y] == -1)
	{
		c = 'N';
		data->obj.ray.nswe = 'N';
	}
	return c;
}

char **map_xy_reverse(char **map, t_config* config)
{
	if (map == NULL || map[0] == NULL)
		return NULL;
	char **reverse_map;
	int i;
	int j;

	i = 0;
	j = 0;
	reverse_map = (char **)malloc(sizeof(char *) * (config->map_row + 1));
	while (i < config->map_row)
	{
		reverse_map[i] = (char *)malloc(sizeof(char) * config->map_column + 1);
		reverse_map[i][config->map_column] = '\0';
		i++;
	}
	reverse_map[i] = NULL;
	
	i = 0;
	while (i < config->map_row)
	{
		j = 0;
		while (j < config->map_column)
		{
			reverse_map[i][j] = map[j][i];
			j++;
		}
		i++;
	}
	return reverse_map;
}

int	main(void)
{
	t_config config;
	if (default_setting_config_data(&config) == 0)
	{
		printf("setting bad config\n");
		return (0);
	}
	config.file = get_datas_linebyline("./srcs/map/map4");
	extract_configs_from_line(config.file, &config);
	print_config_data(&config);
	get_free_all_linebyline(config.file);

	t_data data;
	data.win_width = WIDTH;
	data.win_height = HEIGHT;
	
	data.config = &config;
	data.obj.pos[X] = config.pos_init[X];
	data.obj.pos[Y] = config.pos_init[Y];
	data.obj.ray.dir[X] = config.dir_init[X];
	data.obj.ray.dir[Y] = config.dir_init[Y];
	init_NSWE(&data);

	data.obj.ray.plane[X] = (data.obj.ray.dir[X]*cos(M_PI/2) - sin(M_PI/2)*data.obj.ray.dir[Y]);
	data.obj.ray.plane[Y] = (data.obj.ray.dir[X]*sin(M_PI/2) + cos(M_PI/2)*data.obj.ray.dir[Y]);
	printf("init_pos[X,Y] = [%f, %f]\n", data.obj.pos[X],data.obj.pos[Y]);
	printf("init_dir[X,Y] = [%f, %f]\n", data.obj.ray.dir[X],data.obj.ray.dir[Y]);
	printf("init_plane[X,Y] = [%f, %f]\n", data.obj.ray.plane[X],data.obj.ray.plane[Y]);
	
	
	data.obj.map[X] = (int)data.obj.pos[X];
	data.obj.map[Y] = (int)data.obj.pos[Y]; 
	data.map = config.map;

	data.sprite_num = count_sprite(&data, &config);

	int img_idx = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "yunslee_cub3D");
	img_idx = input_newimage(&data, mlx_new_image(data.mlx, WIDTH, HEIGHT));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, config.east_texture, &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, config.west_texture, &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, config.south_texture, &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, config.north_texture, &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	//sprite
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, config.sprite_texture, &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));

	/*event코드가 겹치면 안되는 거 같다.*/
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_loop_hook(data.mlx, raycasting, &data);
	mlx_hook(data.win, 17, 0, shut_down, &data);

	mlx_loop(data.mlx);
	return (1);
}
