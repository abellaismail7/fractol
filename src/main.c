#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	write(1, str, i);
}

int destroy_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx,vars->win);
	exit(0);
}

int event_loop(int n)
{
	t_vars vars;

	vars.width 	= 500;
	vars.height = 500;
	vars.iters 	= 200;
	vars.zoom = 1;
	vars.mcoor.x = vars.width / 2;
	vars.mcoor.y = vars.height / 2;
	vars.julia = NULL;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "test");
	mlx_mouse_hook(vars.win, mouse_event, &vars);
	mlx_hook(vars.win, 6, 1, motion_event, &vars);
	mlx_key_hook(vars.win, keyevent, &vars);
	mlx_hook(vars.win, 17, 0, destroy_win, &vars);

	mlx_hook(vars.win, 12, 1, redraw, &vars);
	mlx_hook(vars.win, 13, 1, redraw, &vars);
	t_coor coor;
	coor.x = 0;
	coor.y = 0;
	
	//vars.julia = &coor;
	n++;
	mlx_loop(vars.mlx);
	return 0;
}

int main (int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("1. Manlderbolt\n");
		ft_putstr("2. Julia\n");
		ft_putstr("3. Mine\n");
	}
	else {
		int n = av[1][1] - '0';
		event_loop(n);
	}

	//mlx_destroy_display(mlx);
	return 0;
}
