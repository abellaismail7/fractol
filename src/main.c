/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:56:39 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/13 18:56:39 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	pick_fract(t_vars *vars, int fract)
{
	if (fract != 2)
		vars->julia = NULL;
}

int	event_loop(int n, t_coor *coor)
{
	t_vars	vars;

	reset_vars(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "test");
	register_events(&vars);
	vars.julia = coor;
	pick_fract(&vars, n);
	mlx_loop(vars.mlx);
	return (0);
}

int	read_params(char **av, t_coor *coor, int *n)
{
	coor->x = 0;
	coor->y = 0;
	if (!ft_atoi(av[1], n) || *n < 1 || *n > 3)
		return (0);
	if (av[2])
	{
		if (!av[3] || *n != 2
			|| !ft_atoi(av[2], &coor->x) || !ft_atoi(av[3], &coor->y))
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		n;
	t_coor	coor;

	if (ac > 1 && read_params(av, &coor, &n))
	{
		event_loop(n, &coor);
		return (0);
	}
	ft_putstr("Usage: fractol {1|2 [xcoordinate ycoordinate]|3}\n\n");
	ft_putstr("1. Manlderbolt\n");
	ft_putstr("2. Julia\n");
	ft_putstr("3. Mine\n");
	return (1);
}
