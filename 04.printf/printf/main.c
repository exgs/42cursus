#include "ft_printf.h"

int main()
{
	// -, 0, .*, *
	// printf("%10s\n",NULL);
	char buffer[100];
	buffer[0]= 'a';
	buffer[1]= 'a';
	buffer[2]= 'a';
	buffer[3]= '\0';
	buffer[4] = '!';
	ft_printf("!%10.1s!\n","123456789");
	write(1, buffer, 50);
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
	ft_printf("x!%-0s!\n",3,"hello,worl");//x 
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
	ft_printf("X!%-0.s!\n",3,"hello,worl");//x
	ft_printf("!%10.20s!\n","hello,worl");
	return (0);
}