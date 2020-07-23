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

int	c_flag_nostar(t_flag *flag, va_list *ap)
{
	char c;
	int temp;
	int len;

	len = 0;
	// printf("I'm nostar\n");
	c = (char)va_arg(*ap, int);
	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((flag->d_width - 1) > 0)
	{
		temp = flag->d_width -1;
		len = temp;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	if (flag->d_left == 0)
		write(1, &c , 1);
	return (len + 1);
}

int	c_flag_onestar(t_flag *flag, va_list *ap)
{
	char c;
	int temp;
	int len;

	len = 0;
	// printf("I'm onestar\n");
	onestar_replace(flag, ap);
	c = (char)va_arg(*ap, int);

	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((temp = flag->d_width -1) > 0)
	{
		len = temp;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	// printf("flag->d_left : %d\n",flag->d_left);
	if (flag->d_left == 0)
		write(1, &c , 1);
	return (len + 1);
}

int	c_flag_twostar(t_flag *flag, va_list *ap)
{
	char c;
	int temp;
	int len;
	twostar_replace(flag, ap);
	c = (char)va_arg(*ap, int);

	if (flag->d_left == 1)
		write(1, &c, 1);
	if ((flag->d_width - 1) > 0)
	{
		temp = flag->d_width -1;
		len = temp;
		while (temp > 0)
		{
			write(1, " ", 1);
			temp--;
		}
	}
	if (flag->d_left == 0)
		write(1, &c , 1);
	return (len + 1);
}
