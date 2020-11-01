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

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 500, 500, "hi");
	void *img1;
	int get_width;
	int get_height;
	int bit_per_pixel;
	int size_line;
	int endian;
	t_image img_data;
	img1 = mlx_xpm_file_to_image(mlx, "./srcs/item/goodbye.xpm", &get_width, &get_height);
	img_data.addr = mlx_get_data_addr(img1, &bit_per_pixel, &size_line, &endian);
	img_data.bits_per_pixel = bit_per_pixel;
	img_data.size_line = size_line;
	img_data.endian = endian;
	my_mlx_pixel_put(&img_data, 100, 100, 0x002202);
	unsigned int b = my_mlx_pixel_get(&img_data, 100, 100);
	printf("get color from image : %x\n", b);
	printf("%u dd\n", b);
	printf("%d %d", get_width, get_height);
	printf("%s\n", "soso");
	mlx_put_image_to_window(mlx,win, img1, 20,40);
	mlx_loop(mlx);

	return (0);
}
