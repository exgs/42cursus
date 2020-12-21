#include "libasm.h"

int main()
{
	char *dst; char *src; //둘 중 하나라도 NULL인 경우 strcpy -> segfault
	char s1[30] = "01234567890123456789\0";
	char s2[20] = "abcedfghij\0";
	
	dst = strcpy(s2, s1);
	// printf("%s\n",dst);
}
