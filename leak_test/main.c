#include "stack.h"


void print_stack(t_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return ;
	t_node *curr_stack;
	curr_stack = stack->top;

	while (curr_stack != NULL)
	{
		printf("%s\n", curr_stack->data);
		curr_stack = curr_stack->next;
	}
	return ;
}

int main()
{
	printf("--------------Let's start!-----------\n");

	char a= 'a';
	char * alphabet[26];
	int count = 26;
	t_stack *init;
	t_node *temp;

	for (size_t i = 0; i < count; i++)
	{
		alphabet[i] = malloc(2);
		alphabet[i][0] = a;
		alphabet[i][1] = 0;
		a++;
	}

	// for (size_t i = 0; i < 26; i++)
	// {
	// 	printf("%s\n",alphabet[i]);
	// }

	t_stack *lint_stack;

	lint_stack = stack_init();
	for (size_t i = 0; i < count; i++)
	{
		printf("success of fail : %d\n", stack_push(lint_stack, alphabet[i]));
	}

	print_stack(lint_stack);

	printf("stack_peek : %s\n",stack_peek(lint_stack)->data);
	printf("stack_size : %d\n",stack_size(lint_stack));

	printf("Start stack_pop, Please free memory!\n");
	//
	for (size_t i = 0; i < count+2; i++)
	{
		if (NULL == (temp = stack_pop(lint_stack)))
		{
			printf("check NULL pointer\n");
			continue;
		}
		printf("stack_pop : %s\n", temp->data);
		free(temp ? temp->data : 0); free(temp);
		printf("stack_peek : %s\n",stack_peek(lint_stack) ? stack_peek(lint_stack)->data : NULL);
		printf("--------------\n");
	}

	printf("%d\n",stack_size(lint_stack));
	printf("----------End------------\n");

	free_stack(lint_stack, free);
	for (size_t i = 0; i < count; i++)
	{
		free(alphabet[i]);
	}
	//system("leaks a.out > leaks_result; cat leaks_result | grep leaked");
	return 0;
}