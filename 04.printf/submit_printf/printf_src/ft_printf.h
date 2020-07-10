/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 02:30:02 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/10 19:53:46 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
 #define FT_PRINTF_H
 #define LOWERCASE 0
 #define UPPERCASE 1
 #include "../libft/libft.h"//temporary
 #include <stdio.h>//temporary
 #include <stdlib.h>
 #include <unistd.h>
 #include <stdarg.h>
 
typedef struct s_specifier
{
	char array_specifier[10];
	void (*function_specifier[10])(char *, va_list *);
}				t_specifier;
 
int ft_printf(const char *, ...);
char *read_format(char *str, va_list *ap);
char *read_format_tag(char *str, int *i);
void read_non_format(char *str, int *i);

void c_specifier(char *s, va_list *ap);
void s_specifier(char *s, va_list *ap);
void d_specifier(char *s, va_list *ap);
void i_specifier(char *s, va_list *ap);
void u_specifier(char *s, va_list *ap);
char *ft_utoa(unsigned int n);

void p_specifier(char *s, va_list *ap);
void x_specifier(char *s, va_list *ap);
void X_specifier(char *s, va_list *ap);
void percent_specifier(char *s, va_list *ap);

void write_deical_to_hex(unsigned int n, char *hex_array);
void charge_hex_array(char *array, char flag);
 
#endif