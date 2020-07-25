#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("!%%!\n");
	printf("!%23%!\n");
	printf("!%023%!\n");
	printf("!%-%!\n");
	printf("!%.11%!\n");
	printf("!%23.11%!\n");
	printf("!%-23%!\n");
	printf("!%-23.11%!\n");
	printf("---------------------\n");
	printf("!%-*.11%!\n",15);
	printf("!%-12.*%!\n",14);
	printf("!%*.*%!%s\n",32,24,"what are you doing here?");
	
	return (0);
}
