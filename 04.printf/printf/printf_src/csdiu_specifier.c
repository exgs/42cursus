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

	// printf("%s\n",str_tag);
	ft_memset(&flag, 0, sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);

	if (flag.d_star_sum == 0)
		c_flag_nostar(&flag, ap);
	else if (flag.d_star_sum == 1)
		c_flag_onestar(&flag, ap);
	else
		c_flag_twostar(&flag, ap);
	return ;
}

void s_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;

	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);

	if (flag.d_star_sum == 0)
		s_flag_nostar(&flag, ap);
	else if (flag.d_star_sum == 1)
		s_flag_onestar(&flag, ap);
	else
		s_flag_twostar(&flag, ap);
	return ;
}

void d_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;

	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	// printf("check\n");
	if (flag.d_left == 1 && flag.d_zero == 1)
		flag.d_zero = 0;
	if (flag.d_star_sum == 0)
		d_flag_nostar(&flag, ap, 1);
	else if (flag.d_star_sum == 1)
		d_flag_onestar(&flag, ap, 1);
	else
		d_flag_twostar(&flag, ap, 1);
	return ;
}

void i_specifier(char *str_tag, va_list *ap)
{
	d_specifier(str_tag, ap);
	return ;
}

void u_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;

	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	// printf("check\n");
	if (flag.d_left == 1 && flag.d_zero == 1)
		flag.d_zero = 0;
	if (flag.d_star_sum == 0)
		d_flag_nostar(&flag, ap, 0);
	else if (flag.d_star_sum == 1)
		d_flag_onestar(&flag, ap, 0);
	else
		d_flag_twostar(&flag, ap, 0);
	return ;
}
