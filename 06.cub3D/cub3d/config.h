#ifndef CONFIG_H
# define CONFIG_H

#include "cub_default.h"
#include "./libft_plus/libft.h"
#include "./libft_plus/gnl/get_next_line_cub.h"

typedef struct s_config
{
	int resolution[2];
	char north_texture[100];
	char south_texture[100];
	char west_texture[100];
	char east_texture[100];
	char sprite_texture[100];
	char **file;
	char **map; //주의사항 char형으로 해도 좋을꺼 같음 valgrind에서만 에러가 발생함.
	int map_row;	//주의사항 : 한 줄에 있는 벽의 갯수(not index)
	int map_column;	//주의사항 : 세로 줄의 갯수(not index)(높이)
	int floor_color;
	int ceiling_color;
	double pos_init[2];
	double dir_init[2];
}				t_config;

// char **get_datas_linebyline(char *path);
// int get_free_all_linebyline(char **lines);

int default_setting_config_data(t_config *config_data);

int extract_configs_from_line(char **config_lines, t_config *configs);
int extract_resolution(char *str, t_config *configs);
int extract_north_texture(char *str, t_config *configs);
int extract_south_texture(char *str, t_config *configs);
int extract_west_texture(char *str, t_config *configs);
int extract_east_texture(char *str, t_config *configs);
int extract_sprite_texture(char *str, t_config *configs);
int extract_floor_color(char *str, t_config *configs);
int extract_ceiling_color(char *str, t_config *configs);
int extract_map_data(char **config_lines, t_config *configs, int map_start);
void fill_in_map(char **config_lines, t_config *configs, int map_start);

void print_config_data(t_config *configs);
void flush_string(char *str);
int free_map(char **map);

static int	atoi_while_cub(const char *str, int i, int sign, int *idx);
int			ft_atoi_cub(const char *str, int *idx);

#endif
	