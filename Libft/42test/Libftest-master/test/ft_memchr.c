/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:44:09 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/10 02:53:43 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char*)b;
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == (unsigned int)c)
			return (str + i);
		i++;
	}
	return (NULL);
}
