/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:58:53 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/08 18:58:54 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *link;

	link = (char *)s;
	while (*link)
		if (c == *link++)
			return (--link);
	if (*link == '\0' && c == '\0')
		return (link);
	return (NULL);
}
