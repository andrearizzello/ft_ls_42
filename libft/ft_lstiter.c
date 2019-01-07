/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:41:48 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/13 10:41:50 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *now;

	if (lst != NULL)
	{
		now = lst;
		while (now->next != NULL)
		{
			f(now);
			now = now->next;
		}
		f(now);
	}
}
