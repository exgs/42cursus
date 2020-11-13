/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:33:13 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/13 19:41:23 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_hook.h"

int		ray_matrix(char dir, double *x, double *y)
{
	double temp;
	double angle;

	angle = M_PI / 15;
	temp = *x;
	if (dir == 1)
	{
		*x = cos(angle) * (*x) - sin(angle) * (*y);
		*y = sin(angle) * (temp) + cos(angle) * (*y);
	}
	else
	{
		angle = angle * -1;
		*x = cos(angle) * (*x) - sin(angle) * (*y);
		*y = sin(angle) * (temp) + cos(angle) * (*y);
	}
	return (1);
}

void	ray_rotating(int keycode, void *param)
{
	t_ray	*ray;
	int		a;

	ray = param;
	if (keycode == KEY_LEFT)
	{
		a = ray_matrix(-1, &ray->dir[X], &ray->dir[Y]);
		a = ray_matrix(-1, &ray->plane[X], &ray->plane[Y]);
	}
	else if (keycode == KEY_RIGHT)
	{
		a = ray_matrix(1, &ray->dir[X], &ray->dir[Y]);
		a = ray_matrix(1, &ray->plane[X], &ray->plane[Y]);
	}
	return ;
}
