/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:37:24 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/08 20:37:25 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char *first;
	const unsigned char *second;
	unsigned int		i;

	first = (const unsigned char *)s1;
	second = (const unsigned char *)s2;
	i = 0;
	while ((*first || *second) && i < n)
	{
		if (*first != *second)
			return (*first - *second);
		first++;
		second++;
		i++;
	}
	return (0);
}
