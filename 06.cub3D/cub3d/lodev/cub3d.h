#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include "./opengl/mlx.h"

# define X 0
# define Y 1
typedef struct s_setting
{
	double pos[2];
	double dir[2];
	double plane[2];
	double time; //time of current frame
	double oldTime; //time of previous frame
}				t_setting;

typedef struct s_ray
{
	double interval;
	double Dir[2];
	double Dir_one[2];
	double pos[2];
	double map[2];
	double sideDist[2];
	double deltaDist[2];
	double perpWallDist[2];
	double fishDist[2];
	double verticalDist[2];
}				t_raydata;

typedef struct s_dot
{
	double pos[2];
	double map[2];
	double step[2];
}				t_dot;

typedef struct s_ptr
{
	double pos[2];
	void *mlx;
	void *win;
	void *img;
	int width;
	int height;
	// int bits_per_pixel;
	// int size_line;
	// int endian;
}				t_ptr;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef char ColorRGB;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
