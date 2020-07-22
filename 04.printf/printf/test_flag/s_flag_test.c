#include "ft_printf.h"

int main()
{
	// -, 0, .*, *
	ft_printf("%.2s\n",NULL);
	ft_printf("!%10.1s!\n","123456789");
	ft_printf("!%-.100s!\n","hello,worl");
	ft_printf("x!%-0s!\n","hello,worl");
	ft_printf("!%-10s!\n","hello,worl");
	ft_printf("!%-*.10s!\n",4,"hello,worl");
	ft_printf("!%-*s!\n",3,"hello,worl");
	ft_printf("!%-3s!\n","hello,worl");
	ft_printf("!%3s!\n","hello,worl");
	ft_printf("!%17s!\n","hello,worl");
	ft_printf("!%-.*s!\n",3,"hello,worl");
	ft_printf("!%-.*s!\n",17,"hello,worl");
	ft_printf("!%-*.*s!\n",20,4,"hello,worl");
	ft_printf("-1-\n");
	ft_printf("x!%-0s!\n","hello,worl");//x
	ft_printf("X!%-0.*s!\n",3,"hello,worl");//x
	ft_printf("X!%-0.s!\n","hello,worl"); //x
	ft_printf("!%102s!\n","hello,worl");
	ft_printf("!%10.0s!\n","hello,worl");
	ft_printf("-------------------------------\n");
	ft_printf("!%-.10s!\n","hello,worl");
	ft_printf("X!%-0s!\n","hello,worl");//x
	ft_printf("!%-10s!\n","hello,worl");
	ft_printf("!%-*.10s!\n",4,"hello,worl");
	ft_printf("!%-*s!\n",3,"hello,worl");
	ft_printf("-2-\n");
	ft_printf("!%-.*s!\n",3,"hello,worl");
	ft_printf("X!%-0.*s!\n",3,"hello,worl");//x
	ft_printf("X!%0-.*s!\n",3,"hello,worl");//x
	// ft_printf("X!%-0.s!\n",3,"hello,worl");//x 대응되는 숫자가 다른 경우
	ft_printf("!%10.20s!\n","hello,worl");
	return (0);
}
