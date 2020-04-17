/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:11:12 by yunslee           #+#    #+#             */
/*   Updated: 2020/02/26 14:11:12 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// char *ft_strstr(const char *big, const char *little)
// {
//     unsigned int i;
//     unsigned int j;
//     unsigned int little_len;

//     if (little[0] == '\0')
//         return (big);
//     i = 0;
//     while (little[i++])
//         little_len++;
//     i = 0;
//     while (big[i] && big[i + little_len -1])
//     {
//         j = 0;
//         while (little[j])
//         {
//             if (big[i+j] != little[j])
//                 break;
//             if (j == little_len - 1)
//                 return (big + i);
//             j++;
//         }
//         i++;        
//     }
//     return (NULL);
// }

char *ft_strnstr(const char *big, const char *little, size_t n)
{
    unsigned int i;
    unsigned int j;
    unsigned int little_len;
    char * str;
    
    str = (char *)big;
    if (little[0] == '\0')
        return (str);
    i = 0;
    while (little[i++])
        little_len++;
    i = 0;
    while (str[i] && str[i + (little_len -1)] && (i + (little_len - 1)) < n)
    {
        j = 0;
        while (little[j])
        {
            if (str[i+j] != little[j])
                break;
            if (j == little_len - 1)
                return (str + i);
            j++;
        }
        i++;        
    }
    return (NULL);
}
