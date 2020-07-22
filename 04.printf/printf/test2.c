#include <stdio.h>
// cspdiuxX%

int hexa_size(long unsigned int address)
{
	int size;

	size = 0;
	if (address == 0)
		return (1);
	while (address != 0)
	{
		address /= 16;
		size++;
	}
	return (size);
}

int main()
{
	long unsigned int a = 0x0; //6자리 수
	int temp = hexa_size(a);
	printf("size : %d\n", temp);
	return (0);
}
