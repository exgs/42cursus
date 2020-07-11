/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:51:55 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/06 01:50:08 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		get_next_line(int fd, char **line);
void	*ft_memset(void *dest, int c, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		change_newline_to_zero(char *buffer);
size_t	ft_strlcpy_buff(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		read_until_newline(char **connect_string, char *buffer, char **line);
int		if_newline_remain_in_buffer(char *buffer, char **line);
#endif
