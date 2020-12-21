#include "libasm.h"

int main()
{
	char *dst; 
	// char *src = NULL;
	char s1[30] = "01234567890123456789\0";
	// char s2[20] = "abcedfghij\0";
	
	dst = ft_strdup(0);
	printf("%p\n", dst);
	printf("%s\n", dst);
	dst = NULL;
	system("leaks a.out");	
}
