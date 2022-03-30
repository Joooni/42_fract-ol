/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:13:17 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/30 09:47:00 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"
#include "../incl/keys.h"

static double	lin_interp(double start, double end, double interp)
{
	return (start + ((end - start) * interp));
}

int	zoom(int mousecode, int x, int y, t_fractal *fractal)
{
	t_complex	mouse_pos;
	double		interp;

	if (mousecode == MOUSE_UP || mousecode == MOUSE_DOWN)
	{
		mouse_pos = init_complex(
				(double)x / (WINDOW_WIDTH / (fractal->max.re - fractal->min.re))
				+ fractal->min.re,
				-1 * (double)y
				/ (WINDOW_HEIGHT / (fractal->max.im - fractal->min.im))
				+ fractal->max.im);
		if (mousecode == MOUSE_UP)
			interp = 1.0 / 0.8;
		else
			interp = 1.0 / 1.20;
		fractal->min.re = lin_interp(mouse_pos.re, fractal->min.re, interp);
		fractal->max.re = lin_interp(mouse_pos.re, fractal->max.re, interp);
		fractal->min.im = lin_interp(mouse_pos.im, fractal->min.im, interp);
		fractal->max.im = lin_interp(mouse_pos.im, fractal->max.im, interp);
		draw_fractal(fractal);
	}
	return (0);
}

int	julia_mouse_controls(int x, int y, t_fractal *fractal)
{
	if (fractal->fix_julia != 1)
	{
		fractal->k = init_complex(
				4 * ((double)x / WINDOW_WIDTH - 0.5),
				4 * ((double)(WINDOW_HEIGHT - y) / WINDOW_HEIGHT - 0.5));
		draw_fractal(fractal);
	}
	return (0);
}
