#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int i = -20;
	int count = 200;

	while (i < count)
	{
		// ft_printf("i %%c : %d %c\n",i,i);
		printf("i %%c : %d %c\n",i,i);
		i++;
	}
	
	return (0);
}