#include "libasm.h"

void compare(char *str)
{
	int ft; int real;
	ft = ft_strlen(str);
	printf("ft : %d\n", ft);
	printf("errno : %d\n", errno);
	printf("----------------------\n");
	real = strlen(str);
	printf("real : %d\n", real);
	printf("errno : %d\n", errno);
	printf("=============================\n");
	return ;
}

int main()
{
	// char *str = NULL; -> segfault
	// int a;
	// a = ft_strlen(str);
	// printf("%d\n", a);
	
	compare("sldfksjdlf\n\0");
	compare("s0");
}
