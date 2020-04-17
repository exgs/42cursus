/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:24:46 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/26 16:24:46 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strrchr(const char *s, int c)
{
    unsigned int i;
    char *str;

    str = (char *)s;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            break;
        i++;        
    }
    return (str + i);
}
