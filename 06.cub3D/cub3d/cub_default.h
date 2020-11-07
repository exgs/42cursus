/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_default.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:11:30 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/07 14:56:41 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DEFAULT_H
# define CUB_DEFAULT_H
# include "./non_mlx/non_mlx.h"
# include "./mlx_hook/mlx_hook.h"
# include "./mlx_loop_hook/mlx_loop_hook.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define X 0
# define Y 1

# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct	s_ray{
	double		dir[2];
	double		plane[2];
}				t_ray;

typedef struct		s_object{
	double			pos[2];
	struct s_ray	ray;
}					t_object;

typedef struct	s_image{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct	s_data{
	struct s_object	obj;
	struct s_image	imgdata[10];
	struct s_config	*config;
	void			*mlx;
	void			*win;
	int				win_width;
	int				win_height;
	char			**map;
	struct s_sprite	spritedata[50];
	int				sprite_order[50];
	double			sprite_distance[50];
	int				sprite_num;
	double			zbuffer[5000];
}				t_data;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

void			my_mlx_pixel_put(t_image *imgdata, int x, int y, int color);
unsigned int	my_mlx_pixel_get(t_image *imgdata, int x, int y);
int				config_to_data(t_data* data, struct s_config* configs);
int				input_newimage(t_data *data, void *new_img);
int				left_right_valid(char **map, t_data *data);
int				map_validation(t_data *data);
int				top_bottom_valid(char **map, t_data *data);
int				valid_contaminant(char **map, t_data *data);

int				input_newimage2(t_data *data, void *new_img, int img_index);
#endif
