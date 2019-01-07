/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:36:05 by arizzell          #+#    #+#             */
/*   Updated: 2018/01/16 14:36:08 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_gettype(t_object *list)
{
	if (S_ISDIR(list->lstats.st_mode))
		ft_putchar('d');
	else if (S_ISBLK(list->lstats.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(list->lstats.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(list->lstats.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(list->lstats.st_mode))
		ft_putchar('s');
	else if ((list->lstats.st_mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else
		ft_putchar('-');
}

static void	ft_getmaj(t_object *list, t_object *root)
{
	int32_t		maxsize;
	int32_t		size;
	size_t		last;
	t_object	*bk;
	char		*str;

	maxsize = 0;
	bk = root;
	while (bk)
	{
		if (major(bk->lstats.st_rdev) > maxsize)
			maxsize = major(bk->lstats.st_rdev);
		bk = bk->next;
	}
	str = ft_strnew(ft_numlen((unsigned long)maxsize));
	ft_bspace(str, ft_numlen((unsigned long)maxsize));
	last = ft_strlen(str) - 1;
	size = major(list->lstats.st_rdev);
	while (size / 10)
	{
		str[last--] = (char)((size % 10) + 48);
		size /= 10;
	}
	str[last] = (char)((size % 10) + 48);
	ft_putnfree(str, 3);
}

static void	ft_getmin(t_object *list, t_object *root)
{
	int32_t		maxsize;
	int32_t		size;
	size_t		last;
	t_object	*bk;
	char		*str;

	maxsize = 0;
	bk = root;
	while (bk)
	{
		if (minor(bk->lstats.st_rdev) > maxsize)
			maxsize = minor(bk->lstats.st_rdev);
		bk = bk->next;
	}
	str = ft_strnew(ft_numlen((unsigned long)maxsize));
	ft_bspace(str, ft_numlen((unsigned long)maxsize));
	last = ft_strlen(str) - 1;
	size = minor(list->lstats.st_rdev);
	while (size / 10)
	{
		str[last--] = (char)((size % 10) + 48);
		size /= 10;
	}
	str[last] = (char)((size % 10) + 48);
	ft_putnfree(str, 0);
}

void		ft_getmajmin(t_object *list, t_object *root)
{
	ft_getmaj(list, root);
	ft_putstr(", ");
	ft_getmin(list, root);
}
