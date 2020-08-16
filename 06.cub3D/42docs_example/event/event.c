#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

# define X 0
# define Y 1

typedef struct  s_data {
	void		*mlx;
	void		*win;
	void		*img;

	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_second{
	int start;
	int end;
}				t_second;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
	return ;
}

void	loop_hook(int a)
{
	printf("hi\n");
	printf("%d\n",a);
	return ;
}

int mlx_exit(int keycode, void *param)
{
	t_data *img = param;

	printf("click\n");
	if(keycode == 0)
	{
		printf("a\n");
	}
	else if (keycode == 10)
	{
		printf("mouse\n");
	}
	else if(keycode == 53)
	{
		printf("esc\n");
		mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	return (1);
}

int mouse_hook(int x, int y, void *param)
{
	static char in_out = 0;
	// printf("%d %d\n", x, y);
	if ((x > 0 && x < 800) && (y > 0 && y < 800) && in_out == 0)
	{
		printf("hi\n");
		in_out = 1;
	}
	else if ((!(x > 0 && x < 800) || !(y > 0 && y < 800)) && in_out == 1)
	{
		printf("bye\n");
		in_out = 0;
	}
	// printf("%p\n",param);
	return (1);
}

int mouse_release(int button, int x, int y, void* param)
{
	t_second *my_time = param;
	my_time->end = 0;
	if (button == 1)
	{
		my_time->end = time(0);
		// printf("%d\n", time(NULL));
		// printf("time end ; %d\n", my_time->end);
		if (my_time->end - my_time->start > 2)
		{
			printf("click my_time is 2 second over\n");
		}
		// printf("interval : %d\n", (int)(my_time->end - my_time->start));
	}
	// printf("button_release %d\n",button);
	return (1);
}

int mouse_press(int button, int x, int y, void* param)
{
	t_second *my_time = param;
	my_time->start = 0;
	if (button == 1)
	{
		my_time->start = time(0);
		// printf("%d\n", time(0));
		// printf("time start ; %d\n", my_time->start);
	}
	// printf("button_press %d\n",button);
	// printf("address : %d\n", param);
	return (1);
}

int	main(void)
{
    void    *mlx;
    void    *mlx_win;
	int pos[2]; 
	int mov[2];
	int start;
	int end;
    t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	img.win = mlx_win;
	img.mlx = mlx;
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);

	int temp_x;
	int temp_y;
	int num = 0;
	int scale = mov[Y];
	pos[X] = 500; pos[Y] = 500;
	mov[X] = 400; mov[Y] = 400;
	//직각삼각형
	// while (mov[Y] > 0)
	// {
	// 	num = 0;
	// 	mov[X]++;
	// 	while (num < mov[X])
	// 	{
	// 		my_mlx_pixel_put(&img, pos[X] + num, pos[Y] + mov[Y], 0x99ccff);
	// 		num++;
	// 	}
	// 	mov[Y]--;
	// }

	//피라미드 int형에서는 홀수만 가능
	int start_x = (mov[Y] - 1) / 2;
	int i = 0;
	int temp;
	int count;
	int color = 0x99ccff;
	while (mov[Y] > 0)
	{
		count = 2 * (400 - mov[Y]) + 1;
		i = 0;
		if (mov[Y] % 2 == 0)
			color -= 0x000001;
		while (i < count)
		{
			my_mlx_pixel_put(&img, pos[X] + start_x + i, pos[Y] + mov[Y], color);
			i++;
		}
		start_x--;
		mov[Y]--;
	}

	t_second play_time;
	printf("---%p\n", &play_time);
	printf("%d\n", CLOCKS_PER_SEC);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//keyboard_event
	mlx_hook(img.win, 2, 0, mlx_exit, &img);

	//mouse_event
	mlx_hook(img.win, 4, 0, mouse_press, &play_time);
	mlx_hook(img.win, 5, 0, mouse_release, &play_time);
	mlx_hook(img.win, 6, 0, mouse_hook, &img);

	// mlx_loop_hook(img.mlx, loop_hook, &play_time);
	// mlx_hook(img.win, 25, 0, 0, &img);
	printf("main : %p\n", &img);
	// mlx_hook(img.win, 6, 0, mlx_mouse_hook, &img);
	mlx_loop(mlx);
}
