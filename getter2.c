/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:56:48 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/21 14:56:50 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_putnfree(char *s, int mode)
{
	ft_putstr(s);
	if (mode == 0)
		ft_putchar(' ');
	if (mode == 1)
		ft_putstr("  ");
	free(s);
}

void			ft_bspace(char *s, size_t n)
{
	while (n > 0)
	{
		*s = ' ';
		s++;
		n--;
	}
}

unsigned long	ft_numlen(unsigned long i)
{
	unsigned long result;

	result = 0;
	while ((i / 10) != 0)
	{
		i /= 10;
		result++;
	}
	return (++result);
}

void			ft_getdata(t_object *list)
{
	char	*time1;
	char	*time2;

	time1 = ft_strnew(ft_strlen((ft_strchr(ctime(&list->lstats.st_mtime), ' '))
								+ 1));
	ft_strncpy(time1, (ft_strchr(ctime(&list->lstats.st_mtime), ' ') + 1),
			ft_strlen((ft_strchr(ctime(&list->lstats.st_mtime),
									' ') + 1)) - 1);
	time2 = ft_strnew(ft_strchr((ft_strchr(time1, ':')) + 1,
								':') - time1);
	ft_strncpy(time2, time1, ft_strchr((ft_strchr(time1,
												':')) + 1, ':') - time1);
	ft_putnfree(time2, 0);
	free(time1);
}

void			ft_getsize(t_object *list, t_object *root)
{
	off_t			maxsize;
	off_t			size;
	size_t			last;
	t_object		*bk;
	char			*str;

	maxsize = 0;
	bk = root;
	while (bk)
	{
		if (bk->lstats.st_size > maxsize)
			maxsize = bk->lstats.st_size;
		bk = bk->next;
	}
	str = ft_strnew(ft_numlen((unsigned long)maxsize));
	ft_bspace(str, ft_numlen((unsigned long)maxsize));
	last = ft_strlen(str) - 1;
	size = list->lstats.st_size;
	while (size / 10)
	{
		str[last--] = (char)((size % 10) + 48);
		size /= 10;
	}
	str[last] = (char)((size % 10) + 48);
	ft_putnfree(str, 0);
}
