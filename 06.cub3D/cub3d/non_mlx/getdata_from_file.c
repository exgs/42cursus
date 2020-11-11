#include "non_mlx.h"

int extract_configs(char **config_lines, t_config *configs)
{
	int i;
	int j;
	char *config_oneline;
	int map_start;
	
	i = 0;
	j = 0;
	while (config_lines[i] != NULL)
	{
		config_oneline = config_lines[i];
		if (extract_config1(config_oneline, configs) == 0
			|| extract_config2(config_oneline, configs) == 0)
			return (0);
		if (config_lines[i][j] == 'M')
		{
			map_start = i + 1;
			if (extract_map_data(config_lines, configs, map_start) == 0)
				return (0);
			return (1);
		}
		i++;
	}
	return (1);
}

int extract_config2(char *config_oneline, t_config *configs)
{
	if (config_oneline[0] == 'W')
	{
		if (extract_west_texture(config_oneline, configs) == 0)
			return (0);
	}
	else if (config_oneline[0] == 'E')
	{
		if (extract_east_texture(config_oneline, configs) == 0)
			return (0);
	}
	else if (config_oneline[0] == 'F')
	{
		if (extract_floor_color(config_oneline, configs) == 0)
			return (0);
	}
	else if (config_oneline[0] == 'C')
	{
		if (extract_ceiling_color(config_oneline, configs) == 0)
			return (0);
	}
	return (1);
}


int extract_config1(char *config_oneline, t_config *configs)
{
	if (config_oneline[0] == 'R')
	{
		if (extract_resolution(config_oneline, configs) == 0)
			return 0;
	}
	else if (config_oneline[0] == 'N')
	{
		if (extract_north_texture(config_oneline, configs) == 0)
			return 0;
	}
	else if (config_oneline[0] == 'S')
	{
		if (config_oneline[1] == 'O')
		{
			if (extract_south_texture(config_oneline, configs) == 0)
				return (0);
		}
		else
		{
			if (extract_sprite_texture(config_oneline, configs) == 0)
				return (0);
		}
	}
	return (1);
}
