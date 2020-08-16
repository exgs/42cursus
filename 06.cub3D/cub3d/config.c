#include "config.h"

int free_map(t_config *configs)
{
	char **map = configs->map;
	int i = 0;

	if (map == NULL)
		return (0);
	while (i < configs->map_column)
	{
		free(map[i]);
		i++;
	}
	// free(map[i]);
	free(map);
	configs->map = NULL;
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
		config_data->ceilling_color = 0;
		config_data->floor_color = 0;
		return (1);
	}
}

int extract_configs_from_line(char **config_lines, t_config *configs)
{
	int i = 0;
	int j = 0;
	int map_start;
	char *str;

	while (config_lines[i] != NULL)
	{
		j = 0;
		if (config_lines[i][j] == 'R')
		{
			str = config_lines[i];
			// printf("config_lines : %s\n",str);
			// flush_string(str);
			// printf("config_lines : %s\n",str);
			if (extract_resolution(str, configs) == 0)
			{
				printf("error\n");
			}
		}
		else if (config_lines[i][j] == 'N')
		{
			str = config_lines[i];
			if (extract_north_texture(str, configs) == 0)
			{
				printf("error\n");
			}
		}
		else if (config_lines[i][j] == 'S')
		{
			str = config_lines[i];
			if (config_lines[i][j+1] == 'O')
			{
				if (extract_south_texture(str, configs) == 0)
					printf("error\n");
			}
			else
			{
				if (extract_sprite_texture(str, configs) == 0)
					printf("error\n");
			}
		}
		else if (config_lines[i][j] == 'W')
		{
			str = config_lines[i];
			if (extract_west_texture(str, configs) == 0)
			{
				printf("error\n");
			}
		}
		else if (config_lines[i][j] == 'E')
		{
			str = config_lines[i];
			if (extract_east_texture(str, configs) == 0)
			{
				printf("error\n");
			}
		}
		else if (config_lines[i][j] == 'F')
		{
			str = config_lines[i];
			if (extract_floor_color(str, configs) == 0)
			{
				printf("error\n");
			}
		}
		else if (config_lines[i][j] == 'C')
		{
			str = config_lines[i];
			if (extract_ceiling_color(str, configs) == 0)
			{
				printf("error\n");
			}
		}
		else if (config_lines[i][j] == 'M')
		{
			map_start = i + 1;
			if (extract_map_data(config_lines, configs, map_start) == 0)
			{
				printf("error\n");
			}
			return (1);
		}
		i++;
	}
	return (0);
	
}

int extract_resolution(char *str, t_config *configs)
{
	int idx = 0;
	// printf("resolution %s\n",str);
	flush_string(str);
	configs->resolution[X] = ft_atoi_cub(str, &idx);
	configs->resolution[Y] = ft_atoi_cub(str + idx, &idx);
	// printf("flush string : %p\n", str);
	if (configs->resolution[X] == -1 || configs->resolution[Y] == -1)
	{
		configs->resolution[X] = -1;
		configs->resolution[Y] = -1;
		return (0);
	}
	else
		return (1);
}

int extract_north_texture(char *str, t_config *configs)
{
	ft_strlcpy(configs->north_texture, ft_strchr(str, ' ') + 1, 100);
	if (configs->north_texture == NULL)//처리해주어야함
		return (0);
	else
		return (1);
}

int extract_south_texture(char *str, t_config *configs)
{
	ft_strlcpy(configs->south_texture, ft_strchr(str, ' ') + 1, 100);
	if (configs->south_texture == NULL)
		return (0);
	else
		return (1);
}
int extract_west_texture(char *str, t_config *configs)
{
	ft_strlcpy(configs->west_texture, ft_strchr(str, ' ') + 1, 100);
	if (configs->west_texture == NULL)
		return (0);
	else
		return (1);
}

int extract_east_texture(char *str, t_config *configs)
{
	ft_strlcpy(configs->east_texture, ft_strchr(str, ' ') + 1, 100);
	if (configs->east_texture == NULL)
		return (0);
	else
		return (1);
}

int extract_sprite_texture(char *str, t_config *configs)
{
	ft_strlcpy(configs->sprite_texture, ft_strchr(str, ' ') + 1, 100);
	if (configs->sprite_texture == NULL)
		return (0);
	else
		return (1);
}
int extract_floor_color(char *str, t_config *configs)
{
	int red;
	int green;
	int blue;
	int idx = 0;
	int color_int = 0;
	flush_string(str);
	red = ft_atoi_cub(str, &idx);
	green = ft_atoi_cub(str + idx, &idx);
	blue = ft_atoi_cub(str + idx, &idx);
	// printf("%d %d %d\n", red, green, blue);
	if (red < 0 || green < 0 || blue < 0)
		return (0);
	color_int = (red << 16) + (green << 8) + blue;
	configs->floor_color = color_int;
	return (1);
}

int extract_ceiling_color(char *str, t_config *configs)
{
	int red;
	int green;
	int blue;
	int idx = 0;
	int color_int = 0;
	flush_string(str);
	red = ft_atoi_cub(str, &idx);
	// printf("%d\n", idx);
	green = ft_atoi_cub(str + idx, &idx);
	// printf("%d\n", idx);
	blue = ft_atoi_cub(str + idx, &idx);
	// printf("%d\n", idx);
	// printf("%d %d %d\n", red, green, blue);
	if (red < 0 || green < 0 || blue < 0)
		return (0);
	color_int = (red << 16) + (green << 8) + blue;
	configs->ceilling_color = color_int;
	return (1);
}

int extract_map_data(char **config_lines, t_config *configs, int map_start)
{
	int max_row;
	int column;
	int i;
	int len;
	char **map;

	max_row = 0;
	column = 0;
	i = map_start;
	// printf("%s\n", config_lines[i]);
	while (config_lines[i] != NULL && config_lines[i][0] != '\0' && config_lines[i][0] != '\n')
	{
		len = ft_strlen(config_lines[i]);
		if (max_row < len)
			max_row = len;
		column++;
		i++;
	}
	configs->map_row = max_row;
	configs->map_column = column;
	//예외처리
	if (max_row <= 0 || column <= 0)
	{
		configs->map = NULL;
		return (0);
	}
	else
	{
		map = malloc(sizeof(char *) * column + 1);
		for (size_t i = 0; i < column; i++)
		{
			map[i] = malloc(sizeof(char) * max_row + 1);
			map[i][max_row] = '\0';
		}
		map[column] = NULL;
		configs->map = map;
	}
	printf("가로 : %d 세로 : %d\n",max_row, column);
	fill_in_map(config_lines, configs ,map_start);
	return (1);
}

void fill_in_map(char **config_lines, t_config *configs, int map_start)
{
	int i = 0;
	int j = 0;
	int map_i;
	int blank = 9;
	int map_j;
	char *str;

	map_i = map_start;
	while (config_lines[map_i] != NULL && config_lines[map_i][0] != '\0' && config_lines[map_i][0] != '\n')
	{
		j = 0;
		map_j = 0;
		str = config_lines[map_i];
		while (j < configs->map_row)
		{
			if (str[j] == ' ')
			{
				configs->map[i][map_j] = blank;
			}
			else if (str[j] == '0')
			{
				configs->map[i][map_j] = 0;
			}
			else if (str[j] == '1')
			{
				configs->map[i][map_j] = 1;
			}
			else if (str[j] == '\t')
			{
				for (size_t z = 0; z < 4; z++)
				{
					configs->map[i][map_j] = blank;
					map_j++;
				}
				j++;
				continue ;
			}
			else
			{
				configs->map[i][map_j] = blank;
			}
			map_j++;
			j++;
		}
		map_i++;
		i++;
	}
	return ;
}

void flush_string(char *str)
{
	int i = 0;
	if (str == NULL)
	{
		printf("string is NULL(flush)\n");
		return ;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			str[i] = ' ';
		}
		i++;
	}
}

static int	atoi_while_cub(const char *str, int i, int sign, int *idx)
{
	unsigned long long int	sum;

	sum = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		sum *= 10;
		sum += str[i] - 48;
		i++;
	}
	*idx += i;
	return ((int)sum);
}

int			ft_atoi_cub(const char *str, int *idx)
{
	int i;
	int sign;
	int value;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	value = sign * atoi_while_cub(str, i, sign, idx);
	return (value);
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
	printf("C %d\n", configs->ceilling_color);
	printf("-----------map-----------\n");
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			j = 0;
			while (j < configs->map_row)
			{
				printf("%d ", map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
}
