/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csdiu_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:48:15 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/13 21:25:27 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void c_specifier(char *s, va_list *ap)
{
	char c;
	// printf("---\n");
	c = (char)va_arg(*ap, int);
	write(1, &c, 1);
	return ;
}

void s_specifier(char *s, va_list *ap)
{
	char *str;

	str = (char *)va_arg(*ap, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	ft_putstr_fd(str, 1);
	return ;
}

void d_specifier(char *s, va_list *ap)
{
	int integer;
	char *str;
	
	integer = va_arg(*ap, int);
	str = ft_itoa(integer);
	ft_putstr_fd(str, 1);
	free(str);
	return ;	
}

void i_specifier(char *s, va_list *ap)
{
	int integer;
	char *str;
	
	integer = va_arg(*ap, int);
	str = ft_itoa(integer);
	ft_putstr_fd(str, 1);
	free(str);
	return ;
}

void u_specifier(char *s, va_list *ap)
{
	int integer;
	char *str;

	integer = va_arg(*ap, unsigned int); //bit 값을 복사하는것 뿐이라서.. i,d 와는 다른프로세스를 거쳐야함
	str = ft_utoa(integer);
	ft_putstr_fd(str, 1);
	free(str);
	return ;
}
