/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:53:28 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/29 21:53:28 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
    unsigned int i;
    unsigned int j;
    char *str_join;
    i = 0;
    while (s1[i])
        i++;
    j = 0;
    while (s2[j])
        j++;
    str_join = (char *)malloc(sizeof(char)*(i + j + 1));
    if (str_join == NULL)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str_join[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        str_join[i + j] = s2[j];
        j++;
    }
    str_join[i + j] = '\0';
    return (str_join);
}
