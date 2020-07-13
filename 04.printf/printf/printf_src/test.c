#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int main()
{
	// -, 0, .*, *
	
	printf("!%-.10d!\n",42);
	printf("X!%-0d!\n",42);//x
	printf("!%-10d!\n",42);
	printf("!%-*.10d!\n",4,42);
	printf("!%-*d!\n",3,42);
	printf("!%-.*d!\n",3,42); 
	printf("-1-\n");
	printf("X!%-0d!\n",3,42);//x 
	printf("X!%-0.*d!\n",3,42);//x 
	printf("X!%-0.d!\n",42); //x
	printf("!%10.20d!\n",42); 
	printf("!%10.0d!\n",42); 
	printf("-------------------------------\n");
	printf("!%-.10d!\n",-42);
	printf("X!%-0d!\n",-42);//x
	printf("!%-10d!\n",-42);
	printf("!%-*.10d!\n",4,-42);
	printf("!%-*d!\n",3,-42);
	printf("-2-\n");
	printf("!%-.*d!\n",3,-42); 
	printf("X!%-0.*d!\n",3,-42);//x
	printf("X!%0-.*d!\n",3,-42);//x 
	printf("X!%-0.d!\n",3,-42);//x
	printf("!%10.20d!\n",-42);
	return (0);
}