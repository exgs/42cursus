/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pxX%_specifier_sub.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:53:41 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/13 22:24:35 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void charge_hex_array(char *array, char flag)
{
	int i;
	int j;

	if (array == NULL)
		return ;
	i = 0;
	j = 0;
	while (i < 10)
	{
		array[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		if (flag == UPPERCASE)
			array[i] = j + 'A';
		else
			array[i] = j + 'a';
		i++;
		j++;
	}
	return ;
}

void write_deical_to_hex(unsigned int n, char *hex_array, int num)
{
	int remainder;
	
	if (n == 0 && num == 0)
		return ;
	else if (n == 0 && num != 0)
	{
		write(1, "0", 1);
		write_deical_to_hex(n, hex_array, --num);
		return ;
	}
	remainder = n % 16;
	write_deical_to_hex(n / 16, hex_array, --num);
	write(1, &hex_array[remainder], 1);
	return ;
}
