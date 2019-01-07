/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:05:07 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/09 18:05:08 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*strmall;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = -1;
	strmall = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (strmall == NULL)
		return (NULL);
	while (s[++i])
		strmall[i] = f(s[i]);
	strmall[i] = '\0';
	return (strmall);
}
