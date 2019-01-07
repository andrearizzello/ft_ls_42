/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:30:58 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/10 11:30:59 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*retstring;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	retstring = (char *)malloc(sizeof(char) * size + 1);
	if (retstring == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		retstring[i++] = *s1++;
	while (*s2)
		retstring[i++] = *s2++;
	retstring[i] = '\0';
	return (retstring);
}
