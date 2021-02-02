#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open("./test", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	free(line);
	printf("%d\n", get_next_line(fd, &line));
}
