#include <math.h>
#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx,vars->win);
	exit(0);
}

int main ()
{
	t_vars vars;

	vars.width = 1500;
	vars.height = 1500;
	vars.iters = 100;
	vars.minval = -2;
	vars.maxval = 2;
	vars.zx = vars.width / 2;
	vars.zy = vars.height / 2;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.height, vars.width, "test");
	mlx_mouse_hook(vars.win, mouse_event, &vars);
	mlx_hook(vars.win, 6, 1, motion_event, &vars);
	mlx_key_hook(vars.win, keyevent, &vars);
	mlx_hook(vars.win, 12, 1, redraw, &vars);
	mlx_hook(vars.win, 13, 1, redraw, &vars);
	mlx_hook(vars.win, 17, 0, close, &vars);
	mlx_loop(vars.mlx);

	//mlx_destroy_display(mlx);
	return 0;
}
