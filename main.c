/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:05:40 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/14 16:05:41 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_usage(char c, t_params *params)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-lRart] [file ...]\n");
	ft_destroyparams(params);
	exit(1);
}

static void		ft_setter(char *argv, t_params *params)
{
	int i;

	i = 0;
	argv[i] == '-' ? (void)i++ : NULL;
	while (argv[i])
	{
		if (!((argv[i] == '-' && i > 1) || argv[i] == 'l' || argv[i] == 'R'
			|| argv[i] == 'a' || argv[i] == 'r' || argv[i] == 't')
			|| ft_strchr(&argv[i], '-'))
			ft_strchr(&argv[i], '-') ?
			ft_usage(*ft_strchr(&argv[i], '-'), params)
			: ft_usage(argv[i], params);
		i++;
	}
	params->l = ft_strchr(argv, 'l') != NULL ? TRUE : params->l;
	params->rec = ft_strchr(argv, 'R') != NULL ? TRUE : params->rec;
	params->a = ft_strchr(argv, 'a') != NULL ? TRUE : params->a;
	params->r = ft_strchr(argv, 'r') != NULL ? TRUE : params->r;
	params->t = ft_strchr(argv, 't') != NULL ? TRUE : params->t;
}

static t_params	*ft_setparams(char **argv, int *argnow, int *total, int argc)
{
	t_params	*params;
	int			i;

	i = 1;
	*argnow = 1;
	g_erro = 0;
	params = ft_initparams();
	while (argv[i])
	{
		if ((argv[i][0] == '-' && ft_strlen(argv[i]) == 1)
			|| (!ft_strcmp(argv[i], "--") && (*argnow += 1)))
		{
			*total = argc - *argnow;
			return (params);
		}
		else if (argv[i][0] == '-' && (*argnow += 1))
			ft_setter(argv[i], params);
		i++;
	}
	*total = i - *argnow;
	return (params);
}

static int		ft_isfile(char **argv, t_params *params, int i)
{
	t_object	*file;
	DIR			*dir;

	file = ft_initnode();
	if (!(dir = opendir(argv[i]))
		|| (readlink(argv[i], file->lkname, 255) > 0 && params->l))
	{
		if (lstat(argv[i], &file->lstats) == -1)
		{
			ft_exiterror(argv[i]);
			exit(1);
		}
		params->l ? ft_perml(file, argv[i]) : NULL;
		ft_putstr(argv[i]);
		if (file->lkname[0] && params->l)
		{
			ft_putstr(" -> ");
			ft_putstr(file->lkname);
		}
		ft_putchar('\n');
		return (0);
	}
	closedir(dir);
	ft_destroylist(file);
	return (1);
}

int				main(int argc, char **argv)
{
	t_params	*params;
	int			total;
	int			argnow;
	char		*path;

	params = ft_setparams(argv, &argnow, &total, argc);
	params->r ? ft_spr(argv, argc, argnow) : ft_sp(argv, argc, argnow);
	total <= 0 ? ft_recursive(ft_strdup("./"), params, NULL, NULL) : NULL;
	while (argnow < argc && argv[argnow])
	{
		if (ft_isfile(argv, params, argnow))
		{
			if (total > 1)
			{
				ft_putstr(argv[argnow]);
				ft_putstr(":\n");
			}
			path = ft_strdup(argv[argnow]);
			ft_recursive(path, params, NULL, NULL);
			argnow < (argc - 1) ? ft_putchar('\n') : NULL;
		}
		argnow++;
	}
	ft_destroyparams(params);
	return (g_erro);
}
