/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_keypress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:25:21 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 10:42:52 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook.h"

int	key_press(int keycode, void *param)
{
	t_data *data;

	data = param;
	if (keycode == KEY_ESC)
	{
		shut_down(data);
		return (0);
	}
	obj_moving(keycode, data);
	ray_rotating(keycode, &data->obj.ray);
	return (1);
}

int	is_wall(double x, double y, struct s_data *data)
{
	if (data->map[(int)x][(int)y] == 1 || data->map[(int)x][(int)y] == 2
		|| data->map[(int)x][(int)y] == 9)
		return (1);
	return (0);
}

int	shut_down(t_data *data)
{
	free_map(data->map);
	exit(0);
	return (1);
}
