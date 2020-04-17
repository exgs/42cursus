/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 01:32:50 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/10 02:53:30 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lstdel(t_list *lst, void (*del)(void *))
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *curr;

	new = (t_list *)malloc(sizeof(t_list));
	curr = new;
	while (lst->content != NULL)
	{
		curr->content = f(lst->content);
		curr->next = (t_list *)malloc(sizeof(t_list));
		if (curr->next == NULL)
		{
			lstdel(new, del);
			return (NULL);
		}
		lst = lst->next;
	}
	curr->next = NULL;
	return (new);
}
