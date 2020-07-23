#include "ft_printf.h"

int main()
{
	printf ("%d\n\n",  printf("453c[%0*.*d]",   -5, -10, -7));
	printf ("%d\n\n",  printf("453c[%0*.*d]",   -5, 10, -7));
	printf ("%d\n\n",  printf("453c[%0*.*d]",   -13, -10, -7));
	printf ("%d\n\n",  printf("453c[%0*.*d]",   -13, 10, -7));
	printf("----------------\n");
	printf("%12.*d\n",-3, -12);
	printf("%12d\n", -12);
	printf("%012.*d\n",-3, -12);
	printf("%012d\n", -12);
	printf("-------tricky---------\n");
	printf ("%d\n\n",  printf("450[%*.d]", 12,  0));
	printf ("%d\n\n",  printf("450[%*.d]", 12,  22));
	printf ("%d\n\n",  printf("450[%*.d]", 12,  -0));
	printf ("%d\n\n",  printf("450[%*.d]", 12,  -0));
	printf("----------------\n");
	printf ("%d\n\n",  printf("450[%*.0d]", 12,  0));
	printf ("%d\n\n",  printf("450[%*.0d]", 12,  22));
	printf ("%d\n\n",  printf("450[%*.0d]", 12,  -0));
	printf ("%d\n\n",  printf("450[%*.0d]", 12,  -0));
	// printf ("%d\n\n",  printf("450[%*.-2d]", 12,  -0));
	printf("----------------\n");
	printf ("%d\n\n",  printf("450[%*d]", 12,  -0));
	printf ("%d\n\n",  printf("450[%*.0d]", 12,  -0));
	printf ("%d\n\n",  printf("450[%*.1d]", 12,  -0));
	printf ("%d\n\n",  printf("450[%*.2d]", 12,  -0));
	printf("-------tricky222---------\n");
	printf ("%d\n\n",  printf("[%10.*d]", 12,  -123));
	printf ("%d\n\n",  printf("[%10.*d]", -12,  -123));
	printf ("%d\n\n",  printf("[%10.*d]", 0, -123));
	printf ("%d\n\n",  printf("[%10.*d]", 12,  0));
	printf ("%d\n\n",  printf("[%10d]",  0));
	printf ("%d\n\n",  printf("[%10.*d]", -12,  0));
	printf ("%d\n\n",  printf("[%10.*d]", 0, 0));
	printf ("%d\n\n",  printf("[%10.d]", 0));
	return (0);
}
