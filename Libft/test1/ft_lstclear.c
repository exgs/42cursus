#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
    t_list *curr;
    curr = *lst;     
    while (curr != NULL)
    {
        temp = curr;
        del(curr->content);
        curr = curr->next;
        free(temp);
    }
    lst = NULL;
}