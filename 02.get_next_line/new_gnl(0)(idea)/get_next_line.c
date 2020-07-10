#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	static char buffer[BUFFER_SIZE + 1];
	static char *connect_string = "\0";
	char *connect_string_shadow;
	static int validation = 1;
	
	buffer[BUFFER_SIZE] = '\0'; //맨 처음에 '\n'문자가 buffer에 들어가있으면 어떻하지?
	if (change_newline_to_zero(buffer))
	{
		*line = ft_strdup(buffer);
		ft_strlcpy_modified(buffer, ft_strchr(buffer, 0) + 1, BUFFER_SIZE + 1);//마지막 '\0'값을 넘어가지 못함!
		return (1);
	}
	else if (validation == 0)
		return (0);
	/*여기서 부턴 개행문자가 없는 buffer에 있는 내용을 malloc에 넘겨서 진행한다.*/
	connect_string = ft_strdup(buffer);
	while ((validation = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (validation == -1)
		{
			free(connect_string); //connect_string이 *line로 넘어가니깐 필요없음
			return (-1);
		}
		// printf("Check\n");
		// printf("%s\n",buffer);
		connect_string_shadow = connect_string;
		if (change_newline_to_zero(buffer))
		{
		connect_string = ft_strjoin(connect_string_shadow, buffer);
		ft_strlcpy_modified(buffer, ft_strchr(buffer, 0) + 1, BUFFER_SIZE + 1);//마지막 '\0'값을 넘어가지 못함!
		*line = connect_string;
		free(connect_string_shadow); //한번은 거쳤을꺼니깐. 항상 malloc되어있음.
		return (1);
		}
		connect_string = ft_strjoin(connect_string_shadow, buffer);
		free(connect_string_shadow);
		ft_memset(buffer, 0, BUFFER_SIZE); //read함수는 '\0'을 buffer에 쓰지 못하기때문에, BUFFER_SIZE가 작아서 여러번 읽어야하는 경우, 이전에 씌여졌던 내용까지도 읽게 될 수 있다.(aaa -> "aaaa" when BUFFER_SIZE = 2)
	}
	*line = connect_string;
	return (0);
}

int	change_newline_to_zero(char *buffer)
{
	int i;
	
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if(buffer[i] == '\n')
		{
			buffer[i] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = dest;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}
