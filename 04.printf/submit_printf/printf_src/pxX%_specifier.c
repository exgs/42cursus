/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxX%_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:17:12 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/10 21:50:35 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_specifier(char *s, va_list *ap)
{
	unsigned int memeory;
	char hex_array[16];

	charge_hex_array(hex_array, LOWERCASE);
	memeory = (unsigned int)va_arg(*ap, char *);
	write_deical_to_hex(memeory, hex_array);
	return ;
}

void X_specifier(char *s, va_list *ap)
{
	unsigned int memeory;
	char hex_array[16];

	charge_hex_array(hex_array, UPPERCASE);
	memeory = (unsigned int)va_arg(*ap, char *);
	write_deical_to_hex(memeory, hex_array);
	return ;
}

void p_specifier(char *s, va_list *ap)
{
	unsigned int memeory;
	char hex_array[16];
	
	write(1, "0", 1);
	//write(1, "0", 1); window 4byte
	write(1, "x", 1); // 6byte
	
	charge_hex_array(hex_array, UPPERCASE);
	memeory = (unsigned int)va_arg(*ap, char *);
	write_deical_to_hex(memeory, hex_array);
	/*p 주소 값계산할 때 앞에 00 붙는 이슈에 대해서...*/
	return ;
}

void percent_specifier(char *s, va_list *ap)
{
	write(1, ap, 0);
	write(1, "%", 1);
	return ;
}