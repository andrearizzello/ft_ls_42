/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:42:23 by arizzell          #+#    #+#             */
/*   Updated: 2017/11/10 11:42:24 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lencounter(char const *s, size_t len)
{
	int char_count;
	int i;

	char_count = 0;
	i = 0;
	while ((*s == ' ') || (*s == '\t') || (*s == '\n'))
	{
		char_count++;
		s++;
		i++;
	}
	if (*s)
	{
		s = s + (len - i - 1);
		while ((*s == ' ') || (*s == '\t') || (*s == '\n'))
		{
			char_count++;
			s--;
		}
		return (len - char_count);
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	size_t		s_valid_len;
	char		*s_cp;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	s_valid_len = ft_lencounter(s, ft_strlen(s));
	if (!(s_cp = (char *)ft_memalloc(s_valid_len + 1)))
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
		i++;
	while (s_valid_len--)
		s_cp[j++] = s[i++];
	s_cp[i] = '\0';
	return (&s_cp[0]);
}
