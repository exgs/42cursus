#ifndef MLX_HOOK_H
# define MLX_HOOK_H
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124


#include "../cub_default.h"

void ray_rotating(int keycode, void *param);
int is_wall(double x, double y, struct s_data *data);
void obj_moving(int keycode, struct s_data *param);
void key_press(int keycode, void *param);
int ray_matrix(char dir, double *x, double *y);
void move_left(struct s_data* param, double step_interval);
void move_right(struct s_data* param, double step_interval);
void move_forward(struct s_data* param, double step_interval);
void move_backward(struct s_data* param, double step_interval);
#endif
