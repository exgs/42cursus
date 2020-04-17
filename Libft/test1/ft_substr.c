/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:32:48 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/29 21:32:48 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_substr(char *s, unsigned int start, size_t len)
{
    unsigned int i;
    char *substring;
    
    i = 0;
    substring =(char *)malloc(sizeof(char)*len);
    if (substring == NULL)
        return (NULL);
    
    while (i < len-1)
    {
        substring[i] = s[start+i];
        i++;
    }
    substring[len - 1] = '\0';
    return (substring);
}
