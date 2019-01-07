/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:49:32 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/13 10:49:33 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;

	if (!lst)
		return (NULL);
	new = f(lst);
	first = new;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
