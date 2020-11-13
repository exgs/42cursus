/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getimg_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:21:25 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/13 17:22:17 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int	getimg_xpm2(struct s_data *data, struct s_config *config, int *i)
{
	void *p;

	p = mlx_xpm_file_to_image(data->mlx, config->south_texture,
						&data->imgdata[*i].width, &data->imgdata[*i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, (*i)++);
	p = mlx_xpm_file_to_image(data->mlx, config->north_texture,
						&data->imgdata[*i].width, &data->imgdata[*i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, (*i)++);
	p = mlx_xpm_file_to_image(data->mlx, config->sprite_texture,
						&data->imgdata[*i].width, &data->imgdata[*i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, (*i)++);
	return (1);
}

int	getimg_xpm(struct s_data *data, struct s_config *config)
{
	int		i;
	void	*p;

	i = 0;
	p = mlx_new_image(data->mlx, data->win_width, data->win_height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, i++);
	p = mlx_xpm_file_to_image(data->mlx, config->east_texture,
						&data->imgdata[i].width, &data->imgdata[i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, i++);
	p = mlx_xpm_file_to_image(data->mlx, config->west_texture,
						&data->imgdata[i].width, &data->imgdata[i].height);
	if (NULL == p)
		return (0);
	input_newimage2(data, p, i++);
	if (getimg_xpm2(data, config, &i) == 0)
	{
		return (0);
	}
	return (1);
}
