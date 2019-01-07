/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoursive.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:09:02 by arizzell          #+#    #+#             */
/*   Updated: 2018/01/12 11:09:04 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_relauch(t_object *root, t_params *params, char *path)
{
	t_object	*list;
	t_object	*newlist;
	char		*tmp;

	list = root;
	if (params->rec == FALSE)
		return ;
	while (list)
	{
		if (S_ISDIR(list->lstats.st_mode) && ft_strcmp(list->name.d_name, ".")
				!= 0 && ft_strcmp(list->name.d_name, "..") != 0)
		{
			newlist = ft_initnode();
			tmp = ft_strjoin(path, list->name.d_name);
			ft_putchar('\n');
			ft_putstr(tmp);
			ft_putstr(":\n");
			ft_recursive(tmp, params, NULL, NULL);
			ft_destroylist(newlist);
			free(tmp);
		}
		list = list->next;
	}
}
