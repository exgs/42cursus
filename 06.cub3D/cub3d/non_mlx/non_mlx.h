/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:31:47 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/13 17:03:05 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NON_MLX_H
# define NON_MLX_H

# include "../cub_default.h"
# include "../libft_plus/libft.h"
# include "../libft_plus/gnl/get_next_line_cub.h"

typedef struct	s_config
{
	int				resolution[2];
	char			north_texture[100];
	char			south_texture[100];
	char			west_texture[100];
	char			east_texture[100];
	char			sprite_texture[100];
	char			**file;
	char			**map;
	int				map_row;
	int				map_column;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	double			pos_init[2];
	double			dir_init[2];
}				t_config;

typedef struct	s_index
{
	int			i;
	int			j;
	int			file_i;
	int			file_j;
}				t_index;
struct s_data;
struct s_pair;

int				default_setting_config_data(t_config *config_data);
int				extract_configs(char **config_lines, t_config *configs);
int				extract_config1(char *config_oneline, t_config *configs);
int				extract_config2(char *config_oneline, t_config *configs);
int				extract_resolution(char *str, t_config *configs);
int				extract_north_texture(char *str, t_config *configs);
int				extract_south_texture(char *str, t_config *configs);
int				extract_west_texture(char *str, t_config *configs);
int				extract_east_texture(char *str, t_config *configs);
int				extract_sprite_texture(char *str, t_config *configs);
int				extract_floor_color(char *str, t_config *configs);
int				extract_ceiling_color(char *str, t_config *configs);
int				counting_num(char *str);
int				extract_map_data(char **config_lines, t_config *configs,
									int map_start);
int				get_mapsize(char **config_lines, t_config *configs,
									int map_start);
int				fill_map_space(char *config_oneline, t_config *configs,
								t_index *idx);
void			fill_map(char **config_lines, t_config *configs,
								int map_start);
void			set_init_posdir(char dir, t_config *configs, t_index *idx);
void			fill_map_read(char *config_oneline, t_config *configs,
								t_index *idx);

int				map_validation(struct s_data *data);
int				top_bottom_valid(char **map, struct s_data *data);
int				left_right_valid(char **map, struct s_data *data);
int				valid_contaminant(char **map, struct s_data *data);
void			print_config_data(t_config *configs);
int				flush_string(char *str);
int				free_map(char **map);

int				ft_atoi_cub(const char *str, int *idx);

int				getimg_xpm2(struct s_data *data, struct s_config *config,
							int *i);
int				getimg_xpm(struct s_data *data, struct s_config *config);
#endif
