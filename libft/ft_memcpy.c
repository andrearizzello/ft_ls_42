/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:55:22 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/07 14:55:25 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d1;
	char	*s2;
	size_t	i;

	d1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	while (i < n)
	{
		d1[i] = s2[i];
		i++;
	}
	return (dst);
}
