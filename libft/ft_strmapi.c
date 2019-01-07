/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:39:03 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/10 10:39:05 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmall;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	strmall = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (strmall == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		strmall[i] = f((unsigned int)i, s[i]);
	strmall[i] = '\0';
	return (strmall);
}
