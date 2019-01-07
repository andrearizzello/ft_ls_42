/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:37:29 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/11 20:37:30 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_wordlen(char const *s, int word_n, int opt, char split)
{
	int wordstrt;
	int	wordsn;
	int	i;

	wordsn = -1;
	i = 0;
	while (s[i])
	{
		while (s[i] == split && s[i])
			i++;
		wordstrt = i;
		if (s[i])
			wordsn++;
		while (s[i] != split && s[i])
			i++;
		if (opt == 1 && wordsn == word_n)
			return (i - wordstrt);
	}
	if (opt == 2)
		return (wordsn + 1);
	else
		return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		words;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	words = ft_wordlen(s, 0, 2, c);
	if (!(array = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = -1;
	while (++i < words)
		array[i] = (char*)malloc(sizeof(char) * (ft_wordlen(s, i, 1, c) + 1));
	array[i] = NULL;
	i = 0;
	while (*s && array[i])
	{
		k = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			array[i][k++] = *s++;
		array[i++][k] = 0;
	}
	return (array);
}
