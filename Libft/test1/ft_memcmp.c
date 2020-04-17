/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 23:12:03 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/28 23:12:03 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_memcmp(const void *b1, const void *b2, size_t len)
{
    unsigned char *str1;
    unsigned char *str2;
    unsigned int i;
    str1 =(unsigned char *)b1;
    str2 =(unsigned char *)b2;
    i = 0;

    while ((str1[i] || str2[i]) && i < len)
    {
        if (str1[i] != str2[i])
        {
            return (str1[i]-str2[i]);
        }
        i++;
    }
    return (0);
}
