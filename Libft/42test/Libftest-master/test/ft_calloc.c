/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 19:22:48 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/08 20:50:04 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	char	*output;
	size_t	i;

	output = malloc(number * size);
	i = 0;
	while (i < (number * size))
	{
		output[i] = 0;
		i++;
	}
	return (output);
}
