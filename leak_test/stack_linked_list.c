#include "stack.h"

t_stack *stack_init(void)
{
	t_stack *new_stack;
	new_stack = malloc(sizeof(t_stack));
	new_stack->size = 0;
	new_stack->top = NULL;
	return (new_stack);
}

t_node *create_elem(void *data)
{
	t_node *new_elem;
	new_elem = malloc(sizeof(t_node));

	if (data == NULL || new_elem == NULL) //이미 push에서 검증한 사례라서 걸리지않음
		return 0;
	new_elem->data = data;
	new_elem->next = NULL;
	return (new_elem);
}

int stack_push(t_stack *stack, void *data)
{
	t_node *push_elem;

	if (stack == NULL || data == NULL)
		return 0;
	stack->size++;
	push_elem = create_elem(data);
	push_elem->next = stack->top;
	stack->top = push_elem;
	return (1);
}

int stack_size(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	return (stack->size);
}

t_node *stack_peek(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	return (stack->top);
}

t_node *stack_pop(t_stack *stack)
{
	if (stack == NULL)
		return (0);
	t_node *pop_elem;
	if (NULL == (pop_elem = stack->top))
		return 0;
	stack->top = pop_elem->next;
	stack->size--;
	pop_elem->next = NULL;
	return (pop_elem);
}

void stack_clear(t_stack *stack, void (*free_data)(void *))
{
	if (stack == NULL || free_data == NULL)
		return ;
	t_node *curr_elem;
	t_node *temp_elem;
	if (NULL == (curr_elem = stack->top))
		return ;
	stack->top = 0; //청소 사용한공간은 모두
	stack->size = 0; //청소 사용한공간은 모두
	for (unsigned int i = stack->size; i > 0; i--)
	{
		temp_elem = curr_elem->next;
		free_data(curr_elem->data);
		free(curr_elem);
		curr_elem = temp_elem;
	}
	return ;
}

void free_stack(t_stack *stack, void (*free_data)(void *))
{
	stack_clear(stack, free_data);
	free(stack);
	return ;
}