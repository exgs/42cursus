#include "get_next_line.h"

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	if ((fd = open("abc.txt", O_RDONLY)) == -1)
		fd = 0;
	printf("fd : %d\n",fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	// printf("start\n");
	printf("%s\n", line);
	free(line);
	return (0);
}