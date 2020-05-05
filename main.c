#include "stack.h"

void print_array(char *array)
{
	for (size_t i = 0; i < 26; i++)
	{
		printf("%c\n",array[i]);
	}
}

void print_stack(t_stack * stack)
{
	printf("max size : %d\n", stack->max_size);
	printf("top_inex : %d\n", stack->top_index);

	for (size_t i = 0; (i <= stack->top_index && stack->top_index != -1); i++)
	{
		printf("data : %s\n", stack->data[i]);
	}

}


int main()
{
	unsigned int max = 100;
	char a= 'a';
	char alphabet[27];
	t_stack *init;

	for (size_t i = 0; i < 26; i++)
	{
		alphabet[i] = a;
		a++;
	}
	alphabet[26] = 0;
	init = stack_init(0);
	printf("%p\n",init);
	free_stack(init, free);
	init = stack_init(-2100);
	printf("%p\n",init);
	free_stack(init, free);
	init = stack_init(max);
	printf("%p\n",init);

	for (size_t i = 0; i < 26; i++)
	{
		stack_push(init, &alphabet[i]);
	}
	print_stack(init);

	printf("stack_size : %d\n", stack_size(init));
	printf("stack_peak : %s\n", stack_peek(init));

	for (size_t i = 0; i < 26; i++)
	{
		printf("stack_pop : %s\n",stack_pop(init));
	}
	print_stack(init);

	free_stack(init, free);

	return (0);
}