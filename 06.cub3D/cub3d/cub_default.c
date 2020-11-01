#include "cub_default.h"

void	my_mlx_pixel_put(t_image *imgdata, int x, int y, int color)
{
    char    *dst;

    dst = imgdata->addr + (y * imgdata->size_line + x * (imgdata->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
	return ;
}

unsigned int	my_mlx_pixel_get(t_image *imgdata, int x, int y)
{
    char			*dst;
	unsigned int	color;
    dst = imgdata->addr + (y * imgdata->size_line + x * (imgdata->bits_per_pixel / 8));
    color = *(unsigned int*)dst;
	return color;
}
