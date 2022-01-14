/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:59:05 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/13 18:59:05 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

int	destroy_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	reset_vars(t_vars *vars)
{
	vars->width = 500;
	vars->height = 500;
	vars->iters = 200;
	vars->zoom = 1;
	vars->mcoor.x = vars->width / 2;
	vars->mcoor.y = vars->height / 2;
	vars->zcoor.x = 0;
	vars->zcoor.y = 0;
	vars->julia = NULL;
	vars->anim = 0;
	vars->hue = 30;
}

int	ft_atoi(char *str, long *res)
{
	int	sign;

	sign = -1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	*res = 0;
	while (*str >= '0' && *str <= '9')
	{
		*res *= 10;
		*res -= *str - '0';
		str++;
	}
	if (*str != 0)
		return (0);
	*res *= sign;
	return (1);
}
