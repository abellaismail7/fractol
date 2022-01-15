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

#include <errno.h>
#include <stdlib.h>
#include <mlx.h>
#include "fractol.h"

int	destroy_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	reset_vars(t_vars *vars)
{
	vars->width = 600;
	vars->height = 600;
	vars->iters = 200;
	vars->zoom = 1;
	vars->mcoor.x = 0;
	vars->mcoor.y = 0;
	vars->zcoor.x = 0;
	vars->zcoor.y = 0;
	vars->julia = NULL;
	vars->burn = 1;
	vars->anim = 0;
	vars->hue = 30;
}

void	alloc_image(t_vars *vars)
{
	vars->data.img = mlx_new_image(vars->mlx, vars->height, vars->width);
	vars->data.addr = mlx_get_data_addr(
			vars->data.img,
			&vars->data.bits_per_pixel,
			&vars->data.line_length,
			&vars->data.endian);
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
