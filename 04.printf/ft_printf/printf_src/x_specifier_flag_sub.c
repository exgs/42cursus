/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_specifier_flag_sub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:27:32 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 16:29:26 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_flag_precision_most(t_flag *flag, char *hexa_str)
{
	int precision_zero;
	int len;

	len = flag->d_precision;
	precision_zero = flag->d_precision - ft_strlen(hexa_str);
	while (precision_zero-- > 0)
		write(1, "0", 1);
	if (flag->d_dot != 1 || flag->d_precision != 0 || hexa_str[0] != '0')
		ft_putstr_fd(hexa_str, 1);
	else
		len--;
	return (len);
}

int		x_flag_strlen_most(t_flag *flag, char *hexa_str)
{
	int len;

	len = ft_strlen(hexa_str);
	if (flag->d_dot != 1 || flag->d_precision != 0 || hexa_str[0] != '0')
		ft_putstr_fd(hexa_str, 1);
	else
		len--;
	return (len);
}

int		x_flag_width_most(t_flag *flag, char *hexa_str)
{
	int precision_zero;
	int width_space;
	int temp;

	precision_zero = flag->d_precision - ft_strlen(hexa_str);
	if (flag->d_precision == -1 || flag->d_precision < ft_strlen(hexa_str))
		width_space = flag->d_width - ft_strlen(hexa_str);
	else
		width_space = flag->d_width - flag->d_precision;
	if (flag->d_left == 1)
		when_x_left_one(hexa_str, flag, precision_zero, width_space);
	else
		when_x_left_zero(hexa_str, flag, precision_zero, width_space);
	return (flag->d_width);
}

void	when_x_left_one(char *hexa_str, t_flag *flag,
							int precision_zero, int width_space)
{
	while (precision_zero-- > 0)
		write(1, "0", 1);
	if (flag->d_dot != 1 || flag->d_precision != 0 || hexa_str[0] != '0')
		ft_putstr_fd(hexa_str, 1);
	else
		width_space++;
	while (width_space-- > 0)
		write(1, " ", 1);
	return ;
}

void	when_x_left_zero(char *hexa_str, t_flag *flag,
						int precision_zero, int width_space)
{
	if (flag->d_dot == 1 && flag->d_precision == 0 && hexa_str[0] == '0')
		width_space++;
	if (flag->d_zero == 0 ||
			(flag->d_zero == 1 && flag->d_dot == 1 && flag->d_precision >= 0))
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_zero == 1 && flag->d_precision <= 0)
	{
		while (width_space-- > 0)
			write(1, "0", 1);
	}
	else if (flag->d_zero == 0 || flag->d_precision > 0)
	{
		while (precision_zero-- > 0)
			write(1, "0", 1);
	}
	if (flag->d_dot != 1 || flag->d_precision != 0 || hexa_str[0] != '0')
		ft_putstr_fd(hexa_str, 1);
	return ;
}
