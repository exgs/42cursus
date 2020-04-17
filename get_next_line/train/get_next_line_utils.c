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


int get_next_line(int fd, char**line)
{
    int n;
    char buf[BUFFER_SIZE + 1];
    static char* str = "\0";
    char *temp=NULL;
    int i;

    ft_memset(buf,0,BUFFER_SIZE+1);
    // buf[BUFFER_SIZE] = '\0';
    while ((n=read(fd, buf, BUFFER_SIZE)) > 0)
    {
        // test
        // printf("========================\n");
        // printf("readbyte : %d AND buf : %s\n",n,buf);
        // printf("--------------------\n");
        i = 0;
        while (buf[i])
        {
            if (buf[i] == '\n')
            {
                buf[i] = '\0';
                break;
            }
            i++;
        }
        str = ft_strjoin(str,buf);
        free(temp);
        temp = str;
        if (is_replaced_zero(buf))
            break;
        ft_memset(buf,0,BUFFER_SIZE+1);
    }
    // printf("check\n");
    *line = ft_strdup(str);
    str=ft_strdup(ft_strchr(buf,0)+1); // ft_strchr에서 '\0'값 이후를 가리켜야하므로 + 1 수정
    free(temp); //main함수에서 free()는 duplicated 된 쌍둥이
    if (n == 0)
    {
       free(str);
       return 0;
    }
    else if(n == -1)
    {
        free(str);
        return -1;
    }
    else
    {
        return 1;
    }
    
    
}