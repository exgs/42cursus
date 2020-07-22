/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxX%_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:17:12 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/13 22:25:23 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void x_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	char hexa_table[16];

	charge_hexa_table(hexa_table, LOWERCASE);
	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	if (flag.d_zero == 1 && flag.d_left == 1)
		flag.d_zero = 0;
	if (flag.d_star_sum == 0)
		x_flag_nostar(&flag, hexa_table, ap);
	else if (flag.d_star_sum == 1)
		x_flag_onestar(&flag, hexa_table, ap);
	else
		x_flag_twostar(&flag, hexa_table, ap);
	return ;
}

void X_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	char hexa_table[16];

	charge_hexa_table(hexa_table, UPPERCASE);
	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	if (flag.d_zero == 1 && flag.d_left == 1)
		flag.d_zero = 0;
	if (flag.d_star_sum == 0)
		x_flag_nostar(&flag, hexa_table, ap);
	else if (flag.d_star_sum == 1)
		x_flag_onestar(&flag, hexa_table, ap);
	else
		x_flag_twostar(&flag, hexa_table, ap);
	return ;
}

void p_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	char hexa_table[16];

	charge_hexa_table(hexa_table, LOWERCASE);
	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);

	if (flag.d_star_sum == 0)
		p_flag_nostar(&flag, hexa_table, ap);
	else if (flag.d_star_sum == 1)
		p_flag_onestar(&flag, hexa_table, ap);
	return ;
}

void percent_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;

	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	if (flag.d_star_sum == 0)
		percent_flag_nostar(&flag, ap);
	else if (flag.d_star_sum == 1)
		percent_flag_onestar(&flag, ap);
	else
		percent_flag_twostar(&flag, ap);
	return ;
}
