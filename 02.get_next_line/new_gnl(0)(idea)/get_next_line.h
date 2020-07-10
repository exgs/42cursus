#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 2
#endif

int		get_next_line(int fd, char **line);
void	*ft_memset(void *dest, int c, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		change_newline_to_zero(char *buffer);
size_t	ft_strlcpy_modified(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *dest, int c, size_t len);