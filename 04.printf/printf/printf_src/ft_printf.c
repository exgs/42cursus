/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:31:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/10 19:31:41 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void read_non_format(char *str, int *i)
{
	int init;
	
	if (str == NULL)
		return ;
	init = *i;
	while (str[*i] != '%' && str[*i] != '\0')
	{
		(*i)++;
	}
	write(1, str + init, (*i - init));
	return ;
}

char* read_format_tag(char *str, int *i)
{
	int init;
	char *format_tag;
	
	if (str[(*i)] == '\0')
		return (NULL);
	init = (*i)++;
	while (str[*i] != 'c' && str[*i] != 's' && str[*i] != 'p' && str[*i] != 'd'
			&& str[*i] != 'i' && str[*i] != 'u' && str[*i] != 'x' &&
				str[*i] != 'X' && str[(*i)] != '%')
	{
		(*i)++;
	}
	format_tag = malloc(sizeof(char) * ((*i) - init + 2));
	ft_strlcpy(format_tag, str + init, ((*i) - init + 2));
	// ft_putstr_fd(format_tag, 1);
	// free(format_tag);
	(*i)++;
	return (format_tag);
}

void charge_specifier_struct(t_specifier *matchup_array)
{
	if (matchup_array == NULL)
		return ;
	matchup_array->array_specifier[0] = 'c';
	matchup_array->array_specifier[1] = 's';
	matchup_array->array_specifier[2] = 'p';
	matchup_array->array_specifier[3] = 'd';
	matchup_array->array_specifier[4] = 'i';
	matchup_array->array_specifier[5] = 'u';
	matchup_array->array_specifier[6] = 'x';
	matchup_array->array_specifier[7] = 'X';
	matchup_array->array_specifier[8] = '%';
	matchup_array->array_specifier[9] = 0;
	matchup_array->function_specifier[0] = c_specifier;
	matchup_array->function_specifier[1] = s_specifier;
	matchup_array->function_specifier[2] = p_specifier;
	matchup_array->function_specifier[3] = d_specifier;
	matchup_array->function_specifier[4] = i_specifier;
	matchup_array->function_specifier[5] = u_specifier;
	matchup_array->function_specifier[6] = x_specifier;
	matchup_array->function_specifier[7] = X_specifier;
	matchup_array->function_specifier[8] = percent_specifier;
	matchup_array->function_specifier[9] = 0;
	return ;
}

void matchup_tag(char *tag_string, va_list *ap, t_specifier *matchup_array)
{
	int i;
	
	i = 0;
	while (tag_string[(ft_strlen(tag_string) -1)] != matchup_array->array_specifier[i])
	{
		i++;
		// printf("%s %d\n",tag_string, ft_strlen(tag_string));
		// printf("--%d=\n",i);
		// if (i == 13)
		// 	break;
	}
	if (NULL != matchup_array->function_specifier[i])
	{
		matchup_array->function_specifier[i](tag_string, ap);
	}
	return ;
}

void printf_tag(char *tag_string, va_list *ap)
{
	if (tag_string == NULL || ap == NULL)
		return ;
	t_specifier matchup_array;
	charge_specifier_struct(&matchup_array);
	matchup_tag(tag_string, ap, &matchup_array);
	return ;
}

char *read_format(char *str, va_list *ap)
{
	int i = 0;
	int strlen;
	char *tag_string;
	
	strlen = ft_strlen(str);
	// printf("%d\n", strlen);
	while (i < strlen)
	{
		read_non_format(str, &i);
		// printf("|");
		if (i >= strlen)
		{
			// printf("break : %d\n", i);
			break;
		}
		tag_string = read_format_tag(str, &i);
		// printf("tag string : %s tag_size : %d\n", tag_string, ft_strlen(tag_string));
		// printf("-------\n");
		printf_tag(tag_string, ap);
		// printf("|");
		free(tag_string);
	}
	// printf("ft_printf End static i : %d", i);
	// printf("|");
	return (NULL);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	char *string;

	string = (char *)format;
	read_format(string, &ap);
	va_end(ap);
	return (0);
}