#include "ft_printf.h"

int		d_flag_nostar(t_flag *flag, va_list *ap, char d_u)
{
	unsigned int unsigned_num;
	char *utoa_str;
	int len;

	len = 0;
	len += negative_to_positive_with_flags(flag, ap, d_u, &unsigned_num);
	utoa_str = ft_utoa(unsigned_num);
	len += ft_strlen(utoa_str);
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	if (flag->d_left == 1 && flag->d_zero == 1)
		flag->d_zero = 0;
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

int negative_to_positive_with_flags(t_flag *flag, va_list *ap, char d_u, unsigned int *positive_num)
{
	int num;

	num = va_arg(*ap, int);
	if (num < 0 && d_u == FORMAT_D)
	{
		*positive_num = num * -1;
		flag->d_minus_sign = 1;
		return (1);
	}
	else
	{
		*positive_num = num;
		return (0);
	}
	return (-1);
}

int		d_flag_onestar(t_flag *flag, va_list *ap, char d_u)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;
	int len;

	len = 0;
	onestar_replace(flag, ap);
	len += negative_to_positive_with_flags(flag, ap, d_u, &unsigned_num);
	utoa_str = ft_utoa(unsigned_num);
	len += ft_strlen(utoa_str);
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	if (flag->d_left == 1 && flag->d_zero == 1)
		flag->d_zero = 0;
	if (flag->d_precision > flag->d_width && flag->d_precision > len)
		len = d_flag_precision_most(flag, utoa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > len)
		len = d_flag_width_most(flag, utoa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		len = d_flag_strlen_most(flag, utoa_str);
	free(utoa_str);
	return (len);
}

int		d_flag_twostar(t_flag *flag, va_list *ap, char d_u)
{
	int num;
	unsigned int unsigned_num;
	char *utoa_str;
	int len;

	len = 0;
	twostar_replace(flag, ap);
	len += negative_to_positive_with_flags(flag, ap, d_u, &unsigned_num);
	utoa_str = ft_utoa(unsigned_num);
	len += ft_strlen(utoa_str);
	if (flag->d_precision < 0)
		flag->d_precision = -1;
	if (flag->d_left == 1 && flag->d_zero == 1)
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
