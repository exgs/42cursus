#include "mlx_hook.h"

void move_left(struct s_data* param, double step_interval)
{
	t_object *obj = &param->obj;
	double angle;
	double pos_x;
	double pos_y;

	angle = -M_PI/2;
	pos_x = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
	pos_y = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
	if (is_wall(pos_x, pos_y, param) == 1)
		return;
	obj->pos[X] = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
	obj->pos[Y] = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
	printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
}

void move_right(struct s_data* param, double step_interval)
{
	t_object *obj = &param->obj;
	double angle;
	double pos_x;
	double pos_y;

	angle = M_PI/2;
	pos_x = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
	pos_y = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
	if (is_wall(pos_x, pos_y, param) == 1)
		return;
	obj->pos[X] = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
	obj->pos[Y] = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
	printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
}


void move_forward(struct s_data* param, double step_interval)
{
	t_object *obj = &param->obj;
	double pos_x;
	double pos_y;

	pos_x = obj->pos[X] + step_interval * obj->ray.dir[X];
	pos_y = obj->pos[Y] + step_interval * obj->ray.dir[Y];
	if (is_wall(pos_x, pos_y, param) == 1)
		return;
	obj->pos[X] = obj->pos[X] + step_interval * obj->ray.dir[X];
	obj->pos[Y] = obj->pos[Y] + step_interval * obj->ray.dir[Y];
	printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
}

void move_backward(struct s_data* param, double step_interval)
{
	t_object *obj = &param->obj;
	double pos_x;
	double pos_y;

	pos_x = obj->pos[X] - step_interval * obj->ray.dir[X];
	pos_y = obj->pos[Y] - step_interval * obj->ray.dir[Y];
	if (is_wall(pos_x, pos_y, param) == 1)
		return;
	obj->pos[X] = obj->pos[X] - step_interval * obj->ray.dir[X];
	obj->pos[Y] = obj->pos[Y] - step_interval * obj->ray.dir[Y];
	printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
}

void obj_moving(int keycode, struct s_data *param)
{
	t_object *obj = &param->obj;
	double step_interval;

	step_interval = 1.0;
	if (keycode == KEY_A)
		move_left(param, step_interval);
	else if (keycode == KEY_W)
		move_forward(param, step_interval);
	else if (keycode == KEY_D)
		move_right(param, step_interval);
	else if (keycode == KEY_S)
		move_backward(param, step_interval);
}
