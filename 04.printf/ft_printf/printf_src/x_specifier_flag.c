/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_specifier_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:26:08 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 16:26:09 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_flag_nostar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int	hexa_value;
	char				*hexa_str;
	int					len;

	if (flag->d_zero == 1 && flag->d_left == 1)
		flag->d_zero = 0;
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	hexa_value = va_arg(*ap, unsigned int);
	hexa_str = return_hexa_str(hexa_value, hex_table);
	len = ft_strlen(hexa_str);
	if (flag->d_precision >= flag->d_width && flag->d_precision >= len)
		len = x_flag_precision_most(flag, hexa_str);
	else if (flag->d_width >= flag->d_precision && flag->d_width >= len)
		len = x_flag_width_most(flag, hexa_str);
	else
		len = x_flag_strlen_most(flag, hexa_str);
	free(hexa_str);
	return (len);
}

int	x_flag_onestar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int	hexa_value;
	char				*hexa_str;
	int					len;

	onestar_replace(flag, ap);
	if (flag->d_zero == 1 && flag->d_left == 1)
		flag->d_zero = 0;
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	hexa_value = va_arg(*ap, unsigned int);
	hexa_str = return_hexa_str(hexa_value, hex_table);
	len = ft_strlen(hexa_str);
	if (flag->d_precision >= flag->d_width && flag->d_precision >= len)
		len = x_flag_precision_most(flag, hexa_str);
	else if (flag->d_width >= flag->d_precision && flag->d_width >= len)
		len = x_flag_width_most(flag, hexa_str);
	else
		len = x_flag_strlen_most(flag, hexa_str);
	free(hexa_str);
	return (len);
}

int	x_flag_twostar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int	hexa_value;
	char				*hexa_str;
	int					len;

	twostar_replace(flag, ap);
	if (flag->d_zero == 1 && flag->d_left == 1)
		flag->d_zero = 0;
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	hexa_value = va_arg(*ap, unsigned int);
	hexa_str = return_hexa_str(hexa_value, hex_table);
	len = ft_strlen(hexa_str);
	if (flag->d_precision >= flag->d_width && flag->d_precision >= len)
		len = x_flag_precision_most(flag, hexa_str);
	else if (flag->d_width >= flag->d_precision && flag->d_width >= len)
		len = x_flag_width_most(flag, hexa_str);
	else
		len = x_flag_strlen_most(flag, hexa_str);
	free(hexa_str);
	return (len);
}
