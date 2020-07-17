#include "ft_printf.h"

int main()
{
	// ft_printf("i %%c : %d %c\n",i,i);
	ft_printf("!%10c!\n",'A');
	ft_printf("!%1c!\n",'A');
	ft_printf("!%*c!\n",1,'A');
	ft_printf("!%*c!\n",23, 'A');
	ft_printf("!%-10c!\n",'A');
	
	ft_printf("-1-\n");
	ft_printf("i %%c : %c\n",'A');
	ft_printf("X!%-.10c!\n",'A');
	ft_printf("X!%-0c!\n",'A');//x
	ft_printf("!%-10c!\n",'A');
	ft_printf("X!%-*.10c!\n",5,'A');
	ft_printf("!%-*c!\n",5,'A');
	ft_printf("X!%-.*c!\n",5,'A'); 
	ft_printf("-1-\n");
	ft_printf("X!%-0c!\n",'A');//x 
	ft_printf("X!%-0.*c!\n",5, 'A');//x 
	ft_printf("X!%-0.c!\n",'A'); //x
	ft_printf("X!%10.20c!\n",'A'); 
	ft_printf("X!%10.0c!\n",'A'); 
	
	return (0);
}