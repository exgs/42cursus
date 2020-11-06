#include "mlx_loop_hook.h"

int		count_sprite(struct s_data *data, struct s_config *config)
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
				data->spritedata[count].texture = map[i][j] + 3;
				count +=1;
			}
			j++;
		}
		i++;
	}
	data->sprite_num = count;
	return count;
}

void	sort_order(struct s_pair *orders, int amount)
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

void	sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;

	sprites = (t_pair*)malloc(sizeof(t_pair) * amount);
	for (int i = 0; i < amount; i++)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, amount);
	for (int i = 0; i < amount; i++)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}
