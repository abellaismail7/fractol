/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:37:30 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/12 16:02:47 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

double factor = .02;

void zoom_out(t_vars *vars)
{
	vars->zcoor.x -= map(vars->mcoor.x, 0, vars->height, -9, 9) * vars->zoom;
	vars->zcoor.y -= map(vars->mcoor.y, 0, vars->height, -9, 9) * vars->zoom;
}

void zoom_in(t_vars *vars)
{
	double half;

	half = vars->height * factor *  vars->zoom ;
	vars->zcoor.x += map(vars->mcoor.x, 0, vars->height, -half, half);
	vars->zcoor.y += map(vars->mcoor.y, 0, vars->height, -half, half);
}

int keyevent(int key, t_vars *vars)
{
	printf("key pressed: %d", key);
	fflush(stdout);
	if (key == 123)
		vars->mcoor.x -= 5;
	if (key ==  124)
		vars->mcoor.x += 5;
	if (key ==  125)
		vars->mcoor.y += 5;
	if (key ==  126)
		vars->mcoor.y -= 5;

	if (key == 34)
	{
		vars->zoom += vars->zoom * .1;
		zoom_in(vars);
		mlx_clear_window(vars->mlx, vars->win);
	}
	if (key == 31)
	{
		vars->zoom -= vars->zoom * .1;
		zoom_out(vars);

		//if (vars->iters > 50)
		//	vars->iters -= 10;
		mlx_clear_window(vars->mlx, vars->win);
	}
	if (key  == 12 || key == 53)
	{
		mlx_destroy_window(vars->mlx,vars->win);
		exit(0);
	}
	if (key == 45)
		vars->iters -= 10;
	if (key == 46)
		vars->iters += 10;
	redraw(vars);
	return 1;
}

int mouse_event(int button,int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		vars->mcoor.x = x;
		vars->mcoor.y = y;
		vars->zoom += .05;
		zoom_in(vars);
	}
	redraw(vars);
	if (button == 5)
	{
		//vars->zoom -= 0.1;
		//vars->mcoor.x = x;
		//vars->mcoor.y = y;
		//zoom_out(vars);
		////vars->iters += 10;
		factor += 0.02;
		printf("%f\n", factor);
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	if (button == 4)
	{
		//vars->zoom += 0.1;
		//vars->mcoor.x = x;
		//vars->mcoor.y = y;
		//zoom_in(vars);
		//if (vars->iters > 50)
		//	vars->iters -= 10;
		factor -= 0.02;
		printf("%f\n", factor);
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	return (1);
}

int motion_event(int x, int y, t_vars *vars)
{
	if (vars->julia)
	{
		vars->julia->x = x;
		vars->julia->y = y;
		redraw(vars);
	}
	return 1;
}
