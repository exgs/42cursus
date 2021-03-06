/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:31:14 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 15:53:09 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	charge_specifier_struct(t_specifier *matchup_array)
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
	matchup_array->function_specifier[7] = big_x_specifier;
	matchup_array->function_specifier[8] = per_specifier;
	matchup_array->function_specifier[9] = 0;
	return ;
}

int		matchup_tag(char *tag_s, va_list *ap, t_specifier *matchup_array)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (tag_s[(ft_strlen(tag_s) - 1)] != matchup_array->array_specifier[i])
	{
		i++;
		if (matchup_array->array_specifier[i] == '\0')
			return (0);
	}
	if (NULL != matchup_array->function_specifier[i])
	{
		len += matchup_array->function_specifier[i](tag_s, ap);
	}
	return (len);
}
