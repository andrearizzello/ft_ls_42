/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:19:59 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/09 13:20:00 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define TRUE 1
# define FALSE 0
# define MODE lstats.st_mtimespec

# include <time.h>
# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <errno.h>
# include <ntsid.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include "libft/libft.h"

int			g_erro;

typedef struct	s_params
{
	int l;
	int rec;
	int a;
	int r;
	int t;
}				t_params;

typedef struct	s_object
{
	struct stat		lstats;
	struct dirent	name;
	struct s_object	*next;
	char			lkname[255];
}				t_object;

t_params		*ft_initparams(void);
t_object		*lst_sort_ascii(t_object *lst);
t_object		*ft_dataorder(t_object *list);
t_object		*ft_reverseorder(t_object *list);
t_object		*ft_initnode(void);
t_object		*ft_getnewnode(t_object *current);
size_t			ft_spestrleu(uid_t uid);
size_t			ft_spestrleg(gid_t gid);
char			*ft_extattr(char *path);
void			ft_getdatayear(t_object *list);
void			ft_exiterror(char *path);
void			ft_sp(char **a, int s, int argnow);
void			ft_spr(char **a, int s, int argnow);
void			ft_perml(t_object *file, char *path);
void			ft_continue(t_object *file);
void			ft_getnamelink(t_object *list, t_params *params);
void			ft_getmajmin(t_object *list, t_object *root);
void			ft_gettype(t_object *list);
void			ft_relauch(t_object *root, t_params *params, char *path);
void			ft_destroylist(t_object *list);
void			ft_destroyparams(t_params *params);
void			ft_recursive(char *p, t_params *pa, t_object *n, t_object *l);
void			ft_printlist(t_object *list, t_params *params, char *path);
void			ft_getdata(t_object *list);
void			ft_getsize(t_object *list, t_object *root);
void			ft_getgroup(t_object *list, t_object *root);
void			ft_getlinks(t_object *list, t_object *root);
void			ft_getuser(t_object *list, t_object *root);
void			ft_gettotalsize(t_object *list);
void			ft_getperm(t_object *list, char *path);
void			ft_bspace(char *s, size_t n);
void			ft_putnfree(char *s, int mode);
unsigned long	ft_numlen(unsigned long i);

#endif
