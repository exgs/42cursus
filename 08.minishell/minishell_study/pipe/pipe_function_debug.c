#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct s_data
{
	int pipe[2];
}t_data;

int main()
{
	t_data a;
	int *pipe2;
	pipe2 = a.pipe;
	
	pipe(pipe2);
	close(pipe2[0]);
	close(pipe2[1]);
	pipe(pipe2);
	printf("%d\n", close(4));
	return (0);
}