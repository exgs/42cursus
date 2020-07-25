/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 02:21:27 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 15:25:07 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	c_flag_nostar(t_flag *flag, va_list *ap)
{
	char	c;
	int		temp;
	int		len;

	len = 0;
	c = (char)va_arg(*ap, int);
	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((flag->d_width - 1) > 0)
	{
		temp = flag->d_width - 1;
		len = temp;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	if (flag->d_left == 0)
		write(1, &c, 1);
	return (len + 1);
}

int	c_flag_onestar(t_flag *flag, va_list *ap)
{
	char	c;
	int		temp;
	int		len;

	len = 0;
	onestar_replace(flag, ap);
	c = (char)va_arg(*ap, int);
	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((temp = flag->d_width - 1) > 0)
	{
		len = temp;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	if (flag->d_left == 0)
		write(1, &c, 1);
	return (len + 1);
}

int	c_flag_twostar(t_flag *flag, va_list *ap)
{
	char	c;
	int		temp;
	int		len;

	twostar_replace(flag, ap);
	c = (char)va_arg(*ap, int);
	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((flag->d_width - 1) > 0)
	{
		temp = flag->d_width - 1;
		len = temp;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	if (flag->d_left == 0)
		write(1, &c, 1);
	return (len + 1);
}
