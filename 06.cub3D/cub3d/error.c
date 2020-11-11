/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:11:23 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/11 22:11:44 by yunslee          ###   ########.fr       */
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
	if (getimg_xpm(data, config) == 0)
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
	return (1);
}
