/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:06:24 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/12 02:22:22 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*connect_string = "\0"; //static일 이유가 없는데, "\0"이여야만 맨 처음에 ft_strdup할 때 heap이 가능해서..
	static int	validation = -2;

	if (line == NULL || BUFFER_SIZE <= 0) //첫 줄 조차 읽지 못하는 경우
		return (-1);
	if (validation == -2) //맨 처음 파일을 열었을 때, read에 담는 그릇에 오물이 없게 하기 위해서!
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
	if (if_newline_remain_in_buffer(buffer, line) == 1) //buffer에 개행이 있는 경우-> read함수를 진행하지 않기 위함.
		return (1);
	else
		connect_string = ft_strdup(buffer); //buffer에 개행이 없는 경우 -> connect_string 옮겨 담음.
	ft_memset(buffer, 0, BUFFER_SIZE + 1); // (dirty remains in buffer && read EOF(다 채우지 못한 경우)) 어디까지 읽어야하는지 모르니깐..'\0'이 필요해!
	while ((validation = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (read_until_newline(&connect_string, buffer, line) == 1) //개행 문자가 나올때 까지 읽기. 개행문자가 없는 경우 EOF까지 접근하여, while문을 빠져나오게 됨
			return (1);
	}
	if (validation == -1) //에러 처리. 빠져나오도록
	{
		free(connect_string);
		return (-1);
	}
	*line = connect_string;
	return (0); //read의 마지막 순간, EOF를 만날때, 실행되는 return;
	//++ 아쉬운점 get_next_line(int fd, char **line)의 return이 마지막에 한번 실행된다는 건 일반적인 코드와는 상이한 것 같아서 아쉽다.
}

int		if_newline_remain_in_buffer(char *buffer, char **line)
{
	if (change_newline_to_zero(buffer))
	{
		*line = ft_strdup(buffer);
		ft_strlcpy_buff(buffer, ft_strchr(buffer, 0) + 1, BUFFER_SIZE + 1);
		return (1);
	}
	return (0);
}

int		change_newline_to_zero(char *buffer)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

size_t	ft_strlcpy_buff(char *dst, char *src, size_t dstsize)
{
	size_t			i;
	unsigned int	src_len;

	if (src == 0 || dst == 0)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (i < dstsize)
	{
		dst[i] = 0;
		i++;
	}
	return (src_len);
}

int		read_until_newline(char **connect_string, char *buffer, char **line)
{
	char *connect_string_shadow;

	connect_string_shadow = *connect_string;
	if (change_newline_to_zero(buffer))
	{
		*connect_string = ft_strjoin(connect_string_shadow, buffer);
		ft_strlcpy_buff(buffer, ft_strchr(buffer, 0) + 1, BUFFER_SIZE + 1);
		*line = *connect_string;
		free(connect_string_shadow);
		return (1);
	}
	*connect_string = ft_strjoin(connect_string_shadow, buffer);
	free(connect_string_shadow);
	ft_memset(buffer, 0, BUFFER_SIZE);
	return (0);
}
