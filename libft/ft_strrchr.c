/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:18:39 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/08 19:18:40 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last;
	char *link;

	link = (char *)s;
	last = NULL;
	while (*link)
		if (c == *link++)
			last = link - 1;
	if (*link == c)
		last = link;
	return (last);
}
