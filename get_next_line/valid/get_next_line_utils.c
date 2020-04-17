/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:34:27 by yunslee           #+#    #+#             */
/*   Updated: 2020/03/18 17:34:27 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int is_replaced_zero(char *buf)
{
    int i = 0;
    while (i < BUFFER_SIZE) // sizeof(buf) = 4byte(pointer)
    {
        if(buf[i] == '\0')
        {
            return (1);
        }
        i++;
    }
    return (0);
}

char *ft_strchr(const char *s, int c)
{
    int i;
    char *str;

    str = (char *)s;
    i = 0;
    while (str[i])
    {
        if (str[i] == (unsigned char)c)
            break;
        i++;        
    }
    return (str+i);
}


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

char *ft_strdup(const char *str)
{
    char *str_dup;
    unsigned int i;
    unsigned int str_len;

    i = 0;
    while(str[i])
        i++;
    str_len = i; // delete ft_strlen()
    str_dup = (char *)malloc(sizeof(char) * str_len + 1);
    i = 0;
    while (i < str_len)
    {
        str_dup[i] = str[i];
        i++;
    }
    str_dup[str_len] = '\0';
    return (str_dup);
}

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
