/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 11:26:15 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/17 11:26:16 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	lst_swap(t_object *p1, t_object *p2)
{
	struct stat		lstats;
	struct dirent	name;
	char			lkname[255];

	lstats = p1->lstats;
	name = p1->name;
	ft_strcpy(lkname, p1->lkname);
	p1->lstats = p2->lstats;
	p1->name = p2->name;
	ft_strcpy(p1->lkname, p2->lkname);
	p2->lstats = lstats;
	p2->name = name;
	ft_strcpy(p2->lkname, lkname);
}

t_object	*lst_sort_ascii(t_object *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name.d_name, lst->next->name.d_name) > 0)
		lst_swap(lst, lst->next);
	lst->next = lst_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name.d_name, lst->next->name.d_name) > 0)
	{
		lst_swap(lst, lst->next);
		lst->next = lst_sort_ascii(lst->next);
	}
	return (lst);
}

t_object	*ft_dataorder(t_object *list)
{
	if (!list)
		return (NULL);
	if (list->next && (list->MODE.tv_sec < list->next->MODE.tv_sec))
		lst_swap(list, list->next);
	else if (list->next && list->MODE.tv_sec == list->next->MODE.tv_sec)
		if (list->next && (list->MODE.tv_nsec < list->next->MODE.tv_nsec))
			lst_swap(list, list->next);
	list->next = ft_dataorder(list->next);
	if (list->next && (list->MODE.tv_sec < list->next->MODE.tv_sec))
	{
		lst_swap(list, list->next);
		list->next = ft_dataorder(list->next);
	}
	else if (list->next && list->MODE.tv_sec == list->next->MODE.tv_sec)
	{
		if (list->next && (list->MODE.tv_nsec < list->next->MODE.tv_nsec))
		{
			lst_swap(list, list->next);
			list->next = ft_dataorder(list->next);
		}
	}
	return (list);
}

t_object	*ft_reverseorder(t_object *list)
{
	t_object *a;
	t_object *b;
	t_object *c;

	a = NULL;
	b = list;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}
