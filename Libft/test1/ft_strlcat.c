/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:43:51 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/26 15:43:51 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strlcat(char* dst, char* src, size_t dstsize)
{
    unsigned int i;
    unsigned int j;
    unsigned int dst_len;
    unsigned int src_len;

    dst_len = 0;
    src_len = 0;
    i = 0;
    while (dst[i++])
        dst_len++;
    i = 0;
    while (src[i++])
        src_len++;
    i = 0;
    j = 0;
    while (i < dstsize - 1)
    {
        if (i < dst_len - 1)
        {
            i++;
            continue;
        }
        dst[i] = src[j];
        j++;
        i++;
    }
    dst[i] = '\0';
    return (dst_len + src_len);
}
