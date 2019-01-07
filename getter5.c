/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:17:35 by arizzell          #+#    #+#             */
/*   Updated: 2018/01/27 14:17:36 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** a = argv
** s = point used to start
** (*f) = function to compare strings
*/

void		ft_sp(char **a, int s, int argnow)
{
	char	*tmp;
	int		i;

	i = argnow;
	while (i < s && a[i + 1])
	{
		if (ft_strcmp(a[i], a[i + 1]) > 0)
		{
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
			i = argnow;
		}
		i++;
	}
}

void		ft_spr(char **a, int s, int argnow)
{
	char	*tmp;
	int		i;

	i = argnow;
	while (i < s && a[i + 1])
	{
		if (ft_strcmp(a[i], a[i + 1]) < 0)
		{
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
			i = argnow;
		}
		i++;
	}
}

void		ft_getdatayear(t_object *list)
{
	char	*time1;
	char	*time2;
	char	*year;

	time1 = ft_strnew(ft_strlen((ft_strchr(ctime(&list->lstats.st_mtime), ' '))
								+ 1));
	ft_strncpy(time1, (ft_strchr(ctime(&list->lstats.st_mtime), ' ') + 1),
			ft_strlen((ft_strchr(ctime(&list->lstats.st_mtime),
								' ') + 1)) - 1);
	time2 = ft_strnew(ft_strchr((ft_strchr(time1, ':')) + 1,
								':') - time1);
	ft_strncpy(time2, time1, ft_strchr((ft_strchr(time1,
								':')) + 1, ':') - time1);
	year = ft_strchr(ft_strchr(ft_strchr(time1, ':') + 1, ':') + 1, ' ');
	ft_strcpy(&time2[(ft_strchr(time2, ':') - 2) - time2], year);
	ft_putnfree(time2, 0);
	free(time1);
}

char		*ft_extattr(char *path)
{
	acl_t		acl;
	ssize_t		nbr;
	char		*c;
	static char	buffer[64];

	c = ft_strnew(2);
	c[0] = ' ';
	c[1] = ' ';
	nbr = listxattr(path, buffer, 64, XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl)
	{
		c[0] = '+';
		acl_free(acl);
	}
	free(path);
	if (nbr > 0)
		c[0] = '@';
	return (c);
}
