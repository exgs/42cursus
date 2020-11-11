/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:11:54 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/11 22:12:26 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_default.h"

int	main(int argc, char *argv[])
{
	t_config	config;
	t_data		data;

	if (argc < 2)
	{
		ft_putstr_fd("Error : argc < 2\n", 1);
		return (0);
	}
	data.filename = argv[1];
	if (load_file_error(&data, &config) == 0)
		return (0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
				data.win_width, data.win_height, "yunslee_cub3D");
	if (xpm_error(&data, &config) == 0)
		return (0);
	else if (argument_error(argc, argv, &data) == 0)
		return (0);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_loop_hook(data.mlx, raycasting, &data);
	mlx_hook(data.win, 17, 0, shut_down, &data);
	mlx_loop(data.mlx);
	return (1);
}
