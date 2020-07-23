#include "ft_printf.h"

int		percent_flag_nostar(t_flag *flag, va_list *ap)
{
	int width_space;
	int len;

	len = 0;
	width_space = flag->d_width - 1;
	len = width_space;
	if (flag->d_left == 1)
		write(1, "%", 1);
	if (flag->d_zero != 1)
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	else if (flag->d_zero == 1)
	{
		while (width_space-- > 0)
			write(1, "0", 1);
	}
	if (flag->d_left == 0)
		write(1, "%", 1);
	return (len + 1);
}

int		percent_flag_onestar(t_flag *flag, va_list *ap)
{
	int width_space;
	int len;

	len = 0;
	if (flag->star_front > 0)
		flag->d_width = va_arg(*ap, int);
	else
		flag->d_precision = va_arg(*ap, int);
	width_space = flag->d_width - 1;
	len = width_space;
	if (flag->d_left == 1)
		write(1, "%", 1);
	if (flag->d_zero != 1)
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	else if (flag->d_zero == 1)
	{
		while (width_space-- > 0)
			write(1, "0", 1);
	}
	if (flag->d_left == 0)
		write(1, "%", 1);
	return (len + 1);
}

int		percent_flag_twostar(t_flag *flag, va_list *ap)
{
	int width_space;
	int len;

	len = 0;
	flag->d_width = va_arg(*ap, int);
	flag->d_precision = va_arg(*ap, int);
	width_space = flag->d_width - 1;
	len = width_space;
	if (flag->d_left == 1)
		write(1, "%", 1);
	if (flag->d_zero != 1)
	{
		while (width_space-- > 0)
			write(1, " ", 1);
	}
	else if (flag->d_zero == 1)
	{
		while (width_space-- > 0)
			write(1, "0", 1);
	}
	if (flag->d_left == 0)
		write(1, "%", 1);
	return (len + 1);
}
