/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:23:40 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/14 10:23:40 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	hue2rgb(double p, double q, double t)
{
	if (t < 0)
		t += 1;
	if (t > 1)
		t -= 1;
	if (6 * t < 1)
		return (p + (q - p) * 6 * t);
	if (2 * t < 1)
		return (q);
	if (3 * t < 2)
		return (p + (q - p) * (2.0 / 3 - t) * 6);
	return (p);
}

int	hsl2rgb(double h, double s, double l)
{
	double	r;
	double	g;
	double	b;
	double	q;
	double	p;

	if (s == 0)
	{
		r = l;
		g = l;
		b = l;
	}
	else
	{
		if (l < 0.5)
			q = l * (1 + s);
		else
			q = l + s - l * s;
		p = 2 * l - q;
		r = hue2rgb(p, q, h + 1.0 / 3);
		g = hue2rgb(p, q, h);
		b = hue2rgb(p, q, h - 1.0 / 3);
	}
	return (((int) round(r * 255)) << 16
		| ((int) round(g * 255)) << 8 | (int) round(b * 255));
}
