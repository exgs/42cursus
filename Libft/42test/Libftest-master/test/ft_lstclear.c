/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunslee <yunslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 01:23:44 by yunslee           #+#    #+#             */
/*   Updated: 2020/04/10 02:53:17 by yunslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
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
