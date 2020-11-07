/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_cub.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:04:52 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/07 21:16:49 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_cub.h"

char		*ft_strchr2(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if (c == 0)
		return (str + i);
	return (0);
}

void		*ft_memset2(void *dest, int c, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = dest;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

char		*ft_strdup2(const char *str)
{
	char			*str_dup;
	unsigned int	i;
	unsigned int	str_len;

	if (str == NULL)
	{
		str_dup = malloc(sizeof(char));
		str_dup[0] = '\0';
		return (str_dup);
	}
	str_len = ft_strlen2(str);
	str_dup = (char *)malloc(sizeof(char) * str_len + 1);
	if (str_dup == 0)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str_dup[i] = str[i];
		i++;
	}
	str_dup[str_len] = '\0';
	return (str_dup);
}

char		*ft_strjoin2(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str_join;

	if (s1 == NULL)
		return (ft_strdup2(s2));
	else if (s2 == NULL)
		return (NULL);
	if (NULL == (str_join = malloc(sizeof(char) *
						(ft_strlen2(s1) + ft_strlen2(s2) + 1))))
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

size_t		ft_strlen2(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
