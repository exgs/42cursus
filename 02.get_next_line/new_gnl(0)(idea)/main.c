#include <stdio.h>
#include <sys/fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char *line = 0;
	int ret;
	int fd;
	fd = open("./test_files/test2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		// printf("ret : %d\n",ret);
		printf("%s\n", line);
		free(line);
	}
	// printf("ret : %d\n",ret);
	printf("%s\n", line);
	free(line);
	close(fd);
	
	// system("leaks a.out > leaks_result; cat leaks_result");
	return (0);
}