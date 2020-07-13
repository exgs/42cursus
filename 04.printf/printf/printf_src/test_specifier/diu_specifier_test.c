#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0;
	int b = -100;
	int c = 100;
	int d = 2147483647;
	int e = -2147483648;
	int f = 2147483648;int g = -2147483649;

	unsigned int h = 0;
	unsigned int i = 1040;
	unsigned int j = 4294967295;unsigned int k = 4294967296;
	printf("%%---------%%d-------%%\n");
	printf("%d\n",a);printf("%d\n",b);printf("%d\n",c);
	printf("%d\n",d);printf("%d\n",e);printf("%d\n",f);
	printf("%d\n",g);printf("%d\n",h);
	printf("%d\n",i);printf("%d\n",j);printf("%d\n",k);
	
	printf("%%---------%%i--------%%\n");
	printf("%i\n",a);printf("%i\n",b);printf("%i\n",c);
	printf("%i\n",d);printf("%i\n",e);printf("%i\n",f);
	printf("%i\n",g);printf("%i\n",h);
	printf("%i\n",i);printf("%i\n",j);printf("%i\n",k);
	
	printf("%%---------%%u--------%%\n");
	printf("%u\n",a);printf("%u\n",b);printf("%u\n",c);
	printf("%u\n",d);printf("%u\n",e);printf("%u\n",f);
	printf("%u\n",g);printf("%u\n",h);
	printf("%u\n",i);printf("%u\n",j);printf("%u\n",k);
	
	
	return (1);
}