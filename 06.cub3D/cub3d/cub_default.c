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

int count_sprite(t_data *data, struct s_config *config)
{
	char **map = data->map;
	int i = 0;
	int j = 0;
	int count = 0;
	if (data == NULL || map[i] == NULL)
		return (-1);
	while (map[i] != NULL)
	{
		j = 0;
		while (j < config->map_column)
		{
			if (map[i][j] > 1 && map[i][j] < 9)
			{
				data->spritedata[count].x = i + 0.5;
				data->spritedata[count].y = j + 0.5;
				data->spritedata[count].texture = map[i][j];
				count +=1;
			}
			j++;
		}
		i++;
	}
	data->sprite_num = count;
	return count;
}



static int	compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return (1);
	else if (*(int *)first < *(int *)second)
		return (-1);
	else
		return (0);
}

void	sort_order(t_pair *orders, int amount)
{
	t_pair	tmp;

	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < amount - 1; j++)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

void	sortSprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;

	//std::vector<std::pair<double, int>> sprites(amount);
	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	//std::sort(sprites.begin(), sprites.end());
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}
