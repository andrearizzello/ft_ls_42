/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tobject.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:20:42 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/14 16:20:43 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_object	*ft_initnode(void)
{
	t_object *a;

	a = (t_object *)ft_memalloc(sizeof(t_object));
	a->next = NULL;
	return (a);
}

void		ft_destroylist(t_object *list)
{
	t_object *next;

	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
}
