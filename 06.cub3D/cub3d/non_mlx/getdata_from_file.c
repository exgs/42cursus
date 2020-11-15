/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:03:31 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 11:42:24 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int	extract_configs(char **config_lines, t_config *configs)
{
	int		i;
	char	*config_oneline;
	int		map_start;

	i = 0;
	if (error_specifier_double(config_lines, configs) == 0)
	{
		ft_putstr_fd("Error : error_specifier_double\n", 1);
		return (0);
	}
	if (extract_configs_while(config_lines, configs) == 0)
		return (0);
	if (configs->map == NULL)
		return (0);
	return (1);
}

int	extract_configs_while(char **config_lines, t_config *configs)
{
	int		i;
	char	*config_oneline;
	int		map_start;

	i = 0;
	while (config_lines[i] != NULL)
	{
		config_oneline = config_lines[i];
		if (extract_config1(config_oneline, configs) == 0)
			return (0);
		if (config_lines[i][0] == 'M' && config_lines[i][1] == '\0')
		{
			map_start = i + 1;
			if (extract_map_data(config_lines, configs, map_start) == 0)
				return (0);
			return (1);
		}
		i++;
	}
	return (1);
}

int	extract_config3(char *config_oneline, t_config *configs)
{
	if (ft_strncmp(config_oneline, "C ", 2) == 0)
	{
		if (extract_ceiling_color(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strncmp(config_oneline, "S ", 2) == 0)
	{
		if (extract_sprite_texture(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	else if (config_oneline[0] == 'M' && config_oneline[1] == '\0')
		return (1);
	else if (config_oneline[0] == '\0')
		return (1);
	return (0);
}

int	extract_config2(char *config_oneline, t_config *configs)
{
	if (ft_strncmp(config_oneline, "WE ", 3) == 0)
	{
		if (extract_west_texture(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strncmp(config_oneline, "EA ", 3) == 0)
	{
		if (extract_east_texture(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strncmp(config_oneline, "F ", 2) == 0)
	{
		if (extract_floor_color(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	if (extract_config3(config_oneline, configs) == 0)
		return (0);
	else
		return (1);
}

int	extract_config1(char *config_oneline, t_config *configs)
{
	if (ft_strncmp(config_oneline, "R ", 2) == 0)
	{
		if (extract_resolution(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strncmp(config_oneline, "NO ", 2) == 0)
	{
		if (extract_north_texture(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	else if (ft_strncmp(config_oneline, "SO ", 3) == 0)
	{
		if (extract_south_texture(config_oneline, configs) == 0)
			return (0);
		else
			return (1);
	}
	if (extract_config2(config_oneline, configs) == 0)
		return (0);
	else
		return (1);
}
