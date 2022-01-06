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

	vars.width = 1200;
	vars.height = 1200;
	vars.iters = 80;
	vars.zoom = 2;
	vars.zx = 0;
	vars.zy = 0;

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
