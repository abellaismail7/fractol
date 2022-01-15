/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:55:33 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/06 23:04:22 by bella            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_pair {
	double	a;
	double	b;
}	t_pair;

typedef struct s_coor
{
	long	x;
	long	y;
}	t_coor;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	double	zoom;
	int		iters;
	int		anim;
	int		hue;
	int		burn;
	t_data	data;
	t_coor	*julia;
	t_coor	mcoor;
	t_coor	zcoor;
}	t_vars;

int		redraw( t_vars *vars);
int		keyevent(int key, t_vars *vars);
int		mouse_event(int button, int x, int y, t_vars *data);
double	map(double n, double f1, double t1, t_pair p);
int		motion_event(int x, int y, t_vars *vars);
int		hsl2rgb(double h, double s, double l);
void	register_events(t_vars *vars);
void	reset_vars(t_vars *vars);
int		destroy_win(t_vars *vars);
int		ft_atoi(char *str, long *res);
void	zoom_in(t_vars *vars);
void	zoom_out(t_vars *vars);
void	alloc_image(t_vars *vars);

#endif
