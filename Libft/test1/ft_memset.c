/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:33:56 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/29 19:33:56 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void *ft_memset(void *dest, int c, size_t len)
{
    unsigned int i = 0;
    char *str = dest;
    while (i < len)
    {
        str[i] = (unsigned char)c;
        i++;
    }
    return (dest);
}
