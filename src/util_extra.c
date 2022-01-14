/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:30:37 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/14 11:30:37 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_out(t_vars *vars)
{
	double	oldzw;
	t_pair	p;
	t_pair	mp;

	mp.b = 40;
	mp.a = -mp.b;
	oldzw = vars->width * vars->zoom;
	vars->zoom -= vars->zoom * .1;
	p.a = 0;
	p.b = vars->width * vars->zoom;
	vars->zcoor.x = map(vars->zcoor.x, 0, oldzw, p)
		+ map(vars->mcoor.x, 0, vars->width, mp);
	vars->zcoor.y = map(vars->zcoor.y, 0, oldzw, p)
		+ map(vars->mcoor.y, 0, vars->width, mp);
}

void	zoom_in(t_vars *vars)
{
	double	oldzw;
	t_pair	p;
	t_pair	mp;

	mp.b = 40;
	mp.a = -mp.b;
	oldzw = vars->width * vars->zoom;
	vars->zoom += vars->zoom * .1;
	p.a = 0;
	p.b = vars->width * vars->zoom;
	vars->zcoor.x = map(vars->zcoor.x, 0, oldzw, p)
		+ map(vars->mcoor.x, 0, vars->width, mp);
	vars->zcoor.y = map(vars->zcoor.y, 0, oldzw, p)
		+ map(vars->mcoor.y, 0, vars->width, mp);
}
