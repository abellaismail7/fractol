/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:55:33 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/06 15:55:33 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	double zoom;
	int 	iters;
	int zx;
	int zy;
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
double map (int n, int f1, int t1, int f2, int t2);
int motion_event(int x);

#endif
