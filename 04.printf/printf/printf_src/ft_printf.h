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
 #include "../libft/libft.h"//temporary
 #include "../libft_plus/libft_plus.h"//temporary

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
	char star;
	char dot;
}	t_flag;

typedef struct s_data
{
	int space;
	int precision;
}	t_data;

int ft_printf(const char *, ...);
char *read_format(char *str, va_list *ap);
char *read_format_tag(char *str, int *i);
void read_non_format_tag(char *str, int *i);
void printf_tag(char *tag_string, va_list *ap);

void flag_decision(char *str, t_flag *flag);
void flag_printspace(char *str);
int flag_return_atoi(char *str);

void c_specifier(char *s, va_list *ap);
void c_print_normal(t_flag *flag, va_list *ap);
void c_flag_minus(char *str, t_flag *flag, va_list *ap);
void c_flag_unnormal(char *str, t_flag *flag, va_list *ap);

void s_specifier(char *s, va_list *ap);
void s_print_normal(t_flag *flag, va_list *ap);
void s_flag_minus(char *str, t_flag *flag, va_list *ap);
void s_flag_unnormal(char *str, t_flag *flag, va_list *ap);
void s_flag_dot(char *str_tag, t_flag *flag, va_list *ap);

void d_specifier(char *s, va_list *ap);
void i_specifier(char *s, va_list *ap);
void u_specifier(char *s, va_list *ap);
char *ft_utoa(unsigned int n);

void p_specifier(char *s, va_list *ap);
void x_specifier(char *s, va_list *ap);
void X_specifier(char *s, va_list *ap);
void percent_specifier(char *s, va_list *ap);

void write_deical_to_hex(unsigned int n, char *hex_array, int num);
void charge_hex_array(char *array, char flag);
void charge_specifier_struct(t_specifier *matchup_array);
void matchup_tag(char *tag_string, va_list *ap, t_specifier *matchup_array);
 
#endif