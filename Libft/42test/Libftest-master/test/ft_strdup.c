/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 21:01:15 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/10 02:54:23 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char			*ft_strdup(const char *str)
{
	char			*str_dup;
	unsigned int	i;
	unsigned int	str_len;

	str_len = ft_strlen(str);
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
