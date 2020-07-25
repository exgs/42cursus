#include "ft_printf.h"

int main()
{
	unsigned int i = 2147483648;
	// -, 0, .*, *
	ft_printf("!%10u!\n",42);
	ft_printf("!%10u!\n",i);
	ft_printf("!%10u!\n",(unsigned int)2147483648);
	ft_printf("!%13u!\n",(unsigned int)-1);
	ft_printf("!%013u!\n",(unsigned int)-1);
	ft_printf("!%-13u!\n",(unsigned int)-1);
	// ft_printf("!%-013u!\n",(unsigned int)-1);
	ft_printf("!%20u!\n",(unsigned int)-1);
	ft_printf("!%10u!\n",(unsigned int)42);
	ft_printf("X!%5u!\n",(unsigned int)42);
	ft_printf("-------------------------------\n");
	// ft_printf("!%-.*u!\n",3,-42);
	ft_printf("------------Size를 기준으로 생각해보자-----------------\n");
	ft_printf("|너비|정확도|길이|\n");
	ft_printf("| 9 | 7 | 5 | :%9.7u\n",12345);
	ft_printf("| 9 | 3 | 5 | :%9.3u\n",12345);
	ft_printf("| 3 | 9 | 5 | :%3.9u\n",12345);
	ft_printf("| 7 | 9 | 5 | :%7.9u\n",12345);
	ft_printf("| 4 | 3 | 5 | :%4.3u\n",12345);
	ft_printf("| 3 | 4 | 5 | :%3.4u\n",12345);
	ft_printf("-------------마이너스 값이 들어올 때를 기준으로 생각해보자-----------------\n");
	ft_printf("| 9 | 7 | 5 | :%9.7u\n",(unsigned int)-1234);
	ft_printf("| 9 | 3 | 5 | :%9.3u\n",(unsigned int)-1234);
	ft_printf("| 3 | 9 | 5 | :%3.9u\n",(unsigned int)-1234);
	ft_printf("| 7 | 9 | 5 | :%7.9u\n",(unsigned int)-1234);
	ft_printf("| 4 | 3 | 5 | :%4.3u\n",(unsigned int)-1234);
	ft_printf("| 3 | 4 | 5 | :%3.4u\n",(unsigned int)-1234);
	return (0);
}
