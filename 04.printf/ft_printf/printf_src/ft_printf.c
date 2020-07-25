/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:31:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 15:46:52 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		len;
	char	*string;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	string = (char *)format;
	read_format(string, &ap, &len);
	va_end(ap);
	return (len);
}

void	read_format(char *str, va_list *ap, int *len)
{
	int		i;
	int		strlen;
	char	*tag_string;

	i = 0;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		*len += read_non_format_tag(str, &i);
		tag_string = read_format_tag(str, &i);
		*len += printf_tag(tag_string, ap);
		free(tag_string);
	}
	return ;
}

int		read_non_format_tag(char *str, int *i)
{
	int init;

	if (str == NULL)
		return (0);
	init = *i;
	while (str[*i] != '%' && str[*i] != '\0')
	{
		(*i)++;
	}
	write(1, str + init, (*i - init));
	return (*i - init);
}

char	*read_format_tag(char *str, int *i)
{
	int		init;
	char	*format_tag;

	if (str[(*i)] == '\0')
		return (NULL);
	init = (*i)++;
	while (str[*i] != 'c' && str[*i] != 's' && str[*i] != 'p' && str[*i] != 'd'
			&& str[*i] != 'i' && str[*i] != 'u' && str[*i] != 'x' &&
				str[*i] != 'X' && str[(*i)] != '%' && str[(*i)] != '\0')
	{
		(*i)++;
	}
	if (str[*i] == '\0')
		return (NULL);
	format_tag = malloc(sizeof(char) * ((*i) - init + 2));
	ft_strlcpy(format_tag, str + init, ((*i) - init + 2));
	(*i)++;
	return (format_tag);
}

int		printf_tag(char *tag_string, va_list *ap)
{
	int			len;
	t_specifier	matchup_array;

	if (tag_string == NULL || ap == NULL)
		return (0);
	charge_specifier_struct(&matchup_array);
	len = matchup_tag(tag_string, ap, &matchup_array);
	return (len);
}
