#include "stack.h"

// Rule 1: data == NULL 인경우는 stack_array 생성조차 되지않는다.
t_stack *stack_init(unsigned int max_size)
{
	t_stack *stack_a;
	if (max_size == 0)
		return (0);
	if(0 == (stack_a = malloc(sizeof(t_stack))))
		return (0);
	stack_a->max_size = max_size;
	stack_a->top_index = -1;
	if(0 == (stack_a->data = (void **)calloc(sizeof(void *), max_size)))
	{
		free(stack_a);
		return (0);
	}
	return (stack_a);
}

int stack_push(t_stack *stack, void *data)
{
	int xtop_index;
	xtop_index = stack->top_index;

	if (data == NULL || stack == NULL || xtop_index == (stack->max_size)-1 )
		return (0);
	stack->data[xtop_index + 1] = data;
	stack->top_index++;
	return (1);
}

int stack_size(t_stack *stack) //when data doesn't exist, top_index = -1
{
	if (stack == NULL)
		return(-1);
	return ((stack->top_index) + 1);
}

void *stack_peek(t_stack *stack)
{
	if (stack == NULL || stack->data == NULL || stack->top_index == -1)
		return (NULL);
	return (stack->data[stack->top_index]);
}

void *stack_pop(t_stack *stack)
{
	void *pop_data;

	if (stack == NULL || stack->data == NULL || stack->top_index == -1)
		return (0);
	pop_data = stack->data[stack->top_index];
	stack->data[stack->top_index] = 0;
	stack->top_index--;
	return (pop_data);
}

void stack_clear(t_stack *stack, void (*free_data)(void *))
{
	if (stack == NULL || stack->data == NULL)
		return ;
	for (size_t i = 0; i < stack->max_size; i++)
	{
		free_data(stack->data[i]);
	}
	return ;
}

void free_stack(t_stack *stack, void (*free_data)(void *))
{
	stack_clear(stack, free_data);
	free(stack);
}