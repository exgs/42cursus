#include "libft.h"

void lstdel(t_list *lst, void(*del)(void *))
{
    t_list *temp;
    while (lst != NULL)
    {
        temp = lst;
        del(lst->content);
        lst = lst->next;
        free(temp);
    }
}

t_list *ft_lstmap(t_list *lst, void*(*f)(void *), void(*del)(void *))
{
    
    t_list *new;
    new = (t_list *)malloc(sizeof(t_list));
    t_list *curr = new;
    while (lst->content != NULL)
    {
        curr->content = f(lst->content);
        curr->next =(t_list *)malloc(sizeof(t_list));
        if(curr->next == NULL)
        {
            lstdel(new, del);
            return NULL;
        }
        lst = lst->next;
    }
    curr->next = NULL;
    return (new);
}