/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:05:10 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/08 20:05:11 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int			i;
	size_t		x;
	size_t		now;
	const char	*result;

	if (ft_strlen(s2) == 0)
		return ((char *)(s1));
	i = -1;
	x = 0;
	now = 0;
	result = NULL;
	while (s1[++i] && (size_t)i < len)
	{
		if (s1[i] == s2[x])
		{
			if (result == NULL)
				result = &s1[i];
			x++;
		}
		else
			result = ft_strnstr(&s1[++now], s2, len);
		if (s2[x] == '\0')
			return ((char *)(result));
	}
	return (NULL);
}
