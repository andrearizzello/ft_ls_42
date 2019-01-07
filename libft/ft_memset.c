/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:59:53 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/07 10:59:55 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*linkstr;

	if (len == 0)
		return (b);
	linkstr = (unsigned char *)b;
	while (len--)
	{
		*linkstr = (unsigned char)c;
		if (len)
			linkstr++;
	}
	return (b);
}
