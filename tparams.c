/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arizzell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:08:46 by arizzell          #+#    #+#             */
/*   Updated: 2017/12/14 16:09:01 by arizzell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_params	*ft_initparams(void)
{
	t_params	*a;

	a = (t_params *)malloc(sizeof(t_params));
	a->a = FALSE;
	a->l = FALSE;
	a->r = FALSE;
	a->t = FALSE;
	a->rec = FALSE;
	return (a);
}

void		ft_destroyparams(t_params *params)
{
	free(params);
}
