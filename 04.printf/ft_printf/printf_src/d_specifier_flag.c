#include "ft_printf.h"

int		d_flag_nostar(t_flag *flag, va_list *ap, char d_flag)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;
	int len;

	len = 0;
	num = va_arg(*ap, int);
	if (num < 0 && d_flag == 1)
	{
		unsigned_num = -1 * num;
		flag->d_minus_sign = 1;
		len = 1;
	}
	else
		unsigned_num = num;
	utoa_str = ft_utoa(unsigned_num);
	len += ft_strlen(utoa_str);
	//len 재사용
	if (flag->d_precision > flag->d_width && flag->d_precision > len)
		len = d_flag_precision_most(flag, utoa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > len)
		len = d_flag_width_most(flag, utoa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		len = d_flag_strlen_most(flag, utoa_str);
	free(utoa_str);
	return (len);
}

int		d_flag_onestar(t_flag *flag, va_list *ap, char d_flag)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;
	int len;

	len = 0;
	if (flag->star_front > 0)
	{
		if ((flag->d_width = va_arg(*ap, int)) < 0)
		{
			flag->d_width *= -1;
			flag->d_left = 1;
		}
	}
	else
		flag->d_precision = va_arg(*ap, int);
	num = va_arg(*ap, int);
	if (num < 0 && d_flag == 1)
	{
		unsigned_num = -1 * num;
		flag->d_minus_sign = 1;
		len = 1;
	}
	else
		unsigned_num = num;
	utoa_str = ft_utoa(unsigned_num);
	len += ft_strlen(utoa_str);
	if (flag->d_precision > flag->d_width && flag->d_precision > len)
		len = d_flag_precision_most(flag, utoa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > len)
		len = d_flag_width_most(flag, utoa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		len = d_flag_strlen_most(flag, utoa_str);
	free(utoa_str);
	return (len);
}

int		d_flag_twostar(t_flag *flag, va_list *ap, char d_flag)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;
	int len;

	len = 0;
	if ((flag->d_width = va_arg(*ap, int)) < 0)
	{
		flag->d_width *= -1;
		flag->d_left = 1;
	}
	flag->d_precision = va_arg(*ap, int);
	num = va_arg(*ap, int);
	if (num < 0 && d_flag == 1)
	{
		unsigned_num = -1 * num;
		flag->d_minus_sign = 1;
		len = 1;
	}
	else
		unsigned_num = num;
	// printf("-----------------\n");
	utoa_str = ft_utoa(unsigned_num);
	len += ft_strlen(utoa_str);
	if (flag->d_left == 1 && flag-> d_zero == 1)
		flag->d_zero = 0;
	if (flag->d_precision > flag->d_width && flag->d_precision > len)
		len = d_flag_precision_most(flag, utoa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > len)
		len = d_flag_width_most(flag, utoa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		len = d_flag_strlen_most(flag, utoa_str);
	free(utoa_str);
	// printf("len in d_specifier_flag.c : %d\n", len);
	return (len);
}
