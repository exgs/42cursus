/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:11:54 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 11:54:06 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utility.h"

int	main(int argc, char *argv[])
{
	t_config	config;
	t_data		data;

	if (error_argument(argc, argv) == 0)
		return (0);
	data.filename = argv[1];
	if (error_load_file(&data, &config) == 0)
		return (0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx,
				data.win_width, data.win_height, "yunslee_cub3D");
	if (error_xpm(&data, &config) == 0)
		return (0);
	else if (error_savebmp(argc, argv, &data) == 0)
		return (0);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_loop_hook(data.mlx, raycasting, &data);
	mlx_hook(data.win, 17, 0, shut_down, &data);
	mlx_loop(data.mlx);
	return (1);
}
