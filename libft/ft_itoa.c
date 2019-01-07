/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:58:12 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/12 19:58:14 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long long int n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	else
		return (ft_intlen(n / 10) + 1);
}

char		*ft_itoa(int a)
{
	char			*str;
	int				len;
	int				neg;
	long long int	n;

	n = a;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	len = neg ? ft_intlen(n) : ft_intlen(n) - 1;
	if ((str = ft_strnew((size_t)(len + neg + 1))) == NULL)
		return (NULL);
	while (len >= 0)
	{
		str[len] = (char)((n % 10) + '0');
		len--;
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
