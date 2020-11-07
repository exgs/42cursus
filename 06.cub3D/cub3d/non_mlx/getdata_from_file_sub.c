#include "non_mlx.h"

int free_map(char **map)
{
	int i;

	i = 0;
	if (map == NULL)
		return (0);
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = 0;
		i++;
	}
	free(map);
	return (1);
}

int default_setting_config_data(t_config *config_data)
{
	if (config_data == NULL)
		return (0);
	else
	{
		config_data->resolution[X] = -1;
		config_data->resolution[Y] = -1;
		ft_bzero(config_data->north_texture, 100);
		ft_bzero(config_data->south_texture, 100);
		ft_bzero(config_data->west_texture, 100);
		ft_bzero(config_data->east_texture, 100);
		ft_bzero(config_data->sprite_texture, 100);
		config_data->map = NULL;
		config_data->ceiling_color = 0;
		config_data->floor_color = 0;
		return (1);
	}
}


void print_config_data(t_config *configs)
{
	int i = 0;
	int j = 0;
	char **map = configs->map;
	printf("R %d %d\n", configs->resolution[X], configs->resolution[Y]);
	printf("NO %s\n", configs->north_texture);
	printf("SO %s\n", configs->south_texture);
	printf("WE %s\n", configs->west_texture);
	printf("EA %s\n", configs->east_texture);
	printf("\n");
	printf("S %s\n", configs->sprite_texture);
	printf("F %d\n", configs->floor_color);
	printf("C %d\n", configs->ceiling_color);
	printf("-----------map-----------\n");
	if (map != NULL)
	{
		while (i < configs->map_column)
		{
			j = 0;
			while (j < configs->map_row)
			{
				printf("%d ", map[j][i]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
}
