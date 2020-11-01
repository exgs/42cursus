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

	struct s_animate	*ani;
	struct s_position	*pos;
	struct s_mouse_position	*mouse;

	void *image_array[10];
}				t_data;

typedef struct s_mouse_position{
	int pos[2];
}				t_mouse_position;

typedef struct s_position{
	int pos[2]; 
	int mov[2];
}				t_position;

typedef struct s_second{
	int start;
	int end;
}				t_second;

typedef struct s_animate{
	int color;
	int count;
}				t_animate;



int	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;

	return (3);
}

int	loop_hook_easy(void *param) //&img // t_data img;
{
	t_data *ptr = param;
	int num;
	ptr->ani->color -= 0x000101;
	printf("mov[X]:%d mov[Y]: %d\n", ptr->pos->mov[X], ptr->pos->mov[Y]);
	while (ptr->pos->mov[Y] > 0)
	{
		num = 0;
		ptr->pos->mov[X]++;
		while (num < ptr->pos->mov[X])
		{
			my_mlx_pixel_put(ptr, ptr->pos->pos[X] + num, ptr->pos->pos[Y] + ptr->pos->mov[Y], ptr->ani->color);
			// if (3 == (my_mlx_pixel_put(param, ptr->pos->pos[X] + num, ptr->pos->pos[Y] + ptr->pos->mov[Y], ptr->ani->color)))
			// 	printf("yes\n");
			// mlx_pixel_put(ptr->mlx, ptr->win, ptr->pos->pos[X] + num, ptr->pos->pos[Y] + ptr->pos->mov[Y], ptr->ani->color);
			num++;
		}
		ptr->pos->mov[Y]--;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->image_array[1], 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	// printf("loophookeasy : %p\n", ptr);
	ptr->pos->mov[X] = 0;
	ptr->pos->mov[Y] = 200;
	// printf("mov[X]:%d mov[Y]: %d\n", ptr->pos->mov[X], ptr->pos->mov[Y]);
	return (1);
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
		// mlx_destroy_window(img->mlx, img->win);
		exit(0);
	}
	// else if (keycode == 1)
	// {
	// 	loop_hook_easy(param);
	// 	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
		
	// }
	return (1);
}

int mouse_move(int x, int y, void *param, int button)
{
	t_data *ptr = param;
	static char in_out = 0;
	void *mouse_img;
	int width;
	int height;
	ptr->mouse->pos[X] = x;
	ptr->mouse->pos[Y] = y;
	// mlx_clear_window(ptr->mlx, ptr->win);
	mouse_img = ptr->image_array[0];
	// if (NULL == (mouse_img = mlx_xpm_file_to_image(ptr->mlx, "./srcs/item/42.xpm" ,&width ,&height)))
	// {
	// 	printf("mouse_img == NULL!!\n");
	// 	return (0);
	// }
	printf("%p\n", mouse_img);
	// mlx_pixel_put(ptr->mlx, ptr->win, x, y, 0x000000);
	mlx_put_image_to_window(ptr->mlx, ptr->win, mouse_img, x, y);
	// mlx_destroy_image(ptr->mlx, mouse_img);
	// mouse_img = NULL;
	printf("%d %d\n", x, y);
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
		printf("mouse release!\n");
		// printf("%d\n", time(NULL));
		// printf("time end ; %d\n", my_time->end);
		if (my_time->end - my_time->start >= 2)
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
		printf("mouse click!\n");
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
	int height;
	int width;
	void *img2;
    t_data  img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.win = mlx_win;
	img.mlx = mlx;
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.image_array[1] = mlx_xpm_file_to_image(img.mlx, "./srcs/item/바탕화면.xpm", &width, &height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
	
	// printf("-----------%p-------------\n", img.img);
	int scale = mov[Y];
	int color = 0x99ccff;
	t_animate ani;
	t_position posit;
	t_mouse_position mouse_pos;

	//직각삼각형
	pos[X] = 500; pos[Y] = 500;
	mov[X] = 0; mov[Y] = 200;
	img.ani = &ani;
	img.pos = &posit;
	img.mouse = &mouse_pos;
	// mouse_pos.pos[X] = 0;
	// mouse_pos.pos[Y] = 0;
	img.pos->mov[X] = mov[X]; 
	img.pos->mov[Y] = mov[Y];
	img.pos->pos[X] = pos[X];
	img.pos->pos[Y] = pos[Y];
	ani.color = color;
	
	img.image_array[0] = mlx_xpm_file_to_image(img.mlx, "./srcs/item/42.xpm" ,&width ,&height);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	// mlx_put_image_to_window(img.mlx, img.win, img.img,);
	//keyboard_event
	//keyboard_event

	//mouse_event
	// mlx_hook(img.win, 4, 1L<<2, mouse_press, &img);
	mlx_hook(img.win, 5, 1L<<3, mouse_release, &img);
	mlx_hook(img.win, 6, 1L<<6, mouse_move, &img);
	mlx_mouse_show();
	mlx_loop_hook(img.mlx, loop_hook_easy, &img);
	printf("keyboard %d\n", mlx_hook(img.win, 2, 0, mlx_exit, &img));
	// mlx_loop(img.mlx);
	// mlx_hook(img.win, 25, 0, 0, &img);
	printf("main : %p\n", &img);
	printf("%d\n", mlx_loop(mlx));
}
