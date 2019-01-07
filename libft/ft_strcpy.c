/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:06:08 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/08 18:06:09 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int src_size;

	src_size = 0;
	while (src[src_size])
	{
		dst[src_size] = src[src_size];
		src_size++;
	}
	dst[src_size] = src[src_size];
	return (dst);
}
