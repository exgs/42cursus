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

int ray_180rotatingmatrix(double *x, double *y)
{
	double temp = *x;
	double angle = -M_PI/2;
	
	*x = cos(angle)*(*x) - sin(angle)*(*y);
	*y = sin(angle)*(temp) + cos(angle)*(*y);
	return (1);
}

char init_NSWE(t_data *data)
{
	char c;
	if (data == NULL)
		return 0;
	if (data->obj.ray.dir[X] == 1)
	{
		c = 'E';
		data->obj.ray.NSWE = 'E';
	}
	else if (data->obj.ray.dir[X] == -1)
	{
		c = 'W';
		data->obj.ray.NSWE = 'W';
	}
	else if (data->obj.ray.dir[Y] == 1)
	{
		c = 'S';
		data->obj.ray.NSWE = 'S';
	}
	else if (data->obj.ray.dir[Y] == -1)
	{
		c = 'N';
		data->obj.ray.NSWE = 'N';
	}
	return c;
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
	double step_interval = 1;
	double angle;
	double pos_x;
	double pos_y;

	angle = -M_PI/2;
	// if (obj->ray.NSWE == 'W' || obj->ray.NSWE == 'S')
	// 	angle = M_PI/2;
	// else
	// 	angle = -M_PI/2;
	printf("Before X:%f Y:%f\n", obj->pos[X], obj->pos[Y]);
	if (keycode == 0)
	{
		printf("a\n");
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
		angle *= -1;
		// angle = -M_PI/2; //뒤집어진 세계
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
int	shut_down(t_data *data)
{
	free_map(data->map);
	// mlx_destroy_image(data->imgdata[0]); 하는게 좋아보임
	exit(0);
}

void ray_rotating(int keycode, void *param)
{
	t_ray *ray = param;
	printf("Before dirX : %f dirY : %f\n", ray->dir[X], ray->dir[Y]);
	if (keycode == 123)
	{
		printf("<-\n");
		// if (ray->NSWE == 'W' || ray->NSWE == 'S')
		// {
		// 	ray_matrix(1, &ray->dir[X], &ray->dir[Y]);
		// 	ray_matrix(1, &ray->plane[X], &ray->plane[Y]);
		// }
		// else
		// {
		ray_matrix(-1, &ray->dir[X], &ray->dir[Y]);
		ray_matrix(-1, &ray->plane[X], &ray->plane[Y]);
		// }
		printf("After dirX : %f dirY : %f\n", ray->dir[X], ray->dir[Y]);
	}
	else if (keycode == 124)
	{	
		printf("->\n");
		// if (ray->NSWE == 'W' || ray->NSWE == 'S')
		// {
		// 	ray_matrix(-1, &ray->dir[X], &ray->dir[Y]);
		// 	ray_matrix(-1, &ray->plane[X], &ray->plane[Y]);
		// }
		// else
		// {
		ray_matrix(1, &ray->dir[X], &ray->dir[Y]);
		ray_matrix(1, &ray->plane[X], &ray->plane[Y]);
		// }
		printf("After dirX : %f dirY : %f\n", ray->dir[X], ray->dir[Y]);
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
		free_map(data->map);
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

	for (x = 0; x < WIDTH; x++)
	{
		// printf("%d\n", x);
		mapX = (int)data->obj.pos[X];
		mapY = (int)data->obj.pos[Y];
		cameraX = 2 * x / (double)WIDTH - 1;
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
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (data->map[(char)mapX][(char)mapY] == 1)
				hit = 1;
		}
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
		if(side == 0 && rayDirX > 0)
			texX = TEXWIDTH - texX - 1;
		if(side == 1 && rayDirY < 0)
			texX = TEXWIDTH - texX - 1;

		double step = 0.9 * (double)TEXHEIGHT/lineHeight; //여기가 형변환이 문제였네!
		double texPos = (drawStart - h/2 + lineHeight/2) * step;
		// double texPos = 0;
		unsigned int get_color;
		// int win_x;
		// if (data->obj.ray.NSWE == 'S' || data->obj.ray.NSWE == 'W')
		// 	win_x = data->obj.ray.w - x;
		// else
		// 	win_x = x;
		if (hit != 0)
		{
			while (drawStart < drawEnd)
			{
				int texY = (int)texPos & (TEXHEIGHT -1);
				texPos += step;
				get_color = my_mlx_pixel_get(&(data->imgdata[1]), texX, texY);
				// get_color = my_mlx_pixel_get(&(data->imgdata[1]), texX, (int)texPos);
				my_mlx_pixel_put(&(data->imgdata[0]), x ,drawStart, get_color);
				drawStart++;
			}
		}
		data->zbuffer[x] = perpWallDist;
		/*--------------*/

		// 윈도우에 픽셀 그리는 함수	 dir이 음수이면, 벽면이 색이 뒤바뀌는 문제 발생(11/1)
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
	// mlx_put_image_to_window(data->mlx, data->win, data->imgdata[0].img, 0, 0);

	/*스프라이트 색칠*/
	// for (size_t i = 0; i < 50; i++)
	// {
	// 	data->sprite_order[i] = 0;
	// 	data->sprite_distance[i] = 0;
	// }
	
	
	for(int i = 0; i < data->sprite_num; i++)
	{
		data->sprite_order[i] = i;
		data->sprite_distance[i] = (data->obj.pos[X] - data->spritedata[i].x) * (data->obj.pos[X] - data->spritedata[i].x) +
										(data->obj.pos[Y] - data->spritedata[i].y) * (data->obj.pos[Y] - data->spritedata[i].y);
	}
	sortSprites(data->sprite_order, data->sprite_distance, data->sprite_num);
	// printf("sprtie_num %d\n", data->sprite_num);
	for (int i = 0; i < data->sprite_num; i++)
    {
		// double new_dirX;
		// double new_dirY;
		// new_dirX = data->obj.ray.dir[X];
		// new_dirY = -data->obj.ray.dir[Y];
		// double spriteX = data->spritedata[data->sprite_order[i]].x - data->obj.pos[X];
		// double spriteY = (data->spritedata[data->sprite_order[i]].y - data->obj.pos[Y]);
		// double invDet = (double)1.0 / (data->obj.ray.plane[X] * new_dirY - new_dirX * data->obj.ray.plane[Y]);
		// double transformX = invDet * (new_dirY * spriteX - new_dirX * spriteY);
		// double transformY = invDet * (-data->obj.ray.plane[Y] * spriteX + data->obj.ray.plane[X] * spriteY); //this is actually the depth inside the screen, that what Z is in 3D
		////
		double spriteX = data->spritedata[data->sprite_order[i]].x - data->obj.pos[X];
		double spriteY = (data->spritedata[data->sprite_order[i]].y - data->obj.pos[Y]);
		double invDet = (double)1.0 / (data->obj.ray.plane[X] * data->obj.ray.dir[Y] - data->obj.ray.dir[X] * data->obj.ray.plane[Y]); //required for correct matrix multiplication

		double transformX = invDet * (data->obj.ray.dir[Y] * spriteX - data->obj.ray.dir[X] * spriteY);
		double transformY = invDet * (-data->obj.ray.plane[Y] * spriteX + data->obj.ray.plane[X] * spriteY); //this is actually the depth inside the screen, that what Z is in 3D
		// ray_180rotatingmatrix(&transformX, &transformY);


		int spriteScreenX = (int)((WIDTH / 2) * (1 + transformX / transformY));

		//calculate heidsght of the sprite on screen


		int spriteHeight = (int)abs((h / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		int drawStartY = -spriteHeight / 2 + h / 2; 
		if (drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + h / 2;
		if (drawEndY >= h)
			drawEndY = h - 1;

		//calculate width of the sprite
		// int spriteWidth = (int)abs((h / (transformY)));
		int spriteWidth = (int)abs((WIDTH / (transformY)));
		int drawStartX = -spriteWidth / 2 + spriteScreenX;
		if(drawStartX < 0)
			drawStartX = 0;
		int drawEndX = spriteWidth / 2 + spriteScreenX;
		if(drawEndX >= WIDTH)
			drawEndX = WIDTH - 1;
		printf("drawStartX : %d, drawStartY : %d\n", drawStartX, drawStartY);
		printf("drawEndX : %d, drawEndY : %d\n", drawEndX, drawEndY);
		printf("transformX : %f, transformY : %f\n", transformX, transformY);
		for(int stripe = drawStartX; stripe < drawEndX; stripe++)
		{
			// printf("stripe : %d\n", stripe);
			if(transformY > 0 && stripe > 0 && stripe < WIDTH && transformY < data->zbuffer[stripe]) //고쳐준 부분!!!!
			{
				printf("transformY < data->zbuffer[stripe] == %f :%f\n", transformY, data->zbuffer[stripe]);
				int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * TEXWIDTH / spriteWidth / 256);
				for (int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y) * 256 - h * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((d * TEXHEIGHT) / spriteHeight) / 256;
					unsigned int color;
					// color = texture[sprite[spriteOrder[i]].texture][texWidth * texY + texX]; //get current color from the texture
					color = my_mlx_pixel_get(&(data->imgdata[2]), texX, texY);
					if((color & 0x00FFFFFF) != 0)
					{
						my_mlx_pixel_put(&(data->imgdata[0]), stripe, y, color);
						// buffer[y][stripe] = color; //paint pixel if it isn't black, black is the invisible color
					}
				}
			}
		}
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

char **map_xy_reverse(char **map, t_config* config)
{
	if (map == NULL || map[0] == NULL)
		return NULL;
	char **reverse_map;
	int i;
	int j;

	i = 0;
	j = 0;
	reverse_map = (char **)malloc(sizeof(char *) * (config->map_row + 1));
	while (i < config->map_row)
	{
		reverse_map[i] = (char *)malloc(sizeof(char) * config->map_column + 1);
		reverse_map[i][config->map_column] = '\0';
		i++;
	}
	reverse_map[i] = NULL;
	
	i = 0;
	while (i < config->map_row)
	{
		j = 0;
		while (j < config->map_column)
		{
			reverse_map[i][j] = map[j][i];
			j++;
		}
		i++;
	}
	return reverse_map;
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
	config.file = get_datas_linebyline("./srcs/map/map4");
	extract_configs_from_line(config.file, &config);
	print_config_data(&config);
	get_free_all_linebyline(config.file);

	t_data data;
	data.win_width = WIDTH;
	data.win_height = HEIGHT;
	
	// data.obj.pos[X] = 5.5;
	// data.obj.pos[Y] = 5.5;
	// data.obj.ray.dir[X] = 0;
	// data.obj.ray.dir[Y] = -1;

	data.obj.pos[X] = config.pos_init[X];
	data.obj.pos[Y] = config.pos_init[Y];
	data.obj.ray.dir[X] = config.dir_init[X];
	data.obj.ray.dir[Y] = config.dir_init[Y];
	init_NSWE(&data);

	data.obj.ray.plane[X] = (data.obj.ray.dir[X]*cos(M_PI/2) - sin(M_PI/2)*data.obj.ray.dir[Y]);
	data.obj.ray.plane[Y] = (data.obj.ray.dir[X]*sin(M_PI/2) + cos(M_PI/2)*data.obj.ray.dir[Y]);
	printf("init_pos[X,Y] = [%f, %f]\n", data.obj.pos[X],data.obj.pos[Y]);
	printf("init_dir[X,Y] = [%f, %f]\n", data.obj.ray.dir[X],data.obj.ray.dir[Y]);
	printf("init_plane[X,Y] = [%f, %f]\n", data.obj.ray.plane[X],data.obj.ray.plane[Y]);
	
	
	data.obj.map[X] = (int)data.obj.pos[X];
	data.obj.map[Y] = (int)data.obj.pos[Y]; 
	// data.map = map_xy_reverse(config.map, &config); //여기서도 이제 free를 해주어야함.. double free
	// free_map(&config);
	data.map = config.map;

	data.sprite_num = count_sprite(&data, &config);
	// printf("%d\n", count_sprite(&data, &config));
	double time = 0;
	double oldTime = 0;

	int img_idx = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Hello world!");
	img_idx = input_newimage(&data, mlx_new_image(data.mlx, WIDTH, HEIGHT));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, "./srcs/item/redbrick.xpm", &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	img_idx = input_newimage(&data, mlx_xpm_file_to_image(data.mlx, "./srcs/item/pillar.xpm", &data.imgdata[img_idx].width, &data.imgdata[img_idx].height));
	// img_idx = input_newimage(&data, mlx_new_image(data.mlx, WIDTH, HEIGHT));

	/*pixel 찍는 방법*/
	// my_mlx_pixel_put(&data.imgdata[0], WIDTH/4, HEIGHT/2, 0xffffff);
	// mlx_put_image_to_window(data.mlx, data.win, data.imgdata[0].img, 0, 0);
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_loop_hook(data.mlx, ray_casting2, &data);
	mlx_hook(data.win, 17, 0, shut_down, &data);

	/*event코드가 겹치면 안되는 거 같다.*/
	// mlx_hook(data.win, 2, 0, pos_moving, &data);
	// mlx_hook(data.win, 2, 0, dir_rotating, &data);
	mlx_loop(data.mlx);
	return (1);
}
