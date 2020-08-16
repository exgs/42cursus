#ifndef CUB_DEFAULT_H
# define CUB_DEFAULT_H

#include "config.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

# define X 0
# define Y 1


typedef struct s_ray{
	double dir[2];
	double plane[2];
}				t_ray;

typedef struct s_object{
	double pos[2]; 
	struct s_ray ray;
}				t_object;

typedef struct s_image{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}				t_image;

typedef struct s_data{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;

	struct s_object obj;
	struct s_image imgdata[10];
}				t_data;


void            my_mlx_pixel_put(t_image *imgdata, int x, int y, int color);

#endif
