/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:24:19 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/10 19:52:47 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_utoa_len(unsigned int v)
{
	int i;

	i = 0;
	if (v == 0)
		return (1);
	while (v != 0)
	{
		v /= 10;
		i++;
	}
	return (i);
}

char		*ft_utoa(unsigned int n)
{
	char	*utoa;
	int		utoa_len;
	int		i;
	int		temp;

	i = 1;
	utoa_len = ft_utoa_len(n);
	if (NULL == (utoa = (char *)malloc(sizeof(char) * (utoa_len + 1))))
		return (NULL);
	if (n == 0)
		utoa[0] = '0';
	utoa[utoa_len] = '\0';
	while (n != 0)
	{
		temp = n % 10;
		utoa[utoa_len - i] = temp + '0';
		n /= 10;
		i++;
	}
	return (utoa);
}
