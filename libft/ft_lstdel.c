/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:10:02 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/13 10:10:04 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *now;

	now = *alst;
	while (now != NULL)
	{
		next = now->next;
		del(now->content, now->content_size);
		free(now);
		now = next;
	}
	*alst = NULL;
}
