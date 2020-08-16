#include "cub3d.h"
#include "get_next_line_cub.h"
#include "libft.h"
#include "config.h"

void put_background(t_ptr *ptr)
{
	int count;
	count = 9;
	for (size_t i = 0; i < count; i++)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, i * 100, 0);//position
	}
	count = 9;
	for (size_t i = 0; i < count; i++)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 900, i * 100);//position
	}
	count = 9;
	for (size_t i = 0; i < count; i++)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 900 - i * 100, 900);//position
	}
	count = 9;
	for (size_t i = 0; i < count; i++)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 900 - i * 100);//position
	}
	return ;
}

int pos_move(int keycode, void *param)
{
	t_ptr *ptr = param;
	if (keycode == 0)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("a\n");
		ptr->pos[0] -= 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->pos[0], ptr->pos[1]);
	}
	else if (keycode == 0x0d)
	{	
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("w\n");
		ptr->pos[1] -= 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->pos[0], ptr->pos[1]);
	}
	else if (keycode == 2)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("d\n");
		ptr->pos[0] += 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->pos[0], ptr->pos[1]);

	}
	else if (keycode == 1)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("s\n");
		ptr->pos[1] += 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->pos[0], ptr->pos[1]);
	}
	else if(keycode == 53)
	{
		printf("esc\n");
		mlx_destroy_window(ptr->mlx, ptr->win);
		exit(0);
	}
	return (1);
}

int main()
{
	t_ptr ptr1;
	t_ptr ptr2;

	t_config configs;
	char **config_file;
	int i = 0;
	config_file = get_datas_linebyline("./srcs/map/map1");
	default_setting_config_data(&configs);
	extract_configs_from_line(config_file, &configs);
	print_config_data(&configs);
	get_free_all_linebyline(config_file);

	if ((ptr1.mlx = mlx_init()) == NULL)
	{
		printf("System can't initialize the connection between your software and the display\n");
		return (0);
	}
	if (NULL == (ptr1.win = mlx_new_window(ptr1.mlx, 1000, 1000, "Hello, world!")))
	{
		printf("System can't open graphic window\n");
		return (0);
	}

	/*바탕색 칠하기*/
	// int count = 1000;
	// for (size_t i = 0; i < count; i++)
	// {
	// 	for (size_t j = 0; j < count; j++)
	// 	{
	// 		mlx_pixel_put(ptr1.mlx, ptr1.win, i, j, 0x00ffffff);
	// 	}
	// }
	mlx_string_put(ptr1.mlx, ptr1.win, 500, 500, 200, "Hello guys!\n");
	
	/*일반 이미지 가져오기*/
	// ptr1.img = mlx_new_image(ptr1.mlx, 10, 10);

	/*.xpm 파일에서 이미지 가져오기*/
	// ptr1.img = mlx_xpm_file_to_image(ptr1.mlx, "./42.xpm", &ptr1.width, &ptr1.height);
	// ptr1.img = mlx_xpm_file_to_image(ptr1.mlx, "./blackbox.xpm", &ptr1.width, &ptr1.height);
	ptr1.img = mlx_xpm_file_to_image(ptr1.mlx, "./srcs/wall/벽.xpm", &(ptr1.width), &(ptr1.height));
	
	//mlx_get_data 관련한 예시
	// int bit = 2;
	// int size = 3;
	// int endian = 0;
	// mlx_get_data_addr(ptr1.img, &bit, &size, &endian);
	// printf("------%d %d %d\n",bit, size ,endian);
	/*.xpm 파일에서 문자열로 읽어서 가져오기*/
	// ptr1.img = mlx_xpm_to_image(ptr1.mlx, &ptr1.img, &width2, &height2);

	/*이미지를 윈도우창에 출력하기*/
	mlx_put_image_to_window(ptr1.mlx, ptr1.win, ptr1.img, 400,200);
	// printf("%d\n", mlx_put_image_to_window(ptr1.mlx, ptr1.win, ptr1.img, 400,200));//position
	// printf("---%d\n", mlx_destroy_image(ptr1.mlx, ptr1.img));
	// printf("%p\n", ptr1.img);

	put_background(&ptr1);
	ptr1.pos[0] = 100;
	ptr1.pos[1] = 100;

	// int     mlx_mouse_hide();
	// int     mlx_mouse_show();
	// int     mlx_mouse_move(void *win_ptr, int x, int y);
	// int     mlx_mouse_get_pos(void *win_ptr, int *x, int *y);
	// mlx_mouse_hide();
	mlx_hook(ptr1.win, 2, 0, pos_move, &ptr1);
	free_map(configs.map, &configs);
	// mlx_key_hook(ptr1.win, pos_move, &ptr1);
	mlx_loop(ptr1.mlx);
	return(0);
}
