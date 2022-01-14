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

int	keyevent(int key, t_vars *vars)
{
	if (key == A_KEY)
		vars->anim = !vars->anim;
	else if (key == C_KEY)
	{
		if (vars->hue == 300)
			vars->hue = 10;
		else
			vars->hue += 10;
	}
	else if (key == LEFT_ARROW)
		vars->zcoor.x -= 25;
	else if (key == RIGHT_ARROW)
		vars->zcoor.x += 25;
	else if (key == UP_ARROW)
		vars->zcoor.y += 25;
	else if (key == DOWN_ARROW)
		vars->zcoor.y -= 25;

	else if (key == I_KEY)
	{
		zoom_in(vars);
		mlx_clear_window(vars->mlx, vars->win);
	}
	else if (key == O_KEY)
	{
		vars->zoom -= vars->zoom * .1;
		zoom_out(vars);
		mlx_clear_window(vars->mlx, vars->win);
	}

	else if (key == 12 || key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (key == N_KEY)
		vars->iters -= 10;
	else if (key == M_KEY)
		vars->iters += 10;
	else
		return (0);
	redraw(vars);
	return (1);
}

int	mouse_event(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		vars->mcoor.x = x;
		vars->mcoor.y = y;
		vars->zoom += .01;
		zoom_in(vars);
		redraw(vars);
	}
	if (button == 5)
	{
		vars->mcoor.x = x;
		vars->mcoor.y = y;
		zoom_out(vars);
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	if (button == 4)
	{
		vars->mcoor.x = x;
		vars->mcoor.y = y;
		zoom_in(vars);
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	return (1);
}

int	motion_event(int x, int y, t_vars *vars)
{
	if (vars->julia && vars->anim)
	{
		vars->julia->x = x;
		vars->julia->y = y;
		redraw(vars);
	}
	return (1);
}

void	register_events(t_vars *vars)
{
	mlx_mouse_hook(vars->win, mouse_event, vars);
	mlx_hook(vars->win, 6, 1, motion_event, vars);
	mlx_key_hook(vars->win, keyevent, vars);
	mlx_hook(vars->win, 17, 0, destroy_win, vars);
	mlx_hook(vars->win, 12, 1, redraw, vars);
	mlx_hook(vars->win, 13, 1, redraw, vars);
}
