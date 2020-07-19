#include "ft_printf.h"

void s_print_normal(t_flag *flag, va_list *ap)
{
	char *str;
	int temp;

	while (flag->star > 0)
	{
		temp = va_arg(*ap, int);
		flag->star--;
	}
	str = (char *)va_arg(*ap, char *);
	ft_putstr_fd(str, 1);
	return ;
}

void s_flag_unnormal(char *str_tag, t_flag *flag, va_list *ap)
{
	char *str;
	int space;
	int precision;
	int strlen;
	int temp;

	if (flag->minus == 1)
	{
		s_flag_minus(str_tag, flag, ap);
		return ;
	}
	if (flag->dot == 1)
	{
		s_flag_dot(str_tag, flag, ap);
		return ;
	}
	else if (flag->dot == 0)
	{
		if (flag->star == 1)
		{
			space = va_arg(*ap, int);
			str = (char *)va_arg(*ap, char *);
			strlen = ft_strlen(str);
			temp = space - strlen;
			while (temp-- > 0)
				write(1, " ", 1);
		}
		else if (flag->star > 1)
			s_print_normal(flag, ap);
		ft_putstr_fd(str, 1);
	}
	
	
	else
		flag_printspace(str_tag);
	return ;
}

void s_flag_dot(char *str_tag, t_flag *flag, va_list *ap)
{
	int space;
	int precision;
	
	if (flag->star == 2)
	{
		space = (int)va_arg(*ap, int);
		precision = (int)va_arg(*ap, int);
	}
	else if (flag->star == 1)
		precision = (int)va_arg(*ap, int);
	return ;
		
		
	
}

void s_flag_minus(char*str_tag, t_flag *flag, va_list *ap)//앞선 가정에서 star가 1개인경우만
{
	char *str;
	int space;

	if (flag->star == 1)
	{
		space = (int)va_arg(*ap, int);
		str= (char *)va_arg(*ap, char *);
		ft_putstr_fd(str, 1);
		space = space - 1;//문자 갯수 하나 빼기
		while (space--> 0)
			write(1, " ", 1);
	}
	else
	{
		str = (char *)va_arg(*ap, char *);
		ft_putstr_fd(str, 1);
		flag_printspace(str_tag);
	}
	return ;
}
