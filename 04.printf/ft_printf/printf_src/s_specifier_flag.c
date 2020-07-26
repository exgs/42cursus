/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:18:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/26 15:03:34 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char g_null[7] = "(null)";

int	s_flag_nostar(t_flag *flag, va_list *ap)
{
	char	*str;
	int		temp;
	int		len;

	len = 0;
	if (NULL == (str = (char *)va_arg(*ap, char *)))
		str = g_null;
	if (flag->d_precision >= 0 && (int)ft_strlen(str) > flag->d_precision)
		str = ft_substr(str, 0, flag->d_precision);
	if (flag->d_left == 1)
		ft_putstr_fd(str, 1);
	if ((temp = (flag->d_width - ft_strlen(str))) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(str, 1);
	return (len + ft_strlen(str));
}

int	s_flag_onestar(t_flag *flag, va_list *ap)
{
	char	*str;
	int		temp;
	int		len;

	len = 0;
	onestar_replace(flag, ap);
	if (NULL == (str = (char *)va_arg(*ap, char *)))
		str = g_null;
	if (flag->d_precision >= 0 && (int)ft_strlen(str) > flag->d_precision)
		str = ft_substr(str, 0, flag->d_precision);
	if (flag->d_left == 1)
		ft_putstr_fd(str, 1);
	if ((temp = flag->d_width - ft_strlen(str)) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(str, 1);
	if (flag->d_precision >= 0 && (int)ft_strlen(str) > flag->d_precision)
		free(str);
	return (len + ft_strlen(str));
}

int	s_flag_twostar(t_flag *flag, va_list *ap)
{
	char	*str;
	int		temp;
	int		len;

	len = 0;
	twostar_replace(flag, ap);
	if (NULL == (str = (char *)va_arg(*ap, char *)))
		str = g_null;
	if (flag->d_precision >= 0 && (int)ft_strlen(str) > flag->d_precision)
		str = ft_substr(str, 0, flag->d_precision);
	if (flag->d_left == 1)
		ft_putstr_fd(str, 1);
	if ((temp = flag->d_width - ft_strlen(str)) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(str, 1);
	if (flag->d_precision >= 0 && (int)ft_strlen(str) > flag->d_precision)
		free(str);
	return (len + ft_strlen(str));
}
