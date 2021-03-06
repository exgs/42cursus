/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getdata_num_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:19:11 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/15 15:03:21 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "non_mlx.h"

int			flush_string(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("string is NULL(flush)\n", 1);
		return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == ',' || str[i] == '.' ||
					str[i] == '/' || str[i] == ' ')
				str[i] = ' ';
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	atoi_while_cub(const char *str, int i, int sign, int *idx)
{
	unsigned long long int	sum;

	sum = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		sum *= 10;
		sum += str[i] - 48;
		i++;
	}
	*idx += i;
	return ((int)sum);
}

int			ft_atoi_cub(const char *str, int *idx)
{
	int i;
	int sign;
	int value;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	value = sign * atoi_while_cub(str, i, sign, idx);
	return (value);
}
