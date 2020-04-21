#include "list.h"

unsigned int ft_abs(int a)
{
	if (a < 0)
		return ((unsigned int)-1 * a);
	return ((unsigned int)a);
}

t_linked_list *list_init(void)
{
	t_linked_list *circle_init;
	if(NULL == (circle_init = malloc(sizeof(t_linked_list))))
		return (NULL);
	circle_init->head = NULL;
	circle_init->size = 0;
	return (circle_init);
}

t_node *create_elem(void *data)
{
	t_node *list_init;
	if (NULL ==(list_init=malloc(sizeof(t_node))))
		return (NULL);
	list_init->data=data;
	list_init->next=NULL;
	list_init->prev=NULL;
	return (list_init);
}

t_node *list_get(t_linked_list *list, int n)
{
	t_node 		*curr;
	unsigned int i;

	if (list == NULL || list->head == NULL || list_size(list) <= n)
		return (NULL);
	i = 0;
	curr = list->head;
	if(n >= 0)
	{
		while (i < n)
		{
			curr = curr->next;
			i++;
		}
		return (curr);
	}
	else
	{
		n *= -1;
		while (i < n)
		{
			curr = curr->prev;
			i++;
		}
		return (curr);
	}
}

int list_size(t_linked_list *list)
{
	t_node *curr;
	t_node *start_point;
	unsigned int size;

	if (list == NULL || list->head == NULL)
		return (0);
	start_point = list->head;
	size = 1;
	curr = start_point->next;
	while (curr != start_point)
	{
		size++;
		curr=curr->next;
	}
	return (size);
}

int list_add(t_linked_list *list, void *data, int n)
{
	t_node *add_list;
	t_node *prev;
	t_node *next;
	// unsigned int i;

	if (list == NULL || data == NULL)
		return(-1);
	// i = 0;
	add_list = create_elem(data);
	if(list_size(list) == 0)
	{
		list->head = add_list;
		add_list->next = add_list;
		add_list->prev = add_list;
		return (0);
	}
	if (n >= 0)
	{
		if (n > list_size(list) ) //같은 경우 한바퀴돌아 자기자신을가리키므로
			return(-1);
		prev = list_get(list, n-1);
		next = prev->next;
		prev->next = add_list;
		add_list->prev = prev;
		next->prev = add_list;
		add_list->next = next;
		return (n);
	}
	else if (n < 0)
	{
		if ((n*-1) >= list_size(list))
			return (-1);
		next = list_get(list, n + 1);
		prev = next->prev;
		next->prev = add_list;
		add_list->next = next;
		prev->next = add_list;
		add_list->prev = prev;
		return (list_size(list)+n);
	}
}
void list_remove(t_linked_list *list, int n, void (*free_data)(void *))
{
	t_node *del_list;
	t_node *prev;
	t_node *next;
	unsigned int abs;
	if (list == NULL || free_data == NULL)
		return ;
	if (abs = (n >=0 ? n : (n*-1)) >= list_size(list))
		return ;
	del_list = list_get(list, n);
	prev = del_list->prev;
	next = del_list->next;
	prev->next = next;
	next->prev = prev;
	free_data(del_list->data);
	free(del_list);
}
void list_move_head_to_next(t_linked_list *list)
{
	list->head = list->head->next;
}
void list_move_head_to_prev(t_linked_list *list)
{
	list->head = list->head->prev;
}
int list_find(t_linked_list *list, void* data, int (*cmp)(void *data1, void *data2))
{
	if(list == NULL || list->head == NULL)
		return (-1);
	unsigned int i = 0;
	t_node *curr = list->head;
	while (i < list_size(list) && cmp(curr->data,data))
	{
		curr = curr->next;
		i++;
	}
	return (i);
}

void list_clear(t_linked_list *list, void (*free_data)(void *))
{
	t_node *curr;
	t_node *temp;
	unsigned int i = 0;
	curr = list->head;
	while (i < list_size(list))
	{
		temp = curr;
		curr = curr->next;
		free_data(temp->data);
		free(temp);
		i++;
	}
	list->head = NULL;
	list->size = 0;
}
void free_list(t_linked_list *list, void (*free_data)(void *))
{
	list_clear(list,free_data);
	free(list);
	list=NULL;
}
void list_foreach(t_linked_list *list, void (*f)(void *))
{
	t_node *curr;
	curr = list->head;
	unsigned int i = 0;
	while (i < list_size(list))
	{
		f(curr->data);
		// curr->data = f(curr->data);
		curr = curr->next;
		i++;
	}
}
