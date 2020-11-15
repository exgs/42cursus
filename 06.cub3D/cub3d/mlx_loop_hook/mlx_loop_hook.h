/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop_hook.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 21:34:50 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 11:53:51 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_LOOP_HOOK_H
# define MLX_LOOP_HOOK_H
# include "../cub_utility.h"

typedef struct	s_raycasting
{
	double	camerax;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		h;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		x;
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
}				t_raycasting;

typedef struct	s_spritecasting
{
	double	sprite_x;
	double	sprite_y;
	double	invdet;
	double	transform_x;
	double	transform_y;
	double	spritescreen_x;
	int		spriteheight;
	int		drawstart_y;
	int		drawend_y;
	int		spritewidth;
	int		drawstart_x;
	int		drawend_x;
	int		tex_x;
	int		tex_y;
	int		d;
	int		color;
	int		y;
}				t_spritecasting;
struct s_data;
struct s_pair;
struct s_config;
int				raycasting(void *param);
void			sprites_raycasting(struct s_data *data);
void			walls_raycasting(struct s_data *data);
int				find_sprite(struct s_data *data, struct s_config *config);
void			count_sprite(int i, struct s_data *data,
								struct s_config *config, int *count);
void			sort_order(struct s_pair *orders, int amount);
void			sort_sprites(int *order, double *dist, int amount);
void			floor_ceiling_paint(struct s_data *data);
void			ceiling_paint(struct s_data *data);
void			floor_paint(struct s_data *data);
void			until_hit_wall(struct s_data *data, t_raycasting *r);
void			set_sidedist(struct s_data *data, t_raycasting *r);
void			set_deltadist(struct s_data *data, t_raycasting *r);
void			wallx_from_perpwalldist(struct s_data *data, t_raycasting *r);
void			textured_wall_paint(struct s_data *data, t_raycasting *r,
										int win_x);
void			camera_matrix_setting(struct s_data *data, t_spritecasting *r,
									int i);
void			sprites_paint(struct s_data *data, t_spritecasting *r, int num);
void			limit_draw_startend(struct s_data *data, t_spritecasting *r);
void			sprites_paint2(struct s_data *data, t_spritecasting *r,
								int stripe, int sprite_serial_num);
#endif
