#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int i = -20;
	int count = 200;
	// ft_printf("i %%c : %d %c\n",i,i);

	ft_printf("%s\n","");
	ft_printf("%s\n","abc");
	ft_printf("%s\n","\n");
	ft_printf("%s\n","\n\n");
	ft_printf("%s\n"," ");
	ft_printf("%s\n","  ");
	ft_printf("%s\n","	");
	ft_printf("%s\n","		");
	ft_printf("%s\n",0);
	ft_printf("%s\n");
	
	return (0);
}