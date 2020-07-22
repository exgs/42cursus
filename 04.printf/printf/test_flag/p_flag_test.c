#include "ft_printf.h"

typedef struct s_node
{
	void *data;
}	t_node;


int main()
{
	int a = 123;
	int *num;
	char *rdonly = "abcedfg";
	num = &a;

	t_node *node;
	node = malloc(sizeof(t_node));

	// -, 0, .*, *
	// printf("%.2p\n", NULL);
	// printf("!%10.1p!\n", node);
	// printf("!%p!\n", num);
	// printf("!%023.1p!\n", num);
	// printf("!%-.100p!\n",num);
	ft_printf("----------------ft_printf-----------------\n");
	ft_printf("!%23p!\n", rdonly);
	ft_printf("!%-23p!\n", rdonly);
	ft_printf("!%23p!\n", num);
	ft_printf("!%-23p!\n", num);
	ft_printf("!%23p!\n", node);
	ft_printf("!%-23p!\n", node);
	ft_printf("----------------printf----------------\n");
	printf("!%23p!\n", rdonly);
	printf("!%-23p!\n", rdonly);
	printf("!%23p!\n", num);
	printf("!%-23p!\n", num);
	printf("!%23p!\n", node);
	printf("!%-23p!\n", node);

	free(node);
	return (0);
}
