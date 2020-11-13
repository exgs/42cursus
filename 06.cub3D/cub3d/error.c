/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:11:23 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/14 06:33:57 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_default.h"

int	error_load_file(t_data *data, t_config *config)
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

int	error_xpm(t_data *data, t_config *config)
{
	if (error_xpm_extension(config) == 0)
	{
		ft_putstr_fd("Error : xpm_extension error\n", 1);
		shut_down(data);
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

int	error_argument(int argc, char *argv[])
{
	if (argc != 2 && argc != 3)
	{
		ft_putstr_fd("Error : argc != 2 && argc != 3\n", 1);
		return (0);
	}
	else if (error_extension(argv[1], ".cub") == 0)
	{
		ft_putstr_fd("Error : cub_extension error\n", 1);
		return (0);
	}
	return (1);
}

int	error_extension(char *filename, char *extension_name)
{
	char	*filename_extension;
	int		i;

	if (filename == NULL || filename[0] == '\0')
		return (0);
	i = 0;
	while (ft_strchr(filename, '.') != NULL)
	{
		filename_extension = ft_strchr(filename, '.');
		filename++;
	}
	if (filename_extension == NULL)
		return (0);
	if (ft_strncmp(extension_name, filename_extension, 4) != 0)
		return (0);
	return (1);
}

int	error_xpm_extension(struct s_config *config)
{
	char *str;

	str = config->east_texture;
	if (error_extension(str, ".xpm") == 0)
		return (0);
	str = config->north_texture;
	if (error_extension(str, ".xpm") == 0)
		return (0);
	str = config->south_texture;
	if (error_extension(str, ".xpm") == 0)
		return (0);
	str = config->west_texture;
	if (error_extension(str, ".xpm") == 0)
		return (0);
	str = config->sprite_texture;
	if (error_extension(str, ".xpm") == 0)
		return (0);
	return (1);
}
