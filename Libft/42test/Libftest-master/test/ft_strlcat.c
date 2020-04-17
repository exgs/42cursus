/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:43:51 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/10 02:54:28 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int i;
	unsigned int j;
	unsigned int dst_len;
	unsigned int src_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	while (i < dstsize - 1)
	{
		if (i < dst_len - 1)
		{
			i++;
			continue;
		}
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}
