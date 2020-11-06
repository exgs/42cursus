#include "mlx_hook.h"

int ray_matrix(char dir, double *x, double *y)
{
	double temp = *x;
	double angle = M_PI/15;
	
	if (dir == 1)
	{
		*x = cos(angle)*(*x) - sin(angle)*(*y);
		*y = sin(angle)*(temp) + cos(angle)*(*y);
	}
	else
	{
		angle = angle *-1;
		*x = cos(angle)*(*x) - sin(angle)*(*y);
		*y = sin(angle)*(temp) + cos(angle)*(*y);
	}
	return (1);
}

void ray_rotating(int keycode, void *param)
{
	t_ray *ray = param;
	int a;

	printf("Before dirX : %f dirY : %f\n", ray->dir[X], ray->dir[Y]);
	if (keycode == 123)
	{
		printf("<-\n");
		a = ray_matrix(-1, &ray->dir[X], &ray->dir[Y]);
		a = ray_matrix(-1, &ray->plane[X], &ray->plane[Y]);
		printf("After dirX : %f dirY : %f\n", ray->dir[X], ray->dir[Y]);
	}
	else if (keycode == 124)
	{	
		printf("->\n");
		a = ray_matrix(1, &ray->dir[X], &ray->dir[Y]);
		a = ray_matrix(1, &ray->plane[X], &ray->plane[Y]);
		printf("After dirX : %f dirY : %f\n", ray->dir[X], ray->dir[Y]);
	}
	return ;
}
