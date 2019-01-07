/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:18:51 by arizzell          #+#    #+#             */
/*   Updated: 2018/01/21 17:18:53 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_object	*ft_getnewnode(t_object *current)
{
	current->next = ft_initnode();
	current = current->next;
	return (current);
}

size_t		ft_spestrleu(uid_t uid)
{
	char	*str;
	size_t	t;

	if (!getpwuid(uid))
	{
		str = ft_itoa(uid);
		t = ft_strlen(str);
		free(str);
		return (t);
	}
	return (ft_strlen(getpwuid(uid)->pw_name));
}

size_t		ft_spestrleg(gid_t gid)
{
	if (!getgrgid(gid))
		return (ft_strlen(ft_itoa(gid)));
	return (ft_strlen(getgrgid(gid)->gr_name));
}

void		ft_continue(t_object *file)
{
	if (S_ISCHR(file->lstats.st_mode) || S_ISBLK(file->lstats.st_mode))
	{
		ft_putnbr(major(file->lstats.st_rdev));
		ft_putstr(",\t");
		ft_putnbr(minor(file->lstats.st_rdev));
	}
	else
		ft_putnbr(file->lstats.st_size);
}

void		ft_perml(t_object *file, char *path)
{
	time_t			x;

	x = time(NULL);
	ft_getperm(file, path);
	ft_putnbr(file->lstats.st_nlink);
	ft_putchar(' ');
	ft_putstr(getpwuid(file->lstats.st_uid) != NULL
		? getpwuid(file->lstats.st_uid)->pw_name
		: ft_itoa(file->lstats.st_uid));
	ft_putstr("  ");
	ft_putstr(getgrgid(file->lstats.st_gid) != NULL
		? getgrgid(file->lstats.st_gid)->gr_name
		: ft_itoa(file->lstats.st_gid));
	ft_putstr("  ");
	ft_continue(file);
	ft_putchar(' ');
	file->lstats.st_mtime < x - 15778458
	|| file->lstats.st_mtime > x + 15778458
	? ft_getdatayear(file) : ft_getdata(file);
}
