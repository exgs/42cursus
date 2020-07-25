#include "ft_printf.h"

int main()
{
	/*문자 플래그 실습*/
	// ft_printf("what%c %c %aa%%c %% %fsdlfsdfl%aaaac+++what\n",i++,i++,i++,i++,i++,i++);
	
	/*형식문자열에서 형식태그가 more than 가변인자 갯수*/
	// ft_printf("what%c+w%%h%ca%ct%ct%ct%ct%ct%ct%ct\n",i++);
	// printf("what%c+w%%h%ca%ct%ct%ct%ct%ct%ct%ct\n",i++);
	
	/*메모리주소 및 %x %X 16진법 계산하기*/
	char i = 65;
	void *address = &i;
	ft_printf("p x X : %p, %x, %X\n", address, address, address);
	printf("p x X : %p, %x, %X\n", address, address, address);
	printf("==============================\n");
	/*d i u 계산하기*/
	int a = 2147483647;
	int b = -1;
	// int c;
	unsigned int d = 2147483647;
	unsigned int e = -1;
	// unsigned int f;
	
	ft_printf("ft_printf a : d i u : %d, %i, %u\n", a, a, a);
	printf("a : d i u : %d, %i, %u\n", a, a, a);
	ft_printf("ft_printf b : d i u : %d, %i, %u\n", b, b, b);
	printf("b : d i u : %d, %i, %u\n", b, b, b);
	
	// ft_printf("ft_printf d : d i u : %d, %i, %u\n", d, d, d);
	// printf("d : d i u : %d, %i, %u\n", d, d, d);
	ft_printf("ft_printf e : d i u : %d, %i, %u\n", e, e, e);
	printf("e : d i u : %d, %i, %u\n", e, e, e);
	
	return (0);
}