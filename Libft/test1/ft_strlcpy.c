/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:42:07 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/26 14:42:07 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strlcpy(char* dst, char* src,size_t dstsize)
{
    unsigned int i;
    unsigned int src_len;

    i = 0;
    src_len = 0;
    while (src[i])
    {
         src_len++;
         i++;
    }
    i = 0;
    while (src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (src_len);    
}
