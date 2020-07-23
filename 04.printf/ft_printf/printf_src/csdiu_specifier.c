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

int c_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	int len;

	// printf("%s\n",str_tag);
	ft_memset(&flag, 0, sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	if (flag.d_precision < 0)
		flag.d_precision = -1;
	if (flag.d_star_sum == 0)
		len = c_flag_nostar(&flag, ap);
	else if (flag.d_star_sum == 1)
		len = c_flag_onestar(&flag, ap);
	else
		len = c_flag_twostar(&flag, ap);
	return (len);
}

int s_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	int len;

	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);

	if (flag.d_star_sum == 0)
		len = s_flag_nostar(&flag, ap);
	else if (flag.d_star_sum == 1)
		len = s_flag_onestar(&flag, ap);
	else
		len = s_flag_twostar(&flag, ap);
	// printf("len : %d\n",len);
	return (len);
}

int d_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	int len;

	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	if (flag.d_precision < 0)
		flag.d_precision = -1;
	// printf("check\n");
	if (flag.d_left == 1 && flag.d_zero == 1)
		flag.d_zero = 0;
	if (flag.d_star_sum == 0)
		len = d_flag_nostar(&flag, ap, 1);
	else if (flag.d_star_sum == 1)
		len = d_flag_onestar(&flag, ap, 1);
	else
		len = d_flag_twostar(&flag, ap, 1);
	return (len);
}

int i_specifier(char *str_tag, va_list *ap)
{
	int len;

	len = d_specifier(str_tag, ap);
	return (len);
}

int u_specifier(char *str_tag, va_list *ap)
{
	t_flag flag;
	int len;

	len = 0;
	ft_memset(&flag, 0 ,sizeof(t_flag));
	flag_decision(str_tag, &flag);
	flag_decision_more(str_tag, &flag);
	// printf("check\n");
	if (flag.d_left == 1 && flag.d_zero == 1)
		flag.d_zero = 0;
	if (flag.d_star_sum == 0)
		len += d_flag_nostar(&flag, ap, 0);
	else if (flag.d_star_sum == 1)
		len += d_flag_onestar(&flag, ap, 0);
	else
		len += d_flag_twostar(&flag, ap, 0);
	return (len);
}
