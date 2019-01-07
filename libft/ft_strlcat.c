/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:34:20 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/08 18:34:21 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	space_left;
	size_t	d_len;
	size_t	i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	space_left = size - d_len - 1;
	i = 0;
	if (size <= d_len)
		return (size + s_len);
	if (size >= d_len)
	{
		while (src[i] && i < space_left)
		{
			dst[d_len + i] = src[i];
			i++;
		}
	}
	dst[i + d_len] = '\0';
	return (d_len + s_len);
}
