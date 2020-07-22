#include "ft_printf.h"

int main()
{
	ft_printf("!%%!\n");
	ft_printf("!%23%!\n");
	ft_printf("!%023%!\n");
	ft_printf("!%-%!\n");
	ft_printf("!%.11%!\n");
	ft_printf("!%23.11%!\n");
	ft_printf("!%-23%!\n");
	ft_printf("!%-23.11%!\n");
	ft_printf("---------------------\n");
	ft_printf("!%-*.11%!\n",15);
	ft_printf("!%-12.*%!\n",14);
	ft_printf("!%*.*%!%s\n",32,24,"what are you doing here?");
	
	return (0);
}
