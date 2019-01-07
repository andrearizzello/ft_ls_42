/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstln.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:44:33 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/07 11:44:34 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstln(void const *content, size_t content_size)
{
	t_list		*list;

	if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
		list->content_size = 0;
	else
		list->content_size = content_size;
	list->content = (void*)content;
	list->next = NULL;
	return (list);
}
