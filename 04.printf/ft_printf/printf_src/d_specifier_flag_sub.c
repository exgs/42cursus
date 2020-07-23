#include "ft_printf.h"

int	 d_flag_precision_most(t_flag *flag, char *utoa_str)
{
	int precision_zero;
	int len;
	// printf("-----\n");

	len = 0;
	precision_zero = flag->d_precision - ft_strlen(utoa_str);
	if (flag->d_minus_sign == 1)
	{
		write(1,"-", 1);
		len = 1;
	}
	while (precision_zero-- > 0)
		write(1, "0", 1);
	ft_putstr_fd(utoa_str, 1);
	len += flag->d_precision;
	// printf("len in precision_most : %d\n", len);
	return (len);
}

int	 d_flag_strlen_most(t_flag *flag, char *utoa_str)
{
	int len;

	len = 0;
	if (flag->d_minus_sign == 1)
	{
		write(1,"-", 1);
		len = 1;
	}
	ft_putstr_fd(utoa_str, 1);
	len += ft_strlen(utoa_str);
	return (len);
}

int	 d_flag_width_most(t_flag *flag, char *utoa_str)
{
	int precision_zero;
	int width_space;
	// int precision_temp;
	// printf("----\n");
	precision_zero = flag->d_precision - ft_strlen(utoa_str);
	// precision_temp = per
	if (flag->d_precision == -1 || (int)(flag->d_precision - (int)ft_strlen(utoa_str)) < 0)
		width_space = flag->d_width - ft_strlen(utoa_str);
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
		ft_putstr_fd(utoa_str, 1);
	}
	if (flag->d_zero != 1 || (flag->d_zero == 1 && precision_zero > 0))
	{
		while (width_space-- > 0)
			write(1, " ", 1);
		// printf("checkout\n");
	}
	when_d_left_zero(utoa_str, flag, precision_zero, width_space);
	return (flag->d_width);
}

void when_d_left_zero(char *utoa_str, t_flag *flag, int precision_zero, int width_space)
{
	int temp;

	if (flag->d_left == 0)
	{
		if (flag->d_minus_sign == 1)
				write(1,"-", 1);
		if (flag->d_precision < 0 && flag->d_zero == 1)
		{
			// if (flag->d_minus_sign == 1)
			// 	write(1,"-", 1);
			while (width_space-- > 0)
				write(1, "0", 1);
		}
		else if (flag->d_zero == 0 || flag->d_precision > 0)
		{
			// if (flag->d_minus_sign == 1)
			// 	write(1,"-", 1);
			while (precision_zero-- > 0)
				write(1, "0", 1);
		}
		ft_putstr_fd(utoa_str, 1);
	}
	return ;
}

