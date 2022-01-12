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

typedef struct s_coor
{
	int x;
	int y;
} t_coor;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	double 	zoom;
	int 	iters;
	t_coor * julia;
	t_coor mcoor;
	t_coor zcoor;
	
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int redraw( t_vars *vars);
int keyevent(int key, t_vars *vars);
int mouse_event(int button,int x, int y, t_vars *data);
double map (double n, double f1, double t1, double f2, double t2);
int motion_event(int x, int y, t_vars *vars);
int hslToRgb(double h, double s, double l);

#endif
