#include "libasm.h"

int main()
{
	char *dst = NULL; char *src; //둘 중 하나라도 NULL인 경우 strcmp -> segfault
	char s1[30] = "00001000000\0";
	char s2[20] = "000aa000000\0";
	int i;
	i = ft_strcmp(s2,s1);
	printf("%d\n", i);
}
