#include "ft_printf.h"

int flag_return_atoi(char *str)
{
	int i;
	int start;
	int num;
	char *temp;

	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		i++;
	}//첫 숫자가 시작되는 순간을 찾기
	start = i;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		i++;
	}//숫자가 끝나는 순간을 찾기
	temp = malloc(sizeof(char) * (i - start) + 1);
	ft_strlcpy(temp, str + start, (i - start) + 1);
	num = ft_atoi(temp);// 023 -> 23으로 변환가능한 ft_atoi
	free(temp);
	return (num);
}


void flag_printspace(char *str)
{
	int i;
	int start;
	int num;
	char *temp;

	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
	{
		i++;
	}//첫 숫자가 시작되는 순간을 찾기
	start = i;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		i++;
	}//숫자가 끝나는 순간을 찾기
	temp = malloc(sizeof(char) * (i - start) + 1);
	ft_strlcpy(temp, str + start, (i - start) + 1);
	num = ft_atoi(temp);// 023 -> 23으로 변환가능한 ft_atoi
	num = num -1; //문자 갯수 하나빼기
	while (num-- > 0)
	{
		write(1, " ", 1);
	}
	free(temp);
	return ;
}

void flag_decision(char *str, t_flag *flag)
{
	int i;

	i = 1;
	if (str[1] == '0')
		flag->zero++;
	if (str[1] == '-')
	{
		flag->minus++;
		if (str[2] == '0')
			flag->zero++;
	}
	while (str[i] != '\0')
	{
		if (str[i] == '*')
			flag->star++;
		if (str[i++] == '.')
			flag->dot++;
	}
	return ;
}