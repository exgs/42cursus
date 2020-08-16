#include "cub_default.h"

void put_background(t_data *ptr)
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

int key_press(int keycode, void *param)
{
	t_data *ptr = param;
	if (keycode == 0)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("a\n");
		ptr->obj->pos[0] -= 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->obj->pos[0], ptr->obj->pos[1]);
	}
	else if (keycode == 0x0d)
	{	
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("w\n");
		ptr->obj->pos[1] -= 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->obj->pos[0], ptr->obj->pos[1]);
	}
	else if (keycode == 2)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("d\n");
		ptr->obj->pos[0] += 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->obj->pos[0], ptr->obj->pos[1]);

	}
	else if (keycode == 1)
	{
		mlx_clear_window(ptr->mlx, ptr->win);
		put_background(ptr);
		printf("s\n");
		ptr->obj->pos[1] += 10;
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, ptr->obj->pos[0], ptr->obj->pos[1]);
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
	t_data data;

	t_config configs;
	char **config_file;
	int i = 0;
	config_file = get_datas_linebyline("./srcs/map/map1");
	default_setting_config_data(&configs);
	extract_configs_from_line(config_file, &configs);
	print_config_data(&configs);
	get_free_all_linebyline(config_file);

	t_data data;
	if ((data.mlx = mlx_init()) == NULL)
		return (0);
	}
	if (NULL == (data.win = mlx_new_window(data.mlx, 1000, 1000, "Hello, world!")))
	{
		printf("System can't open graphic window\n");
		return (0);
	}
	mlx_string_put(data.mlx, data.win, 500, 500, 200, "Hello guys!\n");
	
	data. = mlx_xpm_file_to_image(data.mlx, "./srcs/wall/벽.xpm", &(data.width), &(data.height));
	
	mlx_put_image_to_window(data.mlx, data.win, data.img, 400,200);

	put_background(&ptr1);
	ptr1.pos[0] = 100;
	ptr1.pos[1] = 100;

	mlx_mouse_show();
	// mlx_do_key_autorepeatoff(ptr1.mlx);
	mlx_hook(ptr1.win, 2, 0, key_press, &ptr1);
	free_map(configs.map, &configs);
	mlx_loop(ptr1.mlx);
	return(0);
}
