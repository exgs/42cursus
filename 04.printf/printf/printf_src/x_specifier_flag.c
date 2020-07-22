#include "ft_printf.h"

void x_flag_nostar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int hexa_value;
	char *hexa_str;
	// printf("--\n");
	hexa_value = va_arg(*ap, long unsigned int);
	hexa_str = return_hexa_str(hexa_value, hex_table);
	if (flag->d_precision > flag->d_width && flag->d_precision > flag->d_width)
		x_flag_precision_most(flag, hexa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > ft_strlen(hexa_str))
		x_flag_width_most(flag, hexa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		x_flag_strlen_most(flag, hexa_str);
	free(hexa_str);
}

void x_flag_onestar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int hexa_value;
	char *hexa_str;

	if (flag->star_front > 0)
		flag->d_width = va_arg(*ap, int);
	else
		flag->d_precision = va_arg(*ap, int);
	hexa_value = va_arg(*ap, long unsigned int);
	hexa_str = return_hexa_str(hexa_value, hex_table);
	if (flag->d_precision > flag->d_width && flag->d_precision > flag->d_width)
		x_flag_precision_most(flag, hexa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > ft_strlen(hexa_str))
		x_flag_width_most(flag, hexa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		x_flag_strlen_most(flag, hexa_str);
	free(hexa_str);
}

void x_flag_twostar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int hexa_value;
	char *hexa_str;

	flag->d_width = va_arg(*ap, int);
	flag->d_precision = va_arg(*ap, int);
	hexa_value = va_arg(*ap, long unsigned int);
	hexa_str = return_hexa_str(hexa_value, hex_table);
	if (flag->d_precision > flag->d_width && flag->d_precision > flag->d_width)
		x_flag_precision_most(flag, hexa_str);
	else if (flag->d_width > flag->d_precision && flag->d_width > ft_strlen(hexa_str))
		x_flag_width_most(flag, hexa_str);
	else//아무런 flag도 포함하고 있지 않을 경우도 포함하는 듯
		x_flag_strlen_most(flag, hexa_str);
	free(hexa_str);
}
