#include "ft_printf.h"

char prefix[3] = {'0', 'x', 0};

int	 p_flag_nostar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int address_num;
	char *address_str;
	char *temp_str;
	int temp;
	int len;

	len = 0;
	address_num = va_arg(*ap, long unsigned int);
	// printf("printf %%lx : %lx\n", address_num);
	temp_str = return_hexa_str(address_num, hex_table);
	// printf("temp_str : %s\n", temp_str);
	address_str = ft_strjoin(prefix, temp_str);
	free(temp_str);
	if (flag->d_left == 1)
		ft_putstr_fd(address_str, 1);
	if ((temp = (flag->d_width - ft_strlen(address_str))) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(address_str, 1);
	len += ft_strlen(address_str);
	free(address_str);
	return (len);
}

int	 p_flag_onestar(t_flag *flag, char *hex_table, va_list *ap)
{
	long unsigned int address_num;
	char *address_str;
	char *temp_str;
	int temp;
	int len;

	len = 0;
	if ((flag->d_width = va_arg(*ap, int)) < 0)
	{
		flag->d_width *= -1;
		flag->d_left = 1;
	}
	address_num = va_arg(*ap, long unsigned);
	temp_str = return_hexa_str(address_num, hex_table);
	address_str = ft_strjoin(prefix, temp_str);
	free(temp_str);
	if (flag->d_left == 1)
		ft_putstr_fd(address_str, 1);
	if ((temp = (flag->d_width - ft_strlen(address_str))) > 0)
	{
		len = temp;
		while (temp-- > 0)
			write(1, " ", 1);
	}
	if (flag->d_left == 0)
		ft_putstr_fd(address_str, 1);
	len += ft_strlen(address_str);
	free(address_str);
	return (len);
}

