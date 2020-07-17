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

void c_print_normal(t_flag *flag, va_list *ap)
{
	char c;
	
	while (flag->star > 0)
	{
		c = (char)va_arg(*ap, int);
		flag->star--;
	}
	c = (char)va_arg(*ap, int);
	write(1, &c, 1);
	return ;
}

void c_flag_unnormal(char *str, t_flag *flag, va_list *ap)
{
	char c;
	int count;

	if (flag->minus == 1)
	{
		c_flag_minus(str, flag, ap);
		return ;
	}
	if (flag->star == 1)
	{
		count = (int)va_arg(*ap, int);
		count--;
		while (count-- > 0)
			write(1," ", 1);
	}
	else
		flag_printspace(str);
	c = va_arg(*ap, int);
	write(1, &c, 1);
	return ;
}

void c_flag_minus(char*str, t_flag *flag, va_list *ap)//앞선 가정에서 star가 1개인경우만
{
	char c;
	int count;

	if (flag->star == 1)
	{
		count = (int)va_arg(*ap, int);
		c = (char)va_arg(*ap, int);
		write(1, &c, 1);
		count = count - 1;//문자 갯수 하나 빼기
		while (count--> 0)
			write(1, " ", 1);
	}
	else
	{
		c = (char)va_arg(*ap, int);
		write(1, &c, 1);
		flag_printspace(str);
	}
	return ;
}
