/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:52:05 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/06 18:52:05 by iait-bel         ###   ########.fr       */
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
}

int redraw( t_vars *vars)
{
	t_data data;
	int i;
	int j;

	data.img = mlx_new_image(vars->mlx, vars->height, vars->width);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
		&data.endian);


	i = 0;
	while(i < vars->height)
	{
		j = 0;
		while(j < vars->width)
		{
			double a = map(i + vars->zx - vars->height/2, 0, vars->height, vars->zoom * -1, vars->zoom) ;
			double b = map(j + vars->zy - vars->width/2, 0, vars->width, vars->zoom * -1, vars->zoom)  ;

			double ca = a;
			double cb = b;

			int n = 0;

			while (n < vars->iters)
			{
				// a^2 - b^2 - 2ab
				double aa = a;	
				
				a = a*a - b*b + ca;
				b = 2*aa*b + cb;

				if (a + b > 16)
					break;
				n++;
			}
			int color = (int) map (n, 0, 100, 0XFFFF, 0XFFFFFF) & ~0XFFFF;
			if (n == vars->iters)
			{
				color = 0;
			}
			my_mlx_pixel_put(&data, i, j, color);
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(vars->mlx, vars->win, data.img, 0, 0);
	draw_infos(vars);
	return 1;
}

