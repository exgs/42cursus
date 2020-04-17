#include "libft.h"

void *f(void *num)
{
	int * new;
	if (NULL == (new = malloc(sizeof(int))))
		return (NULL);
	*new = *(int *)num + 1;
	return (new);
}

int main()
{
	int a = 2;
	t_list *head;
	t_list *head_map;
	t_list *curr;
	head = ft_lstnew(&a);
	curr = head;
	curr->next = ft_lstnew(&a);
	curr = curr->next;
	curr->next = ft_lstnew(&a);
	curr = curr->next;
	curr->next = ft_lstnew(&a);
	curr = curr->next;
	curr->next = ft_lstnew(&a);
	curr = curr->next;
	curr->next = ft_lstnew(&a);
	printf("list size : %d\n",ft_lstsize(head));
	head_map = ft_lstmap(head, f, free);
	printf("list size : %d\n",ft_lstsize(head_map));
	curr = head_map;
	while (curr)
	{
		printf("%d\n",*(int *)(curr->content));
		curr = curr->next;
	}
	ft_lstclear(&head_map,free);
	ft_lstclear(&head,free);
}