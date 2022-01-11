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
	sprintf(str, "c1");
	mlx_string_put(vars->mlx, vars->win, vars->ox,vars->oy, 0XFFFFFFFF ,str);
	sprintf(str, "x:%d", vars->ox);
	mlx_string_put(vars->mlx, vars->win, 20 , 450, 0XFFFFFFFF ,str);
	sprintf(str, "y:%d", vars->oy);
	mlx_string_put(vars->mlx, vars->win, 220 , 450, 0XFFFFFFFF ,str);
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
	double range = 1/(vars->zoom);
	double _x = map(vars->ox, 0, vars->width, 0, vars->width * vars->zoom)  * 0;
	double _y = map(vars->oy, 0, vars->width, 0, vars->width * vars->zoom)  * 0;
	while(x < vars->height)
	{
		y = 0;
		while(y < vars->width)
		{
			double a = map(x + _x , 0, vars->height * vars->zoom, -range, range);
			double b = map(y + _y , 0, vars->width  * vars->zoom, -range, range);
			double ca = a;
			double cb = b;
			if (vars->julia)
			{
				ca = map(vars->julia->x, 0, vars->width, -1, 1);
				cb = map(vars->julia->y, 0, vars->width, -1, 1);
			}
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
		
			color = hslToRgb((double)color/100, 0.8,.5);
			//int color = (int) map(n, 0 , vars->iters, 0XFFFF + 1,0XFFFFFF) + 0XFFFFF  & ~0XFFFF ;
			if (n == vars->iters)
				color = 0;
			my_mlx_pixel_put(&data, x, y, color);
			y++;
		}
		x++;
	}

	mlx_put_image_to_window(vars->mlx, vars->win, data.img, 0, 0);
	draw_infos(vars );
	return 1;
}

