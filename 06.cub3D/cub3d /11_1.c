#include "cub_default.h"

int input_newimage(t_data *data, void *new_img)
{
	static int last_img_index = -1;
	if (data == NULL || new_img == NULL)
		return (-1);
	last_img_index++;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	data->imgdata[last_img_index].img = new_img;
	data->imgdata[last_img_index].addr =  mlx_get_data_addr(data->imgdata[last_img_index].img,
						&bits_per_pixel, &size_line, &endian);
	data->imgdata[last_img_index].bits_per_pixel = bits_per_pixel;
	data->imgdata[last_img_index].size_line = size_line;
	data->imgdata[last_img_index].endian = endian;
	return (last_img_index);
}

int ray_matrix(char dir, double *x, double *y)
{
	double temp = *x;
	double angle = M_PI/30;
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

int is_wall(double x, double y, t_data *data)
{
	if (data->map[(int)x][(int)y] != 0)
		return 1;
	else
		return 0;
}

void obj_moving(int keycode, t_data *param)
{
	t_object *obj = &param->obj;
	double step_interval = 0.5;
	double angle;
	double pos_x;
	double pos_y;
	printf("Before X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
	if (keycode == 0)
	{
		printf("a\n");
		angle = M_PI/2; //뒤집어진 세계
		pos_x = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
		pos_y = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
		if (is_wall(pos_x, pos_y, param) == 1)
			return;
		obj->pos[X] = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
		obj->pos[Y] = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
		printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
	}
	else if (keycode == 0x0d)
	{	
		printf("w\n");
		pos_x = obj->pos[X] + step_interval * obj->ray.dir[X];
		pos_y = obj->pos[Y] + step_interval * obj->ray.dir[Y];
		if (is_wall(pos_x, pos_y, param) == 1)
			return;
		obj->pos[X] = obj->pos[X] + step_interval * obj->ray.dir[X];
		obj->pos[Y] = obj->pos[Y] + step_interval * obj->ray.dir[Y];
		printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
	}
	else if (keycode == 2)
	{
		printf("d\n");
		angle = -M_PI/2; //뒤집어진 세계
		pos_x = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
		pos_y = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
		if (is_wall(pos_x, pos_y, param) == 1)
			return;
		obj->pos[X] = obj->pos[X] + step_interval * cos(angle)*(obj->ray.dir[X]) - sin(angle)*(obj->ray.dir[Y]);
		obj->pos[Y] = obj->pos[Y] + step_interval * sin(angle)*(obj->ray.dir[X]) + cos(angle)*(obj->ray.dir[Y]);
		printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
	}
	else if (keycode == 1)
	{
		printf("s\n");
		pos_x = obj->pos[X] - step_interval * obj->ray.dir[X];
		pos_y = obj->pos[Y] - step_interval * obj->ray.dir[Y];
		if (is_wall(pos_x, pos_y, param) == 1)
			return;
		obj->pos[X] = obj->pos[X] - step_interval * obj->ray.dir[X];
		obj->pos[Y] = obj->pos[Y] - step_interval * obj->ray.dir[Y];
		printf("X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
	}
	// printf("obj_moving:&data->obj:%p\n", obj);
}

void ray_rotating(int keycode, void *param)
{
	t_ray *ray = param;
	if (keycode == 123)
	{
		printf("<-\n");
		ray_matrix(1, &ray->dir[X], &ray->dir[Y]);
		ray_matrix(1, &ray->plane[X], &ray->plane[Y]);
	}
	else if (keycode == 124)
	{	
		printf("->\n");
		ray_matrix(-1, &ray->dir[X], &ray->dir[Y]);
		ray_matrix(-1, &ray->plane[X], &ray->plane[Y]);
	}
	return ;
}

void key_press(int keycode, void *param)
{
	t_data *data = param;
	// printf("pos:%f\n",data->obj.pos[X]);
	// printf("%p\n", data);
	// printf("&data->obj : %p\n", &data->obj);
	// printf("data->obj : %p\n", data->obj);
	if (keycode == 53)//esc
	{
		exit(0);
		return ;
	}
	printf("X:%f Y:%f\n", data->obj.pos[X], data->obj.pos[Y]);
	obj_moving(keycode, data);
	ray_rotating(keycode, &data->obj.ray);
}

void ray_casting2(void *param)
{
	t_data *data = param;
	// if (keycode == 53)//esc
	// {
	// 	exit(0);
	// 	return ;
	// }
	double cameraX;
	double rayDirX; 
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistY;
	double deltaDistX;
	double perpWallDist;
	int stepX;
	int stepY;

	int hit = 0; //was there a wall hit?
	int side; // 0 : '행'과 만남 1 : '열'과 만남

	int h;
	int lineHeight;
	//calculate lowest and highest pixel to fill in current stripe
	int drawStart;
	int drawEnd;
	int x;
	for (x = 0; x < WIDTH; x++)
	{
		for (int i = 0; i < HEIGHT/2; i++)
		{
			my_mlx_pixel_put(&data->imgdata[0],x,i, 0x22);
		}
	}
	for (x = 0; x < WIDTH; x++)
	{
		for (int i = HEIGHT/2; i < HEIGHT; i++)
		{
			my_mlx_pixel_put(&data->imgdata[0],x,i, 0x093333);
		}
	}

	for (x = 0; x < data->obj.ray.w; x++)
	{
		// printf("%d\n", x);
		mapX = (int)data->obj.pos[X];
		mapY = (int)data->obj.pos[Y];
		cameraX = 2 * x / (double)data->obj.ray.w - 1;
		rayDirX = data->obj.ray.dir[X] + data->obj.ray.plane[X] * cameraX;
		rayDirY = data->obj.ray.dir[Y] + data->obj.ray.plane[Y] * cameraX;
		// rayDirY = rayDirY / sqrt(rayDirX * rayDirX + rayDirY * rayDirY);
		// rayDirX = rayDirX / sqrt(rayDirX * rayDirX + rayDirY * rayDirY);  //<-| 유클리드거리 계산으로 되돌아감 -> fish eyes 유발
		// 지금 위에껄 뺴는 것이 perpWall 계산과 잘 맞아떨어짐
		deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1 / rayDirX));
		deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1 / rayDirY));
		if (rayDirX < 0)
		{
			stepX = -1;
			// sideDistX = (data->obj.pos[X] - data->obj.map[X]) * deltaDistX;
			sideDistX = (data->obj.pos[X] - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (1 - (data->obj.pos[X] - data->obj.map[X])) * deltaDistX;
			sideDistX = ((mapX + 1) - data->obj.pos[X]) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			// sideDistY = (data->obj.pos[Y] - data->obj.map[Y]) * deltaDistY;
			sideDistY = (data->obj.pos[Y] - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			// sideDistY = (1 - (data->obj.pos[Y] - data->obj.map[Y])) * deltaDistY;
			sideDistY = ((mapY + 1) - data->obj.pos[Y]) * deltaDistY;
		}
		hit = 0;
		while (hit == 0) //deltaDistX, sideDistX는 광선이 나아가는 데에 판단으로 쓰이지, 값으로는 더이상 쓰이지않음
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				// data->obj.map[X] += stepX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				// data->obj.map[Y] += stepY;
				mapY += stepY;
				side = 1;
			}
			if (data->map[(char)mapX][(char)mapY] > 0)
				hit = data->map[(char)mapX][(char)mapY];
		}
		data->obj.map[X] = mapX;
		data->obj.map[Y] = mapY;
		perpWallDist = 0;
		if (side == 0)
			perpWallDist = ((mapX + (1 - stepX) / 2) - data->obj.pos[X]) / rayDirX;
		else
			perpWallDist = ((mapY + (1 - stepY) / 2) - data->obj.pos[Y]) / rayDirY;
		// printf("%f\n", perpWallDist);
		h = HEIGHT;
		lineHeight = (int)(h / perpWallDist); //perpWallDist가 0이 나오지않도록 위치 잘 조정하기
		drawStart = (int)(h / 2 - lineHeight / 2);
		drawEnd = (int)(h / 2 + lineHeight / 2);
		if(drawStart < 0)
			drawStart = 0;
		if(drawEnd >= h)
			drawEnd = h - 1;
		/*Textured wall*/
		double wallX;
		if (side == 0)
			wallX = data->obj.pos[Y] + perpWallDist * rayDirY;
		else
			wallX = data->obj.pos[X] + perpWallDist * rayDirX;
		wallX -= (int)wallX;

		//x coordinate on the texture
		int texX = (int)(wallX * (double)TEXWIDTH);
		// if(side == 0 && rayDirX > 0)
		// 	texX = TEXWIDTH - texX - 1;
		// if(side == 1 && rayDirY < 0)
		// 	texX = TEXWIDTH - texX - 1;

		double step = 0.9 * (double)TEXHEIGHT/lineHeight; //여기가 형변환이 문제였네!
		double texPos = (drawStart - h/2 + lineHeight/2) * step;
		// double texPos = 0;
		unsigned int get_color;
		while (drawStart < drawEnd)
		{
			// int texY = (int)texPos & (TEXHEIGHT -1);
			texPos += step;
			// get_color = my_mlx_pixel_get(&(data->imgdata[1]), texX, texY);
			get_color = my_mlx_pixel_get(&(data->imgdata[1]), texX, (int)texPos);
			my_mlx_pixel_put(&(data->imgdata[0]), x ,drawStart, get_color);
			drawStart++;
		}
		/*--------------*/

		// 윈도우에 픽셀 그리는 함수	
		// if (side == 0)
		// 	wall_paint_x(x,drawStart,drawEnd, data);
		// else
		// 	wall_paint_y(x,drawStart,drawEnd, data);

		/*기존의 코드*/
		// while (drawStart < drawEnd)
		// {
		// 	my_mlx_pixel_put(&(data->imgdata[0]), x ,drawStart, 0xffffff);
		// 	drawStart++;
		// }
	}
	mlx_put_image_to_window(data->mlx, data->win, data->imgdata[0].img, 0, 0);
}

//명암조절이 안됨..
int wall_paint_x(int x, int drawStart, int drawEnd, void *param)
{
	t_data *data = param;
	if (data->obj.map[X] > (int)data->obj.pos[X])
	{
		while (drawStart < drawEnd)
		{
		my_mlx_pixel_put(&(data->imgdata[0]), x ,drawStart, 0xff0000);
		drawStart++;
		}
	}
	else
	{
		while (drawStart < drawEnd)
		{
		my_mlx_pixel_put(&(data->imgdata[0]), x ,drawStart, 0x00ff00);
		drawStart++;
		}
	}
}

int wall_paint_y(int x, int drawStart, int drawEnd, void *param)
{
	t_data *data = param;
	if (data->obj.map[Y] > (int)data->obj.pos[Y])
	{
		while (drawStart < drawEnd)
		{
		my_mlx_pixel_put(&(data->imgdata[0]), x ,drawStart, 0xffff00);
		drawStart++;
		}
	}
	else
	{
		while (drawStart < drawEnd)
		{
		my_mlx_pixel_put(&(data->imgdata[0]), x ,drawStart, 0x00ffff);
		drawStart++;
		}
	}
}


int	main(void)
{
	t_config config;
	if (default_setting_config_data(&config) == 1)
		printf("setting good config\n");
	else
	{
		printf("setting bad config\n");
		return (0);
	}
	config.file = get_datas_linebyline("./srcs/map/map2");
	extract_configs_from_line(config.file, &config);
	print_config_data(&config);
	// free_map(&config);
	get_free_all_linebyline(config.file);

	t_data data;
	data.win_width = WIDTH;
	data.win_height = HEIGHT;
	
	data.obj.pos[X] = 5.5;
	data.obj.pos[Y] = 5.5;
	printf("pos:%f\n",data.obj.pos[X]);
	data.obj.map[X] = (int)data.obj.pos[X];
	data.obj.map[Y] = (int)data.obj.pos[Y]; 
	data.obj.ray.dir[X] = 0;
	data.obj.ray.dir[Y] = 1;
	data.obj.ray.plane[X] = 0.5;
	data.obj.ray.plane[Y] = 0;
	data.obj.ray.w= 1000;
	data.map = config.map;
	double time = 0;
	double oldTime = 0;

	int img_idx = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Hello world!");
	img_idx = input_newimage(&data, mlx_new_image(data.mlx, WIDTH, HEIGHT));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, "./srcs/item/donor.xpm", &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, "./srcs/item/column.xpm", &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	// img_idx = input_newimage(&data, mlx_new_image(data.mlx, WIDTH, HEIGHT));

	/*pixel 찍는 방법*/
	my_mlx_pixel_put(&data.imgdata[0], WIDTH/4, HEIGHT/2, 0xffffff);
	mlx_put_image_to_window(data.mlx, data.win, data.imgdata[0].img, 0, 0);
	printf("%p\n", &data);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_loop_hook(data.mlx, ray_casting2, &data);
	/*event코드가 겹치면 안되는 거 같다.*/
	// mlx_hook(data.win, 2, 0, pos_moving, &data);
	// mlx_hook(data.win, 2, 0, dir_rotating, &data);
	mlx_loop(data.mlx);
		return (1);
}