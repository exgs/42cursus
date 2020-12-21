/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 17:34:51 by yunslee           #+#    #+#             */
/*   Updated: 2020/12/12 18:41:51 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

extern int	ft_read(int fd, char *buf, int size);
extern int	ft_write(int fd, char *buf, int size);
extern int	ft_strlen(char *str);
extern int	ft_strcmp(char *s1, char *s2);
extern char	*ft_strcpy(char *dst, char *src);
extern char	*ft_strdup(char *str);

#endif
