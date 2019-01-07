/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:15:35 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/14 16:15:36 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_object	*ft_sortnprint(t_object *root, t_params *params, char *path)
{
	lst_sort_ascii(root);
	params->t ? root = ft_dataorder(root) : NULL;
	params->r ? root = ft_reverseorder(root) : NULL;
	ft_printlist(root, params, path);
	return (root);
}

void			ft_exiterror(char *path)
{
	char x;

	ft_putstr("ls: ");
	x = path[ft_strlen(path) - 1];
	path[ft_strlen(path) - 1] = (char)(x == '/' ? '\0' : x);
	if (ft_strchr(path, '/'))
	{
		while (path && (ft_strchr(++path, '/') != NULL))
			path = ft_strchr(path, '/');
	}
	ft_putstr(path);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	g_erro = 1;
	ft_putchar('\n');
}

static void		ft_postexe(char *p, t_params *r, DIR *d, t_object *l)
{
	l = ft_sortnprint(l, r, p);
	ft_relauch(l, r, p);
	if (d)
		closedir(d);
	if (p)
		free(p);
	if (l)
		ft_destroylist(l);
}

/*
** p = path
** pa = params
** l = variable used for nodes
** r = variable that contains the list
*/

void			ft_recursive(char *p, t_params *pa, t_object *n, t_object *l)
{
	struct dirent	*dirent1;
	DIR				*dir;
	char			*file;

	p = (p[ft_strlen(p) - 1] != '/') ? ft_strjoin(p, "/") : p;
	!(dir = opendir(p)) ? ft_exiterror(p) : NULL;
	if (dir)
	{
		while ((dirent1 = readdir(dir)))
			if (pa->a || (!pa->a && dirent1->d_name[0] != '.'))
			{
				n = !n ? ft_initnode() : ft_getnewnode(n);
				l = !l ? n : l;
				file = ft_strjoin(p, dirent1->d_name);
				lstat(file, &n->lstats);
				readlink(file, n->lkname, 255);
				n->name = *dirent1;
				free(file);
			}
	}
	ft_postexe(p, pa, dir, l);
}
