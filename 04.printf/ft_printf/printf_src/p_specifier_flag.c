/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:10:10 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 19:40:16 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char g_prefix[3] = {'0', 'x', 0};

int		p_flag_nostar(t_flag *flag, char *hexa_table, va_list *ap)
{
	long unsigned int	address_num;
	char				*address_str;
	int					temp;
	int					len;

	len = 0;
	address_str = return_address_str(flag, ap, hexa_table);
	if (flag->d_left == 1)
		ft_putstr_fd(address_str, 1);
	if ((temp = (flag->d_width - ft_strlen(address_str))) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(address_str, 1);
	len += ft_strlen(address_str);
	free(address_str);
	return (len);
}

int		p_flag_onestar(t_flag *flag, char *hexa_table, va_list *ap)
{
	long unsigned int	address_num;
	char				*address_str;
	int					temp;
	int					len;

	len = 0;
	onestar_replace(flag, ap);
	address_str = return_address_str(flag, ap, hexa_table);
	if (flag->d_left == 1)
		ft_putstr_fd(address_str, 1);
	if ((temp = (flag->d_width - ft_strlen(address_str))) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(address_str, 1);
	len += ft_strlen(address_str);
	free(address_str);
	return (len);
}

int		p_flag_twostar(t_flag *flag, char *hexa_table, va_list *ap)
{
	long unsigned int	address_num;
	char				*address_str;
	int					temp;
	int					len;

	len = 0;
	twostar_replace(flag, ap);
	address_str = return_address_str(flag, ap, hexa_table);
	if (flag->d_left == 1)
		ft_putstr_fd(address_str, 1);
	if ((temp = (flag->d_width - ft_strlen(address_str))) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(address_str, 1);
	len += ft_strlen(address_str);
	free(address_str);
	return (len);
}

char	*return_address_str(t_flag *flag, va_list *ap, char *hexa_table)
{
	long unsigned int	address_num;
	char				*temp_str;
	char				*address_str;

	address_num = va_arg(*ap, long unsigned);
	if (flag->d_dot == 1 && flag->d_precision == 0 && address_num == 0)
	{
		temp_str = ft_strdup("");
		address_str = ft_strjoin(g_prefix, temp_str);
	}
	else
	{
		temp_str = return_hexa_str(address_num, hexa_table);
		address_str = ft_strjoin(g_prefix, temp_str);
	}
	free(temp_str);
	return (address_str);
}
