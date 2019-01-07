/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:50:58 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/21 14:50:59 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_getgroup(t_object *list, t_object *root)
{
	size_t			maxsize;
	char			*dest;
	char			*tmpuser;
	int				i;
	t_object		*bk;

	maxsize = 0;
	bk = root;
	while (bk)
	{
		if (ft_spestrleg(bk->lstats.st_gid) > maxsize)
			maxsize = ft_spestrleg(bk->lstats.st_gid);
		bk = bk->next;
	}
	dest = ft_strnew(maxsize);
	ft_bspace(dest, maxsize);
	tmpuser = getgrgid(list->lstats.st_gid) != NULL ?
			getgrgid(list->lstats.st_gid)->gr_name :
			ft_itoa(list->lstats.st_gid);
	i = -1;
	while (tmpuser && tmpuser[++i])
		dest[i] = tmpuser[i];
	getgrgid(list->lstats.st_gid) == NULL ? free(tmpuser) : NULL;
	ft_putnfree(dest, 1);
}

void	ft_getlinks(t_object *list, t_object *root)
{
	unsigned long	maxsize;
	char			*str;
	size_t			last;
	nlink_t			nlink;
	t_object		*bk;

	maxsize = 0;
	bk = root;
	while (bk)
	{
		if (bk->lstats.st_nlink > maxsize)
			maxsize = bk->lstats.st_nlink;
		bk = bk->next;
	}
	str = ft_strnew(ft_numlen(maxsize));
	ft_bspace(str, ft_numlen(maxsize));
	last = ft_strlen(str) - 1;
	nlink = list->lstats.st_nlink;
	while (nlink / 10)
	{
		str[last--] = (char)((nlink % 10) + 48);
		nlink /= 10;
	}
	str[last] = (char)((nlink % 10) + 48);
	ft_putnfree(str, 0);
}

void	ft_getuser(t_object *list, t_object *root)
{
	size_t			maxsize;
	char			*dest;
	char			*tmpuser;
	int				i;
	t_object		*bk;

	maxsize = 0;
	bk = root;
	while (bk)
	{
		if (ft_spestrleu(bk->lstats.st_uid) > maxsize)
			maxsize = ft_spestrleu(bk->lstats.st_uid);
		bk = bk->next;
	}
	dest = ft_strnew(maxsize);
	ft_bspace(dest, maxsize);
	tmpuser = getpwuid(list->lstats.st_uid) != NULL ?
			getpwuid(list->lstats.st_uid)->pw_name :
			ft_itoa(list->lstats.st_uid);
	i = -1;
	while (tmpuser && tmpuser[++i])
		dest[i] = tmpuser[i];
	getpwuid(list->lstats.st_uid) == NULL ? free(tmpuser) : NULL;
	ft_putnfree(dest, 1);
}

void	ft_gettotalsize(t_object *list)
{
	blksize_t totalsize;

	totalsize = 0;
	ft_putstr("total ");
	while (list)
	{
		totalsize += list->lstats.st_blocks;
		list = list->next;
	}
	ft_putnbr(totalsize);
	ft_putchar('\n');
}

void	ft_getperm(t_object *list, char *path)
{
	char *attr;

	ft_gettype(list);
	ft_putchar((char)(list->lstats.st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar((char)(list->lstats.st_mode & S_IWUSR ? 'w' : '-'));
	ft_putchar((char)(list->lstats.st_mode & S_IXUSR ? 'x' : '-'));
	ft_putchar((char)(list->lstats.st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar((char)(list->lstats.st_mode & S_IWGRP ? 'w' : '-'));
	ft_putchar((char)(list->lstats.st_mode & S_IXGRP ? 'x' : '-'));
	ft_putchar((char)(list->lstats.st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar((char)(list->lstats.st_mode & S_IWOTH ? 'w' : '-'));
	if (list->lstats.st_mode & S_IXOTH)
		ft_putchar((char)(list->lstats.st_mode & S_ISVTX ? 't' : 'x'));
	else
		ft_putchar((char)(list->lstats.st_mode & S_ISVTX ? 'T' : '-'));
	attr = ft_extattr(ft_strjoin(path, list->name.d_name));
	ft_putstr(attr);
	*attr ? free(attr) : NULL;
}
