#include "ft_printf.h"

void d_flag_precision_most(t_flag *flag, char *int_str)
{
	int precision_zero;

	// printf("check\n");
	precision_zero = flag->d_precision - ft_strlen(int_str);
	if (flag->d_minus_sign == 1)
		write(1,"-", 1);
	while (precision_zero-- > 0)
		write(1, "0", 1);
	ft_putstr_fd(int_str, 1);
	return ;
}

void d_flag_strlen_most(t_flag *flag, char *int_str)
{
	if (flag->d_minus_sign == 1)
		write(1,"-", 1);
	ft_putstr_fd(int_str, 1);
	return ;
}

void d_flag_width_most(t_flag *flag, char *int_str)
{
	int precision_zero;
	int width_space;
	int temp;

	precision_zero = flag->d_precision - ft_strlen(int_str);
	if (flag->d_precision == -1 || flag->d_precision < ft_strlen(int_str))
		width_space = flag->d_width - ft_strlen(int_str);
	else
		width_space = flag->d_width - flag->d_precision;
	if (flag->d_minus_sign == 1)
		width_space--;
	if (flag->d_left == 1)//0은 고려해주지않아도 됨
	{
		if (flag->d_minus_sign == 1)
			write(1,"-", 1);
		while (precision_zero-- > 0)
			write(1, "0", 1);
		ft_putstr_fd(int_str, 1);
	}
	if (flag->d_zero != 1 || (flag->d_zero == 1 && flag->d_precision > 0))
		while (width_space-- > 0)
			write(1, " ", 1);
	when_d_left_zero(int_str, flag, precision_zero);
	return ;
}

void when_d_left_zero(char *int_str, t_flag *flag, int precision_zero)
{
	int temp;

	if (flag->d_left == 0)
	{
		if (flag->d_precision < 0 && flag->d_zero == 1)
		{
			temp = flag->d_width - ft_strlen(int_str);
			while (temp-- > 0)
				write(1, "0", 1);
		}
		else if (flag->d_zero == 0 || flag->d_precision > 0)
		{
			if (flag->d_minus_sign == 1)
				write(1,"-", 1);
			while (precision_zero-- > 0)
				write(1, "0", 1);
		}
		ft_putstr_fd(int_str, 1);
	}
	return ;
}

