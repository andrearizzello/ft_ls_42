/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 11:41:16 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/17 11:41:19 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_getnamelink(t_object *list, t_params *params)
{
	ft_putstr(list->name.d_name);
	if (list->lkname[0] != '\0' && params->l)
	{
		ft_putstr(" -> ");
		ft_putstr(list->lkname);
	}
	ft_putchar('\n');
}

void		ft_printlist(t_object *list, t_params *params, char *path)
{
	t_object		*root;
	time_t			x;

	root = list;
	x = time(NULL);
	list && params->l ? ft_gettotalsize(list) : NULL;
	while (list)
	{
		if (params->l)
		{
			ft_getperm(list, path);
			ft_getlinks(list, root);
			ft_getuser(list, root);
			ft_getgroup(list, root);
			S_ISCHR(list->lstats.st_mode) || S_ISBLK(list->lstats.st_mode) ?
			ft_getmajmin(list, root) : ft_getsize(list, root);
			list->lstats.st_mtime < x - 15778458
			|| list->lstats.st_mtime > x + 15778458
			? ft_getdatayear(list) : ft_getdata(list);
		}
		ft_getnamelink(list, params);
		list = list->next;
	}
}
