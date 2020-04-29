#include "get_next_line.h"

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	if (fd = open("ab2c.txt", O_RDONLY))
		fd = 0;
	printf("fd : %d\n",fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}