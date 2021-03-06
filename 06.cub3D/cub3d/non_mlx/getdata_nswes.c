/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_nswes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:18:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 12:40:27 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int	extract_north_texture(char *str, t_config *configs)
{
	if (ft_strchr(str, ' ') == NULL)
		return (0);
	ft_strlcpy(configs->north_texture, ft_strchr(str, ' ') + 1, STRING_LENGTH);
	if (configs->north_texture[0] == '\0')
	{
		ft_putstr_fd("Error : NO\n", 1);
		return (0);
	}
	else
		return (1);
}

int	extract_south_texture(char *str, t_config *configs)
{
	if (ft_strchr(str, ' ') == NULL)
		return (0);
	ft_strlcpy(configs->south_texture, ft_strchr(str, ' ') + 1, STRING_LENGTH);
	if (configs->south_texture[0] == '\0')
	{
		ft_putstr_fd("Error : SO\n", 1);
		return (0);
	}
	else
		return (1);
}

int	extract_west_texture(char *str, t_config *configs)
{
	if (ft_strchr(str, ' ') == NULL)
		return (0);
	ft_strlcpy(configs->west_texture, ft_strchr(str, ' ') + 1, STRING_LENGTH);
	if (configs->west_texture[0] == '\0')
	{
		ft_putstr_fd("Error : WE\n", 1);
		return (0);
	}
	else
		return (1);
}

int	extract_east_texture(char *str, t_config *configs)
{
	if (ft_strchr(str, ' ') == NULL)
		return (0);
	ft_strlcpy(configs->east_texture, ft_strchr(str, ' ') + 1, STRING_LENGTH);
	if (configs->east_texture[0] == '\0')
	{
		ft_putstr_fd("Error : EA\n", 1);
		return (0);
	}
	else
		return (1);
}

int	extract_sprite_texture(char *str, t_config *configs)
{
	if (ft_strchr(str, ' ') == NULL)
		return (0);
	ft_strlcpy(configs->sprite_texture, ft_strchr(str, ' ') + 1,
				STRING_LENGTH);
	if (configs->sprite_texture[0] == '\0')
	{
		ft_putstr_fd("Error : S\n", 1);
		return (0);
	}
	else
		return (1);
}
