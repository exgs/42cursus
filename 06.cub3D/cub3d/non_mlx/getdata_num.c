#include "non_mlx.h"

int counting_num(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
			}
			count++;
		}
		i++;
	}
	return (count);
}


int extract_floor_color(char *str, t_config *configs)
{
	int red;
	int green;
	int blue;
	int idx;
	int color_int;

	idx = 0;
	color_int = 0;
	flush_string(str);
	if (counting_num(str) != 3)
		return (0);
	red = ft_atoi_cub(str, &idx);
	green = ft_atoi_cub(str + idx, &idx);
	blue = ft_atoi_cub(str + idx, &idx);
	if (red < 0 || green < 0 || blue < 0)
	{
		ft_putstr_fd("Error : F\n", 1);
		return (0);
	}
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
	if (counting_num(str) != 3)
		return (0);
	red = ft_atoi_cub(str, &idx);
	green = ft_atoi_cub(str + idx, &idx);
	blue = ft_atoi_cub(str + idx, &idx);
	if (red < 0 || green < 0 || blue < 0)
	{
		ft_putstr_fd("Error : C\n", 1);
		return (0);
	}
	color_int = (red << 16) + (green << 8) + blue;
	configs->ceiling_color = color_int;
	return (1);
}

int extract_resolution(char *str, t_config *configs)
{
	int idx;

	idx = 0;
	flush_string(str);
	if (counting_num(str) != 2)
		return (0);
	configs->resolution[X] = ft_atoi_cub(str, &idx);
	configs->resolution[Y] = ft_atoi_cub(str + idx, &idx);
	if (configs->resolution[X] < 0 || configs->resolution[Y] < 0)
	{
		configs->resolution[X] = -1;
		configs->resolution[Y] = -1;
		printf("Error : resolution\n");
		return (0);
	}
	else
		return (1);
}
