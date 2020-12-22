#include "libasm.h"

void compare(int fd, int size)
{
	char buffer[100] = {0, };
	int ft; int real;

	errno = 0;
	ft = ft_read(fd, buffer, size);
	printf("%s\n", buffer);
	printf("ft : %d\n", ft);
	printf("errno : %d\n", errno);
	printf("----------------------\n");
	memset(buffer, 0, 100);

	errno = 0;
	real = read(fd, buffer, size);
	printf("%s\n", buffer);
	printf("real : %d\n", real);
	printf("errno : %d\n", errno);
	printf("=============================\n");
	return ;
}

void compare_noprintf(int fd, int size)
{
	char buffer[1000] = {0, };
	int ft; int real;
	
	errno = 0;
	ft = ft_read(fd, buffer, size);
	// printf("%s\n", buffer);
	printf("ft : %d\n", ft);
	printf("errno : %d\n", errno);
	printf("----------------------\n");
	memset(buffer, 0, 100);

	errno = 0;
	real = read(fd, buffer, size);
	// printf("%s\n", buffer);
	printf("real : %d\n", real);
	printf("errno : %d\n", errno);
	printf("=============================\n");
	return ;
}

int main()
{
	int fd;

	fd = open("./test", O_RDONLY);
	printf("Case 1\n");
	compare(fd, 3);
	close(fd);
	printf("Case 2\n");
	compare(fd, 3);
	
	printf("Exception 1\n");
	fd = open("./test", O_RDONLY);
	compare_noprintf(fd, 1000); //설명이 필요함
	close(fd);
	
	printf("Exception 2\n");
	char buffer[100] = {0, };
	int ft; int real; int size;
	size = 16;
	errno = 0;
	ft = ft_read(-1, buffer, size);
	printf("%s\n", buffer);
	printf("ft : %d\n", ft);
	printf("errno : %d\n", errno);
	printf("----------------------\n");
	memset(buffer, 0, 100);

	errno = 0;
	real = read(-1, buffer, size);
	printf("%s\n", buffer);
	printf("real : %d\n", real);
	printf("errno : %d\n", errno);
	printf("=============================\n");
	
	printf("Case 3\n");
	fd = open("./test", O_RDONLY);
	compare(fd, 0);
	close(fd);
	return (1);
}
