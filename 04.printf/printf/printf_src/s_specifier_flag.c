#include "ft_printf.h"

char g_null[7] = "(null)";

void s_flag_nostar(t_flag *flag, va_list *ap)
{
	char *str;
	int temp;

	if (NULL == (str = (char *)va_arg(*ap, char *)))
		str = g_null;
	if (flag->d_precision >= 0 && ft_strlen(str) > flag->d_precision)
		str = ft_substr(str, 0, flag->d_precision);
	if (flag->d_left == 1)
		ft_putstr_fd(str, 1);
	// printf("d_width : %d\n d_precision : %d\n",flag->d_width,flag->d_precision);
	if ((flag->d_width - ft_strlen(str)) > 0)
	{
		temp = flag->d_width - ft_strlen(str);
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(str, 1);
	return ;
}

void s_flag_onestar(t_flag *flag, va_list *ap)
{
	char *str;
	int temp;

	if (flag->star_front > 0)
		flag->d_width = (int)va_arg(*ap, int);
	else
		flag->d_precision = (int)va_arg(*ap, int);
	if (NULL == (str = (char *)va_arg(*ap, char *)))
		str = g_null;
	if (flag->d_precision >= 0 && ft_strlen(str) > flag->d_precision)
		str = ft_substr(str, 0, flag->d_precision);
	if (flag->d_left == 1)
		ft_putstr_fd(str, 1);
	if ((flag->d_width - ft_strlen(str)) > 0)
	{
		temp = flag->d_width -ft_strlen(str);
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(str, 1);
	if (flag->d_precision >= 0 && ft_strlen(str) > flag->d_precision)
		free(str);
	return ;
}

void s_flag_twostar(t_flag *flag, va_list *ap)
{
	char *str;
	int temp;

	flag->d_width = (int)va_arg(*ap, int);
	flag->d_precision = (int)va_arg(*ap, int);
	if (NULL == (str = (char *)va_arg(*ap, char *)))
		str = g_null;
	if (flag->d_precision >= 0 && ft_strlen(str) > flag->d_precision)
		str = ft_substr(str, 0, flag->d_precision);
	if (flag->d_left == 1)
		ft_putstr_fd(str, 1);
	if ((flag->d_width - ft_strlen(str)) > 0)
	{
		temp = flag->d_width - ft_strlen(str);
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(str, 1);
	if (flag->d_precision >= 0 && ft_strlen(str) > flag->d_precision)
		free(str);
	return ;
}
