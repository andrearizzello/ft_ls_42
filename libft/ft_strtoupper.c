/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:36:07 by arizzell          #+#    #+#             */
/*   Updated: 2018/01/16 11:04:02 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtoupper(char *str)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i++])
		ret[i] = (char)ft_toupper(str[i]);
	return (ret);
}
