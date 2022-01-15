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

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "fractol.h"
#include "mlx_com.h"

int	key_event(int key, t_vars *vars)
{
	if (key == A_KEY)
		vars->anim = !vars->anim;
	else if (key == C_KEY)
		vars->hue = (vars->hue + 10) % 300;
	else if (key == LEFT_ARROW)
		vars->zcoor.x -= 25;
	else if (key == RIGHT_ARROW)
		vars->zcoor.x += 25;
	else if (key == UP_ARROW)
		vars->zcoor.y += 25;
	else if (key == DOWN_ARROW)
		vars->zcoor.y -= 25;
	else if (key == Q_KEY || key == ESC_KEY)
		destroy_win(vars);
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
	if (button == CLICK_KEY)
	{
		vars->mcoor.x = x;
		vars->mcoor.y = y;
		zoom_in(vars);
		redraw(vars);
	}
	if (button == MOUSE_SCROLL_UP)
	{
		vars->mcoor.x = x;
		vars->mcoor.y = y;
		zoom_out(vars);
		redraw(vars);
	}
	if (button == MOUSE_SCROLL_DOWN)
	{
		vars->mcoor.x = x;
		vars->mcoor.y = y;
		zoom_in(vars);
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
	mlx_key_hook(vars->win, key_event, vars);
	mlx_hook(vars->win, MOUSE_MOTION_EVENT, 1, motion_event, vars);
	mlx_hook(vars->win, DESTROY_NOTIFY_EVENT, 0, destroy_win, vars);
	mlx_hook(vars->win, EXPOSE_EVENT, 1, redraw, vars);
	mlx_hook(vars->win, GRAPHICS_EXPOSE_EVENT, 1, redraw, vars);
}
