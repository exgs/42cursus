#include "ft_printf.h"

int main()
{
	printf("!%10c!\n",'A');
	printf("!%1c!\n",'A');
	printf("!%*c!\n",1,'A');
	printf("!%*c!\n",23, 'A');
	printf("!%-10c!\n",'A');

	printf("-1-\n");
	printf("i %%c : %c\n",'A');
	printf("X!%-.10c!\n",'A');
	printf("X!%-0c!\n",'A');//x
	printf("!%-10c!\n",'A');
	printf("X!%-*.10c!\n",5,'A');
	printf("!%-*c!\n",5,'A');
	printf("X!%-.*c!\n",5,'A');
	printf("-1-\n");
	printf("X!%-0c!\n",'A');//x
	printf("X!%-0.*c!\n",5, 'A');//x
	printf("X!%-0.c!\n",'A'); //x
	printf("X!%10.20c!\n",'A');
	printf("X!%10.0c!\n",'A');

	return (0);
}
