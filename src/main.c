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
#include <errno.h>

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
	if (fract != 3)
		vars->burn = 0;
}

void	event_loop(int n, t_coor *coor)
{
	t_vars	vars;

	reset_vars(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "Fract-ol");
	vars.julia = coor;
	alloc_image(&vars);
	register_events(&vars);
	pick_fract(&vars, n);
	mlx_loop(vars.mlx);
	destroy_win(&vars);
}

int	read_params(char **av, t_coor *coor, long *n)
{
	coor->x = 0;
	coor->y = 0;
	errno = EINVAL;
	if (!ft_atoi(av[1], n) || *n < 1 || *n > 3)
		return (0);
	if (av[2])
	{
		if (!av[3] || *n != 2
			|| !ft_atoi(av[2], &coor->x) || !ft_atoi(av[3], &coor->y))
			return (0);
	}
	errno = 0;
	return (1);
}

int	main(int ac, char **av)
{
	long	n;
	t_coor	coor;

	errno = 0;
	if (ac > 1 && read_params(av, &coor, &n))
	{
		event_loop(n, &coor);
		return (0);
	}
	if (errno != 0)
		perror("fractol: ");
	ft_putstr("Usage: fractol {1|2 [xcoordinate ycoordinate]|3}\n\n");
	ft_putstr("1. Manlderbolt\n");
	ft_putstr("2. Julia\n");
	ft_putstr("3. Mine\n");
	return (1);
}
