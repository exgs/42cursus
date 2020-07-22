/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:30:02 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/18 01:05:54 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
 #define FT_PRINTF_H
 #define LOWERCASE 0
 #define UPPERCASE 1
 #include "../libft/libft.h"//location
 #include "../libft_plus/libft_plus.h"//location

 #include <stdio.h>//temporary
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdarg.h>

typedef struct s_specifier
{
	char array_specifier[10];
	void (*function_specifier[10])(char *, va_list *);
}				t_specifier;

typedef struct s_flag
{
	char minus;
	char zero;
	char dot;
	char star_front;
	char star_back;


	char d_left;
	char d_zero;
	char d_minus_sign;
	char d_dot;

	int d_width;
	int d_precision;
	char d_star_sum;
}	t_flag;

int		ft_printf(const char *, ...);
char	*read_format(char *str, va_list *ap);
char	*read_format_tag(char *str, int *i);
void	read_non_format_tag(char *str, int *i);
void	printf_tag(char *tag_string, va_list *ap);

void	flag_decision(char *str, t_flag *flag);
void	flag_printfspace(char *str);
int		flag_return_atoi(char *str);
void	flag_decision_more(char *str_tag, t_flag *flag);
void	flag_printf(t_flag *flag);//편의를 위한 함수

void	c_specifier(char *str_tag, va_list *ap);
void	c_flag_nostar(t_flag *flag, va_list *ap);
void	c_flag_onestar(t_flag *flag, va_list *ap);
void	c_flag_twostar(t_flag *flag, va_list *ap);

void	s_specifier(char *s, va_list *ap);
void	s_flag_nostar(t_flag *flag, va_list *ap);
void	s_flag_onestar(t_flag *flag, va_list *ap);
void	s_flag_twostar(t_flag *flag, va_list *ap);

void	d_specifier(char *s, va_list *ap);

void	d_flag_nostar(t_flag *flag, va_list *ap, char d_flag);
void	d_flag_onestar(t_flag *flag, va_list *ap, char d_flag);
void	d_flag_twostar(t_flag *flag, va_list *ap, char d_flag);
void	d_flag_precision_most(t_flag *flag, char *int_str);
void	d_flag_strlen_most(t_flag *flag, char *int_str);
void	d_flag_width_most(t_flag *flag, char *int_str);
void	when_d_left_zero(char *int_str, t_flag *flag, int precision_zero);

void	i_specifier(char *s, va_list *ap);

void	u_specifier(char *s, va_list *ap);
char	*ft_utoa(unsigned int n);

void	p_specifier(char *s, va_list *ap);
void	p_flag_nostar(t_flag *flag, char *hexa_table, va_list *ap);
void	p_flag_onestar(t_flag *flag, char *hexa_table, va_list *ap);

void	x_specifier(char *s, va_list *ap);
void	x_flag_nostar(t_flag *flag, char *hex_table, va_list *ap);
void	x_flag_onestar(t_flag *flag, char *hex_table, va_list *ap);
void	x_flag_twostar(t_flag *flag, char *hex_table, va_list *ap);

void	x_flag_precision_most(t_flag *flag, char *hexa_str);
void	x_flag_strlen_most(t_flag *flag, char *hexa_str);
void	x_flag_width_most(t_flag *flag, char *hexa_str);
void	when_x_left_zero(char *hexa_str, t_flag *flag, int precision_zero);

void	X_specifier(char *s, va_list *ap);

void	percent_specifier(char *s, va_list *ap);
void	percent_flag_nostar(t_flag *flag, va_list *ap);
void	percent_flag_onestar(t_flag *flag, va_list *ap);
void	percent_flag_twostar(t_flag *flag, va_list *ap);

void	charge_hexa_str(long unsigned int n, char *hexa_str,
							int hexa_size, char *table);
char	*return_hexa_str(long unsigned int value, char *hex_table);
void	charge_hexa_table(char *array, char flag);
int		hexa_size(long unsigned int address);
void	charge_specifier_struct(t_specifier *matchup_array);
void	matchup_tag(char *tag_string, va_list *ap, t_specifier *matchup_array);

#endif
