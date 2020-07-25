/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_specifier_flag_sub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:29:06 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 15:33:20 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		d_flag_precision_most(t_flag *flag, char *utoa_str)
{
	int precision_zero;
	int len;

	if (flag->d_minus_sign == 1)
		len = 1 + flag->d_precision;
	else
		len = flag->d_precision;
	precision_zero = flag->d_precision - ft_strlen(utoa_str);
	if (flag->d_minus_sign == 1)
	{
		write(1, "-", 1);
	}
	while (precision_zero-- > 0)
		write(1, "0", 1);
	if (flag->d_dot != 1 || flag->d_precision != 0 || utoa_str[0] != '0')
		ft_putstr_fd(utoa_str, 1);
	else
		len--;
	return (len);
}

int		d_flag_strlen_most(t_flag *flag, char *utoa_str)
{
	int len;

	if (flag->d_minus_sign == 1)
		len = 1 + ft_strlen(utoa_str);
	else
		len = ft_strlen(utoa_str);
	if (flag->d_minus_sign == 1)
	{
		write(1, "-", 1);
	}
	if (flag->d_dot != 1 || flag->d_precision != 0 || utoa_str[0] != '0')
		ft_putstr_fd(utoa_str, 1);
	else
		len--;
	return (len);
}

int		d_flag_width_most(t_flag *flag, char *utoa_str)
{
	int precision_zero_print;
	int width_space;

	precision_zero_print = flag->d_precision - ft_strlen(utoa_str);
	if (flag->d_precision == -1 ||
			(int)(flag->d_precision - (int)ft_strlen(utoa_str)) < 0)
		width_space = flag->d_width - ft_strlen(utoa_str);
	else
		width_space = flag->d_width - flag->d_precision;
	if (flag->d_minus_sign == 1)
		width_space--;
	if (flag->d_left == 1)
		when_d_left_one(utoa_str, flag, precision_zero_print, width_space);
	else
		when_d_left_zero(utoa_str, flag, precision_zero_print, width_space);
	return (flag->d_width);
}

void	when_d_left_one(char *utoa_str, t_flag *flag,
						int precision_zero, int width_space)
{
	if (flag->d_minus_sign == 1)
		write(1, "-", 1);
	while (precision_zero-- > 0)
		write(1, "0", 1);
	if (flag->d_dot != 1 || flag->d_precision != 0 || utoa_str[0] != '0')
		ft_putstr_fd(utoa_str, 1);
	else
		width_space++;
	while (width_space-- > 0)
		write(1, " ", 1);
	return ;
}

void	when_d_left_zero(char *utoa_str, t_flag *flag,
							int precision_zero, int width_space)
{
	if (flag->d_dot == 1 && flag->d_precision == 0 && utoa_str[0] == '0')
		width_space++;
	if (flag->d_zero == 0 ||
			(flag->d_zero == 1 && flag->d_dot == 1 && flag->d_precision >= 0))
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_minus_sign == 1)
		write(1, "-", 1);
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
	if (flag->d_dot != 1 || flag->d_precision != 0 || utoa_str[0] != '0')
		ft_putstr_fd(utoa_str, 1);
	return ;
}
