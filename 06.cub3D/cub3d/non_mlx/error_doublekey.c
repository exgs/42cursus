/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_doublekey.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:35:00 by yunslee           #+#    #+#             */
/*   Updated: 2020/12/29 18:57:32 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int	error_specifier_judge(char *config_oneline, short *flag)
{
	if (ft_strncmp(config_oneline, "R ", 2) == 0)
	{
		if (((*flag) & 1) == 1)
			return (0);
		*flag = *flag + 1;
	}
	else if (ft_strncmp(config_oneline, "NO", 2) == 0)
	{
		if (((*flag) & (1 << 1)) == (1 << 1))
			return (0);
		*flag = *flag + (1 << 1);
	}
	else if (ft_strncmp(config_oneline, "SO", 2) == 0)
	{
		if (((*flag) & (1 << 2)) == (1 << 2))
			return (0);
		*flag = *flag + (1 << 2);
	}
	if (error_specifier_judge2(config_oneline, flag) == 0)
		return (0);
	return (1);
}

int	error_specifier_judge2(char *config_oneline, short *flag)
{
	if (ft_strncmp(config_oneline, "WE", 2) == 0)
	{
		if (((*flag) & (1 << 3)) == (1 << 3))
			return (0);
		*flag = *flag + (1 << 3);
	}
	else if (ft_strncmp(config_oneline, "EA", 2) == 0)
	{
		if (((*flag) & (1 << 4)) == (1 << 4))
			return (0);
		*flag = *flag + (1 << 4);
	}
	else if (ft_strncmp(config_oneline, "S ", 2) == 0)
	{
		if (((*flag) & (1 << 5)) == (1 << 5))
			return (0);
		*flag = *flag + (1 << 5);
	}
	if (error_specifier_judge3(config_oneline, flag) == 0)
		return (0);
	return (1);
}

int	error_specifier_judge3(char *config_oneline, short *flag)
{
	if (ft_strncmp(config_oneline, "F ", 2) == 0)
	{
		if (((*flag) & (1 << 6)) == (1 << 6))
			return (0);
		*flag = *flag + (1 << 6);
	}
	else if (ft_strncmp(config_oneline, "C ", 2) == 0)
	{
		if (((*flag) & (1 << 7)) == (1 << 7))
			return (0);
		*flag = *flag + (1 << 7);
	}
	else if (ft_strncmp(config_oneline, "M", 1) == 0)
	{
		if (((*flag) & (1 << 8)) == (1 << 8))
			return (0);
		*flag = *flag + (1 << 8);
		if (*flag + 1 != 1 << 9)
			return (0);
	}
	return (1);
}

int	error_specifier_double(char **config_lines, t_config *configs)
{
	int		i;
	short	flag;

	i = 0;
	flag = 0;
	while (config_lines[i] != NULL)
	{
		if (error_specifier_judge(config_lines[i], &flag) == 0)
			return (0);
		i++;
	}
	return (1);
}
