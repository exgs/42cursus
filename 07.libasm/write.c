#include <stdio.h>
#include "libasm.h"

void compare(int fd, char *str, int size)
{
	int ft; int real;
	ft = ft_write(fd, str, size);
	printf("ft : %d\n", ft);
	printf("errno : %d\n", errno);
	printf("----------------------\n");
	real = write(fd, str, size);
	printf("real : %d\n", real);
	printf("errno : %d\n", errno);
	printf("=============================\n");
	return ;
}

int main()
{
	compare(1, "abcd\n", 5);
	compare(-31, "abcd\n", 5);
	compare(0, "abcd\n", 5);
	
	compare(1, "abcd\n", 10);
	compare(0, "abcd\n", 10);
	compare(3, "abcd\n", 10);
	return (1);
}
