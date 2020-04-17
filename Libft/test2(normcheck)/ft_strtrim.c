/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:28:21 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/10 02:54:51 by yunslee          ###   ########.fr       */
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

static size_t	front_count(const char *s1, const char *set)
{
	unsigned int	i;
	unsigned int	j;
	size_t			value;

	i = 0;
	j = 0;
	value = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				value++;
				break ;
			}
			j++;
		}
		i++;
		if (i != value)
			break ;
	}
	return (value);
}

static size_t	back_count(const char *s1, const char *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	s1_len;
	size_t			value;

	i = 0;
	j = 0;
	value = 0;
	s1_len = ft_strlen(s1);
	while (i < s1_len)
	{
		j = 0;
		while (set[j])
		{
			if (s1[(s1_len - 1) - i] == set[j++])
			{
				value++;
				break ;
			}
		}
		i++;
		if (i != value)
			break ;
	}
	return (value);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	k;
	char			*str_trim;

	i = 0;
	k = 0;
	if (back_count(s1, set) == 0 && front_count(s1, set) == 0)
		str_trim = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	else
		str_trim = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) - front_count(s1, set) - back_count(s1, set) + 1));
	i += front_count(s1, set);
	while (i < ft_strlen(s1) - back_count(s1, set))
	{
		str_trim[k] = s1[i];
		i++;
		k++;
	}
	str_trim[k] = '\0';
	return (str_trim);
}
