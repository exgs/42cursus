/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:22:04 by yunslee           #+#    #+#             */
/*   Updated: 2020/03/01 14:22:04 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t split_len(const char *s, char c)
{
    unsigned int i;

    i = 0;
    while(s[i] && s[i] != c)
    {
        i++;
    }
    return (i);
}

static unsigned int size_array(const char *str, char c)
{
	int size;
	int i;

	i = 0;
	size = 0;
	if (str[0] != c)
		size +=1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			size++;
		i++;
	}
	return (size);
}

static int input_parts(char *dst, const char *src, char c, int i)
{
	int j;

	j = 0;
	while (src[i] && src[i] != c)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
    dst[j] = '\0';
	return (i);
}

char **ft_split(char const *s, char c)
{
    unsigned int i;
    unsigned int array_size;
    unsigned int row;
    char **split;
    
    i = 0;
    row = 0;
    array_size = size_array(s,c);
    split = (char**)malloc(sizeof(char *)*(array_size + 1));
    while (row < array_size)
    {
        split[row] = (char *)malloc(sizeof(char) * (split_len((s + row),c) + 1));
        i = input_parts(split[row],s,c,i);
        row++;
        while (s[i] == c)
            i++;
    }
    split[array_size] = NULL;
    return (split);
}
