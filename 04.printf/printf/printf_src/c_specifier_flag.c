/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 02:21:27 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/17 17:39:20 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void c_flag_nostar(t_flag *flag, va_list *ap)
{
	char c;
	int temp;
	// printf("I'm nostar\n");
	c = (char)va_arg(*ap, int);
	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((flag->d_width - 1) > 0)
	{
		temp = flag->d_width -1;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	if (flag->d_left == 0)
		write(1, &c , 1);
	return ;
}

void c_flag_onestar(t_flag *flag, va_list *ap)
{
	char c;
	int temp;
	// printf("I'm onestar\n");
	if (flag->d_dot == 1)
		flag->d_precision = (int)va_arg(*ap, int);
	else
		flag->d_width = (int)va_arg(*ap, int);
	c = (char)va_arg(*ap, int);

	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((flag->d_width - 1) > 0)
	{
		temp = flag->d_width -1;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	// printf("flag->d_left : %d\n",flag->d_left);
	if (flag->d_left == 0)
		write(1, &c , 1);
	return ;
}

void c_flag_twostar(t_flag *flag, va_list *ap)
{
	char c;
	int temp;
	// printf("I'm twostar\n");
	flag->d_width = (int)va_arg(*ap, int);
	flag->d_precision = (int)va_arg(*ap, int);
	c = (char)va_arg(*ap, int);

	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((flag->d_width - 1) > 0)
	{
		temp = flag->d_width -1;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	if (flag->d_left == 0)
		write(1, &c , 1);
	return ;
}
