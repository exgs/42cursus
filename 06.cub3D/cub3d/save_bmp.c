/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:12:35 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 16:18:41 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_utility.h"

int			save_bmp(t_data *data)
{
	void	*window;
	int		pad;
	int		fd;
	int		filesize;

	window = data->win;
	pad = (4 - ((int)data->win_width * 3) % 4) % 4;
	filesize = 54 + (3 * (int)data->win_width + pad) * (int)data->win_height;
	if ((fd = open("cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND
								, 0644)) < 0)
		return (0);
	if (write_bmp_header(fd, filesize, data) == 0)
		return (0);
	if (write_bmp_data(fd, data, pad) == 0)
		return (0);
	close(fd);
	return (1);
}

int			write_bmp_data(int fd, t_data *data, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	raycasting(data);
	i = data->win_height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < data->win_width)
		{
			color = my_mlx_pixel_get(&(data->imgdata[0]), j, i);
			if (write(fd, &color, 3) < 0)
				return (0);
			j++;
		}
		if (pad > 0 && write(fd, &zero, pad) < 0)
			return (0);
		i--;
	}
	return (1);
}

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

int			write_bmp_header(int fd, int filesize, t_data *data)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = data->win_width;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = data->win_height;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	if (write(fd, bmpfileheader, 54) < 0)
		return (0);
	return (1);
}

int			error_savebmp(int argc, char *argv[], t_data *data)
{
	if (argc == 3)
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
