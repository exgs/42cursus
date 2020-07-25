/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_flag_common.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:22:54 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/25 22:41:39 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_return_atoi(char *str)//형식태그에 존재하는 width와 precision의 정수값을 얻기위한 함수
{
	int		i;
	int		start;
	int		num;
	char	*temp;

	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9') && str[i] != '.')
	{
		i++;
	}
	start = i;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') && str[i] != '.')
	{
		i++;
	}
	temp = malloc(sizeof(char) * (i - start) + 1);
	ft_strlcpy(temp, str + start, (i - start) + 1);
	num = ft_atoi(temp);
	free(temp);
	return (num);
}

void	flag_decision(char *str, t_flag *flag)
{
	int i;

	i = 1;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '0'))
	{
		if (str[i] == '-')
			flag->minus++;
		if (str[i] == '0')
			flag->zero++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			flag->dot++;
		if (str[i] == '*' && flag->dot == 0)
			flag->star_front++;
		if (str[i] == '*' && flag->dot > 0)
			flag->star_back++;
		i++;
	}
	return ;
}

void	flag_decision_more(char *str_tag, t_flag *flag)
{
	flag->d_star_sum = flag->star_front + flag->star_back;
	if (flag->minus > 0)
		flag->d_left = 1;
	if (flag->zero > 0)
		flag->d_zero = 1;
	if (flag->dot > 0)
		flag->d_dot = 1;
	if (flag->d_dot == 0)
	{
		flag->d_width = flag_return_atoi(str_tag);
		flag->d_precision = -1;
	}
	else if (flag->d_dot > 0)
	{
		flag->d_width = flag_return_atoi(str_tag);
		flag->d_precision = flag_return_atoi(ft_strchr(str_tag, '.') + 1);
	}
	return ;
}

void	onestar_replace(t_flag *flag, va_list *ap)// '.'을 기준으로 '*'의 위치에 따라 너비 또는 정밀도에 할당해줌. 또한 음수처리를 해줌
{
	if (flag->star_front > 0)
	{
		if ((flag->d_width = (int)va_arg(*ap, int)) < 0)
		{
			flag->d_width *= -1;
			flag->d_left = 1;
		}
	}
	else
	{
		if ((flag->d_precision = (int)va_arg(*ap, int)) < 0)
			flag->d_precision = -1;
	}
	return ;
}

void	twostar_replace(t_flag *flag, va_list *ap) //너비와 정밀도에 음수로 들어오는 값에 대해서 처리를 해줌
{
	if ((flag->d_width = (int)va_arg(*ap, int)) < 0)
	{
		flag->d_width *= -1;
		flag->d_left = 1;
	}
	if ((flag->d_precision = (int)va_arg(*ap, int)) < 0)
		flag->d_precision = -1;
	return ;
}
