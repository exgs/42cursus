/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:31:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/15 06:12:41 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int len;

	len = 0;
	va_list ap;
	va_start(ap, format);
	char *string;

	string = (char *)format;
	read_format(string, &ap, &len);
	va_end(ap);
	return (len);
}

void	read_format(char *str, va_list *ap, int *len)
{
	int i = 0;
	int strlen;
	char *tag_string;
	
	strlen = ft_strlen(str);
	// printf("%d\n", strlen);
	while (i < strlen)
	{
		*len += read_non_format_tag(str, &i);
		// printf("%d\n", *len);
		tag_string = read_format_tag(str, &i);
		// printf("tag string : %s tag_size : %d\n", tag_string, ft_strlen(tag_string));
		*len += printf_tag(tag_string, ap);
		// printf("read_tag len : %d\n", *len);
		// printf("%d\n", *len);
		free(tag_string);
	}
	// printf("ft_printf End static i : %d", i);
	// printf("|");
	return ;
}

int read_non_format_tag(char *str, int *i)
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

char* read_format_tag(char *str, int *i)
{
	int init;
	char *format_tag;
	
	if (str[(*i)] == '\0')//read_non_format으로 서식문자열이 끝나는 경우
		return (NULL);
	init = (*i)++;
	while (str[*i] != 'c' && str[*i] != 's' && str[*i] != 'p' && str[*i] != 'd'
			&& str[*i] != 'i' && str[*i] != 'u' && str[*i] != 'x' &&
				str[*i] != 'X' && str[(*i)] != '%' && str[(*i)] != '\0')
	{
		(*i)++;
	}
	if (str[*i] == '\0')//error! %로 시작하였으나, 서식문자로 끝나지않은 경우(출력하지 않기로 한다.)
		return (NULL);
	format_tag = malloc(sizeof(char) * ((*i) - init + 2));
	ft_strlcpy(format_tag, str + init, ((*i) - init + 2));
	// ft_putstr_fd(format_tag, 1);
	// free(format_tag);
	(*i)++;
	return (format_tag);
}

int printf_tag(char *tag_string, va_list *ap)
{
	int len;

	if (tag_string == NULL || ap == NULL) //서식태그가 형식적이지않는 경우 출력하지않는다.
		return (0);
	t_specifier matchup_array;
	charge_specifier_struct(&matchup_array);
	len = matchup_tag(tag_string, ap, &matchup_array);
	return (len);
}
