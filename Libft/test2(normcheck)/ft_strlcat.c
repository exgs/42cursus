/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:43:51 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/14 04:17:42 by yunslee          ###   ########.fr       */
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

size_t				ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;
	unsigned int dst_len;
	unsigned int src_len;

	i = 0;
	j = 0;
	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[j] != '\0')
	{
		if (i < dst_len)
		{
			i++;
			continue;
		}
		dest[i++] = src[j++];
	}
	if (size > dst_len) //return 값이 나뉜다는 게 이해가안되며, unix설명서에도 안적혀있다.
	{
		if (src[0] != '\0')
			dest[i] = '\0';
		return (src_len + dst_len);
	}
	else
		return (src_len + size);
}
