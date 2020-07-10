/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:33:39 by yunslee           #+#    #+#             */
/*   Updated: 2020/05/04 05:09:05 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char**line)
{
    int n;
    static char buf[BUFFER_SIZE + 1];
    static char* str = "\0";
    char *temp=NULL;
    int i;

    ft_memset(buf,0,BUFFER_SIZE + 1);
    // buf[BUFFER_SIZE] = '\0';
    while ((n=read(fd, buf, BUFFER_SIZE)) >= 0)
    {
		printf("n : %d\n",n);
        // test
        // printf("========================\n");
        // printf("readbyte : %d AND buf : %s\n",n,buf);
        // printf("--------------------\n");
        i = 0;
        while (i < BUFFER_SIZE)
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
		{
			// printf("if : running\n");
            break;
		}
		// printf("if : passing\n");
        ft_memset(buf,0,BUFFER_SIZE+1);
    }
    // printf("check\n");
    *line = ft_strdup(str);
	if (*str == '\0' && i == BUFFER_SIZE && n == 0)
	{
		printf("check\n");
		*line = NULL;
	}
    str=ft_strdup(ft_strchr(buf,0)+1); // ft_strchr에서 '\0'값 이후를 가리켜야하므로 + 1 수정
    free(temp); //main함수에서 free()는 duplicated 된 쌍둥이
	// printf("n : %d\n",n);
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

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}