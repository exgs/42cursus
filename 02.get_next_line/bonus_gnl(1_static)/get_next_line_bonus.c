/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 19:06:24 by yunslee           #+#    #+#             */
/*   Updated: 2020/07/06 02:38:09 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_sub(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];//-D BUFFER_SIZE 만큼 읽음.
	char		*oneline_string; // *line = oneline_string; line에 값을 할당해주기 위한 변수.
	static char	*remain_string[1000] = {0, }; // 여러파일을 읽으면 각각의 개행이후의 값을 저장하는 static이 배열로써 존재함.
	int			validation; // read의 return 값;

	if (exist_newline_in_remain_string(remain_string, fd, line) == 1)//buffer_size가 매우 큰 경우 static에 개행이 몇개 들어와있을 수 있다. 이때 read함수를 실행시키지 않고, 맨 처음에 있는 개행문자를 기준으로 분절시키는 함수
		return (1);
	ft_memset(buffer, 0, (BUFFER_SIZE + 1)); //read로 담기 이전에 buffer를 깨끗이 청소해줌
	while ((validation = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (read_until_newline(buffer, fd, &oneline_string, remain_string) == 1)//개행이 buffer에 하나 이상 담길 때 while문과 gnl을 탈출할 수 있다.
		{
			*line = oneline_string;
			return (1);
		}
		ft_memset(buffer, 0, BUFFER_SIZE);
	}
	if (validation == -1) //open으로 fd에 할당되지않은 임의의 정수일 때
	{
		// *line = ft_strdup(""); 넣어주면 좋긴한데, 줄 수 제한때문에 빼도록한다.
		return (-1);
	}
	*line = ft_strdup(remain_string[fd]);
	free(remain_string[fd]);
	remain_string[fd] = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int return_value;

	if (BUFFER_SIZE <=0 || line == NULL) //line에 값을 할당해주지않고 return, fd값에 대한 에러는 line에 빈문자열을 할당해주고 return한다.
	{
		return (-1);
	}
	if (1 == (return_value = get_next_line_sub(fd, line)))
		return (1);
	else if (return_value == 0)
		return (0);
	else if (return_value == -1)
		return (-1);
	return(-1);
}

//buffer_size가 매우 큰 경우 static에 개행이 몇개 들어와있을 수 있다. 이때 read함수를 실행시키지 않고, 맨 처음에 있는 개행문자를 기준으로 분절시키는 함수
int exist_newline_in_remain_string(char **remain_string, int fd, char **line)
{
	char *remain_string_shadow;
	char *oneline_string;
	char *temp;

	if (fd < 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (remain_string[fd] == NULL)
		return (0);
	remain_string_shadow = remain_string[fd];
	if (change_newline_to_zero(remain_string[fd]))
	{
		oneline_string = ft_strdup(remain_string[fd]);
		*line = oneline_string;
		temp = ft_strdup(ft_strchr(remain_string[fd], 0) + 1);
		free(remain_string[fd]);
		remain_string[fd] = temp;
		return (1);
	}
	return (0);
}

//buffer에 있는 내용을 읽으면서 개행이 있으면, 가장 앞에오는 개행에 대해서만 '\0'으로 바꿔주고 return(true);
int		change_newline_to_zero(char *buffer)
{
	int i;

	i = 0;
	while (buffer[i])
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

// change_newline_to_zero()함수를 통해 개행이 있을 때 return(1)(=gnl함수의 탈출조건),otherwise staitc variable에 계속 내용을 붙여줌
int		read_until_newline(char *buffer, int fd, char **oneline_string, char **remain_string)
{
	char *remain_string_shadow;

	remain_string_shadow = remain_string[fd];
	if (change_newline_to_zero(buffer))
	{
		*oneline_string = ft_strjoin(remain_string[fd], buffer);
		remain_string[fd] = ft_strdup(ft_strchr(buffer, 0) + 1);
		free(remain_string_shadow);
		return (1);
	}
	remain_string[fd] = ft_strjoin(remain_string[fd], buffer);
	free(remain_string_shadow);
	return (0);
}
