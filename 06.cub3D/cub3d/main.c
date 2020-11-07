#include "cub_default.h"

int getimg_xpm2(t_data *data, t_config *config, int *i)
{
	void *p;

	p = mlx_xpm_file_to_image(data->mlx, config->south_texture,
						&data->imgdata[*i].width, &data->imgdata[*i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p ,(*i)++);
	p = mlx_xpm_file_to_image(data->mlx, config->north_texture,
						&data->imgdata[*i].width, &data->imgdata[*i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, (*i)++);
	p = mlx_xpm_file_to_image(data->mlx, config->sprite_texture,
						&data->imgdata[*i].width, &data->imgdata[*i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, (*i));
	return (1);
}

int getimg_xpm(t_data *data, t_config *config)
{
	int i;
	void *p;

	i = 0;
	p = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, i++);
	p = mlx_xpm_file_to_image(data->mlx, config->east_texture,
						&data->imgdata[i].width, &data->imgdata[i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, i++);
	p = mlx_xpm_file_to_image(data->mlx, config->west_texture,
						&data->imgdata[i].width, &data->imgdata[i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, i++);
	if (getimg_xpm2(data, config, &i) == 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		printf("%s\n", argv[0]);
	if (argc == 2)
		printf("%s\n", argv[1]);
	t_config config;
	t_data data;

	if (config_to_data(&data, &config) == 0)
	{
		ft_putstr_fd("Error : config to data!\n", 1);
		return (0);
	}
	if (map_validation(&data) == 0)
	{
		ft_putstr_fd("Error : map is very odd!\n", 1);
		return (0);
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "yunslee_cub3D");
	if (getimg_xpm(&data, &config) == 0)
		return (0);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_loop_hook(data.mlx, raycasting, &data);
	mlx_hook(data.win, 17, 0, shut_down, &data);
	mlx_loop(data.mlx);
	return (1);
}

int map_validation(t_data *data)
{
	char **map;

	map = data->map;
	if (left_right_valid(map, data) == 0 || top_bottom_valid(map, data) == 0)
		return (0);
	if (valid_contaminant(map, data) == 0)
		return (0);
	return (1);
}

int left_right_valid(char **map, t_data *data)
{
	int j; 
	int i;

	i = data->config->map_row;
	j = 0;
	while(j < (data->config->map_column))
	{
		if (map[0][j] != 1 && map[0][j] != 9)
			return (0);
		j++;
	}
	j = 0;
	while (j < (data->config->map_column))
	{
		if (map[i - 1][j] != 1 && map[i - 1][j] != 9)
			return (0);
		j++;
	}
	return (1);
}

int top_bottom_valid(char **map, t_data *data)
{
	int i;
	int j;

	i = 0;
	j = data->config->map_column;
	while(i < (data->config->map_row))
	{
		if (map[i][0] != 1 && map[i][0] != 9)
			return (0);
		i++;
	}
	i = 0;
	while (i < (data->config->map_row))
	{
		if (map[i][j - 1] != 1 && map[i][j - 1] != 9)
			return (0);
		i++;
	}
	return (1);
}

int		valid_contaminant(char **map, t_data *data)
{
	int end_row;
	int end_column;
	int i;
	int j;

	i = 1;
	j = 1;
	end_row = data->config->map_row - 1;
	end_column = data->config->map_column - 1;
	while (i < end_row)
	{
		while (j < end_column)
		{
			if ((map[i][j] != 0 && map[i][j] != 9))
			{
				if (map[i - 1][j] == 9 || map[i + 1][j] == 9 || 
						map[i][j - 1] == 9 || map[i][j + 1] == 9)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
