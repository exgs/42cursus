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
	printf("!%10.1s!\n","123456789");
	write(1, buffer, 50);
	// printf("!%-.100s!\n","hello,worl");
	// printf("x!%-0s!\n","hello,worl");
	// printf("!%-10s!\n","hello,worl");
	// printf("!%-*.10s!\n",4,"hello,worl");
	// printf("!%-*s!\n",3,"hello,worl");
	// printf("!%-3s!\n","hello,worl");
	// printf("!%3s!\n","hello,worl");
	// printf("!%17s!\n","hello,worl");
	// printf("!%-.*s!\n",3,"hello,worl");
	// printf("!%-.*s!\n",17,"hello,worl");
	// printf("!%-*.*s!\n",20,4,"hello,worl");
	// printf("-1-\n");
	// printf("x!%-0s!\n",3,"hello,worl");//x 
	// printf("X!%-0.*s!\n",3,"hello,worl");//x 
	// printf("X!%-0.s!\n","hello,worl"); //x
	// printf("!%102s!\n","hello,worl"); 
	// printf("!%10.0s!\n","hello,worl"); 
	// printf("-------------------------------\n");
	// printf("!%-.10s!\n","hello,worl");
	// printf("X!%-0s!\n","hello,worl");//x
	// printf("!%-10s!\n","hello,worl");
	// printf("!%-*.10s!\n",4,"hello,worl");
	// printf("!%-*s!\n",3,"hello,worl");
	// printf("-2-\n");
	// printf("!%-.*s!\n",3,"hello,worl"); 
	// printf("X!%-0.*s!\n",3,"hello,worl");//x
	// printf("X!%0-.*s!\n",3,"hello,worl");//x 
	// printf("X!%-0.s!\n",3,"hello,worl");//x
	// printf("!%10.20s!\n","hello,worl");
	return (0);
}