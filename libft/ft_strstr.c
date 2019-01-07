/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:53:47 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/08 19:53:49 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (!(*needle))
		return (char *)(haystack);
	while (haystack[i])
	{
		if (needle[0] == haystack[i])
		{
			k = 0;
			while (needle[k] == haystack[k + i])
			{
				if (!(needle[k + 1]) || !(needle[k]))
					return (char *)(haystack + i);
				k++;
			}
		}
		i++;
	}
	return (0);
}
