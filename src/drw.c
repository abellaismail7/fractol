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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

#include <stdlib.h>
void draw_infos(t_vars *vars)
{
	char str[300];
	
	sprintf(str, "number of iterations: %d\n", vars->iters);
	mlx_string_put(vars->mlx, vars->win, 20, 20, 0XFFFFFFFF ,str);
	sprintf(str, "zoom: %f\n", vars->zoom);
	mlx_string_put(vars->mlx, vars->win, 320, 20, 0XFFFFFFFF ,str);
	sprintf(str, "c");
	mlx_string_put(vars->mlx, vars->win, vars->height / 2, vars->width / 2, 0XFFFFFFFF ,str);
}

double calc_center(double height, double coordinate)
{

	if(coordinate < height / 2)
	{
		
	}
	return height;
}

int redraw( t_vars *vars)
{
	t_data data;
	int x;
	int y;

	data.img = mlx_new_image(vars->mlx, vars->height, vars->width);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
		&data.endian);

	x = 0;
	double range = 2/(vars->zoom * 1.35);
	while(x < vars->height)
	{
		y = 0;
		while(y < vars->width)
		{
			double _x = x + map(vars->zx, 0, vars->width , 0 , vars->width / range );
			double _y = y + map(vars->zy, 0, vars->height, 0 , vars->width / range );
			double a = map(_x , 0, vars->height * vars->zoom, -range, range);
			double b = map(_y , 0, vars->width  * vars->zoom, -range, range);
	

			double ca = a;
			double cb = b;

			int n = 0;

			while (n < vars->iters)
			{
				double aa = a;	

				a = a*a - b*b + ca;
				b = 2*aa*b + cb;
				if (a * a + b * b > 4)
					break;
				n++;
			}

			int color = 30 + round(120 * n * 1.0/ vars->iters);
		
			color = hslToRgb((double)color/100, 1,.5);
			//int color = (int) map(n, 0 , vars->iters, 0XFFFF + 1,0XFFFFFF) + 0XFFFFF  & ~0XFFFF ;
			if (n == vars->iters)
				color = 0;
			my_mlx_pixel_put(&data, x, y, color);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(vars->mlx, vars->win, data.img, 0, 0);
	draw_infos(vars);
	return 1;
}

