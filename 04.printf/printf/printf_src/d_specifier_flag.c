#include "ft_printf.h"

void	d_flag_nostar(t_flag *flag, va_list *ap, char d_flag)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;

	num = va_arg(*ap, int);
	if (num < 0 && d_flag == 1)
	{
		unsigned_num = -1 * num;
		flag->d_minus_sign = 1;
	}
	else
		unsigned_num = num;
	utoa_str = ft_utoa(unsigned_num);
	// printf("utoa_str : %s\n",utoa_str);
	if (flag->d_precision > flag->d_width && flag->d_precision > flag->d_width)
		d_flag_precision_most(flag, utoa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > ft_strlen(utoa_str))
		d_flag_width_most(flag, utoa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		d_flag_strlen_most(flag, utoa_str);
	free(utoa_str);
	return ;
}

void	d_flag_onestar(t_flag *flag, va_list *ap, char d_flag)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;

	if (flag->star_front > 0)
		flag->d_width = va_arg(*ap, int);
	else
		flag->d_precision = va_arg(*ap, int);
	num = va_arg(*ap, int);
	if (num < 0 && d_flag == 1)
	{
		unsigned_num = -1 * num;
		flag->d_minus_sign = 1;
	}
	else
		unsigned_num = num;
	utoa_str = ft_utoa(unsigned_num);
	if (flag->d_precision > flag->d_width && flag->d_precision > flag->d_width)
		d_flag_precision_most(flag, utoa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > ft_strlen(utoa_str))
		d_flag_width_most(flag, utoa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		d_flag_strlen_most(flag, utoa_str);
	free(utoa_str);
	return ;
}

void	d_flag_twostar(t_flag *flag, va_list *ap, char d_flag)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;

	flag->d_width = va_arg(*ap, int);
	flag->d_precision = va_arg(*ap, int);
	num = va_arg(*ap, int);
	if (num < 0 && d_flag == 1)
	{
		unsigned_num = -1 * num;
		flag->d_minus_sign = 1;
	}
	else
		unsigned_num = num;
	utoa_str = ft_utoa(unsigned_num);
	if (flag->d_precision > flag->d_width && flag->d_precision > flag->d_width)
		d_flag_precision_most(flag, utoa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > ft_strlen(utoa_str))
		d_flag_width_most(flag, utoa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		d_flag_strlen_most(flag, utoa_str);
	free(utoa_str);
	return ;
}
