#include "ft_printf.h"

int flag_return_atoi(char *str)
{
	int i;
	int start;
	int num;
	char *temp;

	i = 0;
	while (str[i] != '\0' && (str[i] < '0' || str[i] > '9') && str[i] != '.')
	{
		i++;
	}//첫 숫자가 시작되는 순간을 찾기
	start = i;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') && str[i] != '.')
	{
		i++;
	}//숫자가 끝나는 순간을 찾기
	temp = malloc(sizeof(char) * (i - start) + 1);
	ft_strlcpy(temp, str + start, (i - start) + 1);
	num = ft_atoi(temp);// 023 -> 23으로 변환가능한 ft_atoi
	//만약 str[i] == '\0'이라면, 결과적으로 atoi return값은 0 -> 어짜피 별표로 덮어씌여지긴 함
	free(temp);
	return (num);
}

/*현재 쓰지않는 함수*/
void flag_printfspace(char *str)
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
		if (str[i] == '*' && flag->dot >0)
			flag->star_back++;
		i++;
	}
	return ;
}

void flag_decision_more(char *str_tag, t_flag *flag)
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
		flag->d_precision = -1; //**중요포인트
	}
	else if (flag->d_dot > 0)
	{
		flag->d_width = flag_return_atoi(str_tag);
		flag->d_precision = flag_return_atoi(ft_strchr(str_tag, '.') + 1);
	}
	return ;
}

void onestar_replace(t_flag *flag, va_list *ap)
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

void twostar_replace(t_flag *flag, va_list *ap)
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

void flag_printf(t_flag *flag)
{
	if (flag == NULL)
		printf("No flag data\n");
	printf("flag->d_dot : %d\n",flag->d_dot);
	printf("flag->d_left : %d\n",flag->d_left);
	printf("flag->d_precision : %d\n",flag->d_precision);
	printf("flag->d_star_sum : %d\n",flag->d_star_sum);
	printf("flag->d_width : %d\n",flag->d_width);
	printf("flag->d_zero : %d\n",flag->d_zero);

}
