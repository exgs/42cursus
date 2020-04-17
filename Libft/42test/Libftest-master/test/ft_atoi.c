/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:32:36 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/08 21:10:32 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	atoi_while(const char *str, int i)
{
	int	sum;

	sum = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		sum *= 10;
		sum += str[i] - 48;
		i++;
	}
	if (sum == -2147483648)
		sum *= -1;
	return (sum);
}

int			ft_atoi(const char *str)
{
	int i;
	int sign;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	return (sign * atoi_while(str, i));
}
