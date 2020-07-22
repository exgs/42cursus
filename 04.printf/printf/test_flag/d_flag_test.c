#include "ft_printf.h"

int main()
{
	// -, 0, .*, *
	ft_printf("!%-.10d!\n",42);
	// ft_printf("X!%-0d!\n",42);//x
	ft_printf("!%-10d!\n",42);
	ft_printf("!%-*.10d!\n",4,42);
	ft_printf("!%-*d!\n",3,42);
	ft_printf("!%-.*d!\n",3,42);
	ft_printf("-1-\n");
	// ft_printf("X!%-0d!\n",3,42);//x
	// ft_printf("X!%-0.*d!\n",3,42);//x
	// ft_printf("X!%-0.d!\n",42); //x
	ft_printf("!%10.20d!\n",42);
	ft_printf("!%10.5d!\n",42);
	ft_printf("!%-10.5d!\n",42);
	ft_printf("-------------------------------\n");
	ft_printf("!%-.10d!\n",-42);
	// ft_printf("X!%-0d!\n",-42);//x
	ft_printf("!%-10d!\n",-42);
	ft_printf("!%-*.10d!\n",4,-42);
	ft_printf("!%-*d!\n",3,-42);
	ft_printf("-2-\n");
	ft_printf("!%-.*d!\n",3,-42);
	// ft_printf("X!%-0.*d!\n",3,-42);//x
	// ft_printf("X!%0-.*d!\n",3,-42);//x
	// ft_printf("X!%-0.d!\n",3,-42);//x
	ft_printf("!%10.20d!\n",-42);
	ft_printf("------------Size를 기준으로 생각해보자-----------------\n");
	ft_printf("|너비|정확도|길이|\n");
	ft_printf("| 9 | 7 | 5 | :%9.7d\n",12345);
	ft_printf("| 9 | 3 | 5 | :%9.3d\n",12345);
	ft_printf("| 3 | 9 | 5 | :%3.9d\n",12345);
	ft_printf("| 7 | 9 | 5 | :%7.9d\n",12345);
	ft_printf("| 4 | 3 | 5 | :%4.3d\n",12345);
	ft_printf("| 3 | 4 | 5 | :%3.4d\n",12345);
	ft_printf("-------------마이너스 값이 들어올 때를 기준으로 생각해보자-----------------\n");
	ft_printf("| 9 | 7 | 5 | :%9.7d\n",-1234);
	ft_printf("| 9 | 3 | 5 | :%9.3d\n",-1234);
	ft_printf("| 3 | 9 | 5 | :%3.9d\n",-1234);
	ft_printf("| 7 | 9 | 5 | :%7.9d\n",-1234);
	ft_printf("| 4 | 3 | 5 | :%4.3d\n",-1234);
	ft_printf("| 3 | 4 | 5 | :%3.4d\n",-1234);

	return (0);
}
