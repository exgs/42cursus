#include "mlx_hook.h"

int key_press(int keycode, void *param)
{
	t_data *data = param;
	if (keycode == KEY_ESC)
	{
		free_map(data->map);
		exit(0);
		return (0);
	}
	printf("Before X:%f Y:%f\n", data->obj.pos[X], data->obj.pos[Y]);
	obj_moving(keycode, data);
	ray_rotating(keycode, &data->obj.ray);
	return (1);
}

int is_wall(double x, double y, struct s_data *data)
{
	if (data->map[(int)x][(int)y] != 0)
		return 1;
	else
		return 0;
}

int		shut_down(t_data *data)
{
	free_map(data->map);
	exit(0);
}
