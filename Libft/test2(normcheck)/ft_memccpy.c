/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:47:34 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/10 03:56:52 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned int	i;
	char			*str1;
	const char		*str2;

	str1 = (char *)dst;
	str2 = (const char *)src;
	i = 0;
	while (i < len)
	{
		*str1 = str2[i];
		if (*str1 == (unsigned char)c)
			return (++str1);
		str1++;
		i++;
	}
	return (NULL);
}
