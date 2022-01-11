/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:37:30 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/11 17:37:30 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

int keyevent(int key, t_vars *vars)
{
	//printf("key pressed: %d", key);
	//fflush(stdout);
	if (key == 123)
		vars->ox -= 5;
	if (key ==  124)
		vars->ox += 5;
	if (key ==  125)
		vars->oy += 5;
	if (key ==  126)
		vars->oy -= 5;

	if (key == 34)
	{
		vars->zoom += vars->zoom * .1;
		mlx_clear_window(vars->mlx, vars->win);
	}
	if (key == 31)
	{
		vars->zoom -= vars->zoom * .1;
		//if (vars->iters > 50)
		//	vars->iters -= 10;
		mlx_clear_window(vars->mlx, vars->win);
	}
	if (key  == 12 || key == 53)
	{
		mlx_destroy_window(vars->mlx,vars->win);
		exit(0);
	}
	redraw(vars);
	return 1;
}

int mouse_event(int button,int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		vars->ox = x;
		vars->oy = y;
		vars->zoom += vars->zoom * .01;
	}
	redraw(vars);
	return 0;
	//if (button == 5)
	//{
	//	vars->zoom -= 0.1;
	//	vars->zx = x;
	//	vars->zy = y;
	//	//vars->iters += 10;
	//	mlx_clear_window(vars->mlx, vars->win);
	//	redraw(vars);
	//}
	//if (button == 4)
	//{
	//	vars->zoom += 0.1;
	//	vars->zx = x;
	//	vars->zy = y;
	//	//if (vars->iters > 50)
	//	//	vars->iters -= 10;
	//	mlx_clear_window(vars->mlx, vars->win);
	//	redraw(vars);
	//}
	return (1);
}

int motion_event(int x, int y, t_vars *vars)
{
	if (vars->julia)
	{
		vars->julia->x = x;
		vars->julia->y = y;
	}
	return 1;
}
