/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:31:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/26 14:55:24 by yunslee          ###   ########.fr       */
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

	i = 0;//i는 함수내에서 증가된 값이 영향을 미치도록 while문 내의 함수에 int *i를 파라미터로 가짐
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		*len += read_non_format_tag(str, &i);//형식태그 이전까지는 읽고 출력함
		tag_string = read_format_tag(str, &i);//형식태그가 시작되는 '%'를 기준으로 형식태그의 문자열을 문자열포인터에 넘겨줌
		*len += printf_tag(tag_string, ap);//넘겨받은 형식태그와 가변인자목록포인터를 printf_tag()에 파라미터로 주면서, 형식태그에 관한 출력을 담당함
		free(tag_string);
	}
	return ;
}

int		read_non_format_tag(char *str, int *i)//형식태그가 아닌 문자열 읽기
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

char	*read_format_tag(char *str, int *i)//형식태그인 부분을 malloc 및 ft_strlcpy로 넘기기
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

int		printf_tag(char *tag_string, va_list *ap)//서식문자에 따라서 알맞은 함수가 실행되도록 판단해주는 함수
{
	int			len;
	t_specifier	matchup_array;

	if (tag_string == NULL || ap == NULL)
		return (0);
	charge_specifier_struct(&matchup_array);
	//서식문자('cspdiuxX%')와 각각의 서식문자에 따라서 실행되야되는 함수를 구조체(t_specifier)내의 배열에 담음.
	len = matchup_tag(tag_string, ap, &matchup_array);//서식문자에 따라서 알맞은 함수가 실행되도록 매칭시켜줌
	return (len);
}
