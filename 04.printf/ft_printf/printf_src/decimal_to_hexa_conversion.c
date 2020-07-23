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

void	charge_hexa_table(char *array, char flag)
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

void	charge_hexa_str(long unsigned int n, char *hexa_str,
							int hexa_size, char *table)
{
	int	remainder;

	if (n == 0 && hexa_size == 0)//hexa_size가 추가되어야 NULL처리가 가능
		return ;
	remainder = n % 16;
	hexa_str[hexa_size - 1] = table[remainder];
	charge_hexa_str(n / 16, hexa_str, --hexa_size, table);
}

char	*return_hexa_str(long unsigned int value, char *hexa_table)
{
	char *address;
	int size;
	int remainder;
	char *strdup;
	size = hexa_size(value);
	address = malloc(sizeof(char) * size + 1);
	// printf("printf %%lx : %lx\n", value);
	// printf("address_size : %d\n", size);
	address[size] = '\0';
	charge_hexa_str(value, address, size, hexa_table);
	strdup = ft_strdup(address);
	// printf("address : %s\n", address);
	// printf("strdup : %s\n", strdup);
	free(address);
	return (strdup);
}

int		hexa_size(long unsigned int address)
{
	int size;

	size = 0;
	if (address == 0)
		return (1);
	while (address != 0)
	{
		address /= 16;
		size++;
	}
	return (size);
}
