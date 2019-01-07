/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:05:23 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/13 00:05:25 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *c, size_t size)
{
	t_list	*newo;
	void	*data;

	newo = (t_list *)ft_memalloc(sizeof(t_list));
	if (newo == NULL)
		return (NULL);
	if (c == NULL)
	{
		newo->content = NULL;
		newo->content_size = 0;
	}
	else
	{
		data = ft_memalloc(sizeof(unsigned char *) * size);
		ft_memcpy(data, c, size);
		newo->content = data;
		newo->content_size = size;
	}
	return (newo);
}
