/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:11:23 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/14 01:15:59 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_default.h"

int	load_file_error(t_data *data, t_config *config)
{
	if (config_to_data(data, config) == 0)
	{
		ft_putstr_fd("Error : config_to_data!\n", 1);
		return (0);
	}
	if (map_validation(data) == 0)
	{
		ft_putstr_fd("Error : map_validation\n", 1);
		shut_down(data);
		return (0);
	}
	return (1);
}

int	xpm_error(t_data *data, t_config *config)
{
	if (xpm_extension_error(config) == 0)
	{
		ft_putstr_fd("Error : xpm_extension error\n", 1);
		return (0);
	}
	else if (getimg_xpm(data, config) == 0)
	{
		ft_putstr_fd("Error : getimg_xpm\n", 1);
		shut_down(data);
		return (0);
	}
	return (1);
}

int	argument_error(int argc, char *argv[], t_data *data)
{
	if (argc != 2 && argc != 3)
	{
		ft_putstr_fd("Error : argc != 2 && argc != 3\n", 1);
		shut_down(data);
		return (0);
	}
	else if (argc == 3)
	{
		if (ft_strncmp(argv[2], "--save", 6) == 0)
		{
			save_bmp(data);
			ft_putstr_fd("Save bmp\n", 1);
		}
		else
			ft_putstr_fd("Please type \"--save\"\n", 1);
		shut_down(data);
		return (0);
	}
	if (extension_error(argv[1], ".cub") == 0)
	{
		ft_putstr_fd("Error : cub_extension error\n", 1);
		return (0);
	}
	return (1);
}

int	extension_error(char *filename, char *extension_name)
{
	char	*filename_extension;
	int		i;

	i = 0;
	while (ft_strchr(filename, '.') != NULL)
	{
		filename_extension = ft_strchr(filename, '.');
		filename++;
	}
	if (ft_strncmp(extension_name, filename_extension, 4) != 0)
		return (0);
	return (1);
}

int	xpm_extension_error(struct s_config *config)
{
	char *str;

	str = config->east_texture;
	if (extension_error(str, ".xpm") == 0)
		return (0);
	str = config->north_texture;
	if (extension_error(str, ".xpm") == 0)
		return (0);
	str = config->south_texture;
	if (extension_error(str, ".xpm") == 0)
		return (0);
	str = config->west_texture;
	if (extension_error(str, ".xpm") == 0)
		return (0);
	str = config->sprite_texture;
	if (extension_error(str, ".xpm") == 0)
		return (0);
	return (1);
}
