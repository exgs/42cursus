/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:20:10 by yunslee           #+#    #+#             */
/*   Updated: 2020/12/29 18:27:13 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int	counting_num(char *str)
{
	int	i;
	int	count;

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
			continue ;
		}
		i++;
	}
	return (count);
}

int	extract_floor_color(char *str, t_config *configs)
{
	int	red;
	int	green;
	int	blue;
	int	idx;
	int	color_int;

	idx = 0;
	color_int = 0;
	str = ft_strchr(str, ' ');
	if (counting_num(str) != 3 || flush_string(str) == 0)
		return (0);
	red = ft_atoi_cub(str, &idx);
	green = ft_atoi_cub(str + idx, &idx);
	blue = ft_atoi_cub(str + idx, &idx);
	if ((red < 0 || green < 0 || blue < 0) ||
		(red > 255 || green > 255 || blue > 255))
	{
		ft_putstr_fd("Error : F\n", 1);
		return (0);
	}
	color_int = (red << 16) + (green << 8) + blue;
	configs->floor_color = color_int;
	return (1);
}

int	extract_ceiling_color(char *str, t_config *configs)
{
	int	red;
	int	green;
	int	blue;
	int	idx;
	int	color_int;

	idx = 0;
	color_int = 0;
	str = ft_strchr(str, ' ');
	if (counting_num(str) != 3 || flush_string(str) == 0)
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

int	extract_resolution(char *str, t_config *configs)
{
	int idx;

	idx = 0;
	str = ft_strchr(str, ' ');
	if (counting_num(str) != 2 || flush_string(str) == 0)
		return (0);
	configs->resolution[X] = ft_atoi_cub(str, &idx);
	configs->resolution[Y] = ft_atoi_cub(str + idx, &idx);
	if (configs->resolution[X] < 0 || configs->resolution[Y] < 0)
	{
		configs->resolution[X] = -1;
		configs->resolution[Y] = -1;
		ft_putstr_fd("Error : extract_resolution\n", 1);
		return (0);
	}
	if (configs->resolution[X] > 2560)
		configs->resolution[X] = 2560;
	if (configs->resolution[Y] > 1440)
		configs->resolution[Y] = 1440;
	return (1);
}
