/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:31:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/15 02:20:15 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (matchup_array->array_specifier[i] == '\0')
			return ;
	}
	if (NULL != matchup_array->function_specifier[i])
	{
		matchup_array->function_specifier[i](tag_string, ap);
	}
	return ;
}
