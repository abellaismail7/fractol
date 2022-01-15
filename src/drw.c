/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:52:05 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/06 23:10:55 by bella            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, t_coor coor, int color)
{
	char	*dst;

	dst = data->addr
		+ (coor.y * data->line_length + coor.x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	iterate(t_vars *vars, t_pair ab, t_pair c_ab)
{
	double	a;
	double	b;
	double	tmp;
	int		n;

	n = 0;
	a = ab.a;
	b = ab.b;
	while (n < vars->iters)
	{
		tmp = a * a - b * b + c_ab.a;
		if (vars->burn)
			b = fabs(2 * a * b) + c_ab.b;
		else
			b = 2 * a * b + c_ab.b;
		a = tmp;
		if (a * a + b * b > 4)
			break ;
		n++;
	}
	return (n);
}

int	get_color(t_vars *vars, t_coor coor, double range)
{
	t_pair	ab;
	t_pair	c;
	int		n;
	t_pair	pr;

	pr.a = -range;
	pr.b = range;
	ab.a = map(coor.x + vars->zcoor.x, 0, vars->height, pr);
	ab.b = map(coor.y + vars->zcoor.y, 0, vars->width, pr);
	c.a = ab.a;
	c.b = ab.b;
	if (vars->julia)
	{
		pr.a = -.6;
		pr.b = .4;
		c.a = map(vars->julia->x, 0, vars->width, pr);
		c.b = map(vars->julia->y, 0, vars->width, pr);
	}
	n = iterate(vars, ab, c);
	if (n == vars->iters)
		return (0);
	return (
		hsl2rgb(
			(30 + round(120 * n * 1.0 / vars->iters))
			/ vars->hue, .7, .5));
}

int	redraw(t_vars *vars)
{
	t_coor	coor;
	int		color;
	double	range;

	range = 2 / (vars->zoom);
	coor.x = 0;
	while (coor.x < vars->height)
	{
		coor.y = 0;
		while (coor.y < vars->width)
		{
			color = get_color(vars, coor, range);
			my_mlx_pixel_put(&vars->data, coor, color);
			coor.y++;
		}
		coor.x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.img, 0, 0);
	return (1);
}
