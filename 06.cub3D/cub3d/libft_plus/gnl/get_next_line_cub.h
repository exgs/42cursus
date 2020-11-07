/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_cub.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 18:51:55 by yunslee           #+#    #+#             */
/*   Updated: 2020/11/07 21:15:23 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_CUB_H
# define GET_NEXT_LINE_CUB_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		get_next_line_sub(int fd, char **line);
int		get_next_line(int fd, char **line);
int		read_until_newline(char *buffer, int fd,
							char **oneline_string, char **remain_string);
int		change_newline_to_zero(char *buffer);
int		exist_newline_in_remain_string(char **remain_string,
							int fd, char **line);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strdup2(const char *str);
void	*ft_memset2(void *dest, int c, size_t len);
char	*ft_strchr2(const char *s, int c);
size_t	ft_strlen2(const char *s);
char	**get_datas_linebyline(char *path);
int		get_free_all_linebyline(char **lines);

#endif
