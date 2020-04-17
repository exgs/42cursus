/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:47:34 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/29 18:47:34 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_memccpy(void *dst, const void *src, int c, size_t len)
{
    unsigned int i;
    char * str1;
    const char * str2;

    str1 = (char *)dst;
    str2 = (const char *)src;
    i = 0;
    while (i < len)
    {
        if (str2[i] == (unsigned char)c)
        {
            str1[i] = str2[i];
            return (str1);
        }
        str1[i] = str2[i];
        i++;
    }
    return (str1);
}
