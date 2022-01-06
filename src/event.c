#include "fractol.h"
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

int keyevent(int key, t_vars *vars)
{
	printf("key pressed: %d", key);
	fflush(stdout);
	if (key == 105)
	{
		vars->maxval += .1;
		vars->minval -= .1;
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	if (key == 111)
	{
		vars->minval += .1;
		vars->maxval -= .1;
		//if (vars->iters > 50)
		//	vars->iters -= 10;
		mlx_clear_window(vars->mlx, vars->win);
		redraw(vars);
	}
	if (key  == 12 || key == 53)
	{
		mlx_destroy_window(vars->mlx,vars->win);
		exit(0);
	}
	return 1;
}

int mouse_event(int button,int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		vars->zx = x;
		vars->zy = y;
		redraw(vars);
	}
	return 0;
	//if (button == 5)
	//{
	//	vars->zoom -= 0.1;
	//	vars->zx = x;
	//	vars->zy = y;
	//	//vars->iters += 10;
	//	mlx_clear_window(vars->mlx, vars->win);
	//	redraw(vars);
	//}
	//if (button == 4)
	//{
	//	vars->zoom += 0.1;
	//	vars->zx = x;
	//	vars->zy = y;
	//	//if (vars->iters > 50)
	//	//	vars->iters -= 10;
	//	mlx_clear_window(vars->mlx, vars->win);
	//	redraw(vars);
	//}
	return (1);
}

int motion_event(int x)
{
x++;
	return 1;
}
