#include "libft.h"

int ft_lstsize(t_list *lst)
{
    unsigned int count = 0;
    while (lst != 0)
    {
        count ++;
        lst = lst->next;
    }
    return count;
}