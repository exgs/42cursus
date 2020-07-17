/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csdiu_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:48:15 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/18 01:04:06 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void c_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	
	ft_memset(&flag, 0, sizeof(t_flag));
	flag_decision(str_tag, &flag);
	if (flag.dot > 0 || flag.zero > 0 || flag.star > 2)
		c_print_normal(&flag, ap);
	else
		c_flag_unnormal(str_tag, &flag, ap);
	return ;
}

void s_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	t_data data;

	ft_memset(&flag, 0 ,sizeof(t_flag));
	ft_memset(&data, 0 ,sizeof(t_data));
	flag_decision(str_tag, &flag);
	if (flag.dot == 1 && flag.star == 1)
	{
		data.precision = flag_return_atoi(str_tag);
	}
	if (flag.dot > 1 || flag.zero > 0 || flag.star > 2)
		s_print_normal(&flag, ap);
	else
		s_flag_unnormal(str_tag, &flag, ap);
	return ;
}

void d_specifier(char *str_tag, va_list *ap)
{
	int integer;
	char *str;
	
	integer = va_arg(*ap, int);
	str = ft_itoa(integer);
	ft_putstr_fd(str, 1);
	free(str);
	return ;	
}

void i_specifier(char *str_tag, va_list *ap)
{
	int integer;
	char *str;
	
	integer = va_arg(*ap, int);
	str = ft_itoa(integer);
	ft_putstr_fd(str, 1);
	free(str);
	return ;
}

void u_specifier(char *str_tag, va_list *ap)
{
	int integer;
	char *str;

	integer = va_arg(*ap, unsigned int); //bit 값을 복사하는것 뿐이라서.. i,d 와는 다른프로세스를 거쳐야함
	str = ft_utoa(integer);
	ft_putstr_fd(str, 1);
	free(str);
	return ;
}
