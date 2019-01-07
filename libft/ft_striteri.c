/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:52:19 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/09 17:52:21 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int a;

	a = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[a])
	{
		f(a, &s[a]);
		a++;
	}
}
