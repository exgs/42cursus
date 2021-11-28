/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:47:35 by yunslee           #+#    #+#             */
/*   Updated: 2021/11/28 13:31:55 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

# define X 0
# define Y 1

# define LEFTMOUSE 1
# define RIGHTMOUSE 2
# define MIDDLEMOUSE 3

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

int keyboard_press(int keycode, void *param)
{
	t_data *img = param;
	printf("keyboard_press\n");
	if(keycode == 0)
	{
		printf("A\n");
	}
	else if(keycode == 1)
	{
		printf("S\n");
	}
	else if(keycode == 2)
	{
		printf("D\n");
	}
	else if(keycode == 13)
	{
		printf("W\n");
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

// 마우스가 화면 밖으로 나가면 Bye, 화면 안으로 들어오면 Hi 출력
int mouse_range(int x, int y, void *param)
{
	static char in_out = 0;
	// printf("%d %d\n", x, y);
	if ((x > 0 && x < 1000) && (y > 0 && y < 1000) && in_out == 0)
	{
		printf("hi\n");
		in_out = 1;
	}
	else if ((!(x > 0 && x < 1000) || !(y > 0 && y < 1000)) && in_out == 1)
	{
		printf("bye\n");
		in_out = 0;
	}
	return (1);
}

// 마우스를 2초 동안 눌러보세요
int mouse_release(int button, int x, int y, void* param)
{
	t_second *my_time = param;
	my_time->end = 0;
	if (button == 1)
	{
		my_time->end = time(0);
		if (my_time->end - my_time->start > 2)
		{
			printf("click my_time is 2 second over\n");
		}
	}
	return (1);
}

int mouse_press(int button, int x, int y, void* param)
{
	t_second *my_time = param;
	my_time->start = 0;
	if (button == 1)
	{
		my_time->start = time(0);
		printf("time start ; %d\n", my_time->start);
	}
	printf("Mouse Click keycode %d\n",button);
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
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.win = mlx_win;
	img.mlx = mlx;
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
	// img.bits_per_pixel = 24;
	// img.line_length = 1000 * img.bits_per_pixel / 8;
	/* gnl의 두 번째인자에 문자열이 담기듯이 넣는 것이아니라 담겨져 나오는 값이다.
	img.bits_per_pixel = 32;
	img.line_length = 1000 * img.bits_per_pixel / 8;
	img.endian = 0;
	실제로 값이 잘 담겨나오는지 위에서 예상한 값과 비교해보자
	*/
	printf("%d %d %d\n", img.bits_per_pixel, img.line_length, img.endian);

	int temp_x;
	int temp_y;
	int num = 0;
	int scale = mov[Y];
	pos[X] = 500; pos[Y] = 500;
	mov[X] = 400; mov[Y] = 400;
	// 직각삼각형
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

	// //피라미드 int형에서는 홀수만 가능
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

	t_second param; // 전달 하고자하는 매개변수
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // 캔버스에 그린 그림을 window에 그려줌(띄움)
	
	//keyboard_event
	mlx_hook(img.win, 2, 0, keyboard_press, &img);

	//mouse_event
	// 두번째인자 2, 4, 5, 6에 대한 근거는 오른쪽 링크로 확인. https://harm-smits.github.io/42docs/libs/minilibx/events.html#x11-events
	mlx_hook(img.win, 4, 0, mouse_press, &param);
	mlx_hook(img.win, 5, 0, mouse_release, &param);
	mlx_hook(img.win, 6, 0, mouse_range, &img);

	// Unity의 Update처럼 loop마다 계속해서 호출되도록 look_hook을 걸 수 있음 vs "mlx_loop_hook () 함수의 구문은 이전 구문과 동일하지만 이벤트가 발생하지 않으면 주어진 함수가 호출됩니다."
	// 버튼을 누르는 이벤트가 frame 단위가 아닌 초 단위로 감지를 하기 때문에 다른 이벤트가 발생하더라도 계속해서 호출되는 것처럼 보이는 것
	// mlx_loop_hook(img.mlx, loop_hook, &param);
	
	mlx_loop(mlx); // solong 그래픽 프로그램이 꺼지지 않도록 무한루프 돌게 함
}
