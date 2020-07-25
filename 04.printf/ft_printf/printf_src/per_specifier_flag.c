/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_specifier_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:12:32 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 16:12:44 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		per_flag_nostar(t_flag *flag, va_list *ap)
{
	int width_space;
	int len;

	len = 0;
	per_width_space(flag, &width_space, &len);
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	if (flag->d_left == 1 && flag->d_zero == 1)
		flag->d_zero = 0;
	if (flag->d_left == 1)
		write(1, "%", 1);
	if (flag->d_zero != 1)
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	else if (flag->d_zero == 1)
	{
		while (width_space-- > 0)
			write(1, "0", 1);
	}
	if (flag->d_left == 0)
		write(1, "%", 1);
	return (len + 1);
}

int		per_flag_onestar(t_flag *flag, va_list *ap)
{
	int width_space;
	int len;

	len = 0;
	onestar_replace(flag, ap);
	per_width_space(flag, &width_space, &len);
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	if (flag->d_left == 1 && flag->d_zero == 1)
		flag->d_zero = 0;
	if (flag->d_left == 1)
		write(1, "%", 1);
	if (flag->d_zero != 1)
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	else if (flag->d_zero == 1)
	{
		while (width_space-- > 0)
			write(1, "0", 1);
	}
	if (flag->d_left == 0)
		write(1, "%", 1);
	return (len + 1);
}

int		per_flag_twostar(t_flag *flag, va_list *ap)
{
	int width_space;
	int len;

	len = 0;
	twostar_replace(flag, ap);
	per_width_space(flag, &width_space, &len);
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	if (flag->d_left == 1 && flag->d_zero == 1)
		flag->d_zero = 0;
	if (flag->d_left == 1)
		write(1, "%", 1);
	if (flag->d_zero != 1)
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	else if (flag->d_zero == 1)
	{
		while (width_space-- > 0)
			write(1, "0", 1);
	}
	if (flag->d_left == 0)
		write(1, "%", 1);
	return (len + 1);
}

void	per_width_space(t_flag *flag, int *width_space, int *len)
{
	if (flag->d_width == 0)
		*width_space = 0;
	else
		*width_space = flag->d_width - 1;
	if (*width_space >= 0)
		*len = *width_space;
	else
		*len = 0;
	return ;
}
