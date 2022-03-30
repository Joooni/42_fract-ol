/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:48 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/30 15:16:15 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"
#include "../incl/errors.h"
#include "../incl/keys.h"

static void	colorshift(t_fractal *fractal)
{
	fractal->color_shift = (fractal->color_shift + 1) % 3;
	draw_fractal(fractal);
}

static void	move(int keycode, t_fractal *fractal)
{
	double	changepos_x;
	double	changepos_y;

	changepos_x = 0.0;
	changepos_y = 0.0;
	if (keycode == ARROW_LEFT)
		changepos_x = fabs(fractal->max.re - fractal->min.re) * -0.05;
	else if (keycode == ARROW_RIGHT)
		changepos_x = fabs(fractal->max.re - fractal->min.re) * 0.05;
	else if (keycode == ARROW_UP)
		changepos_y = fabs(fractal->max.im - fractal->min.im) * -0.05;
	else if (keycode == ARROW_DOWN)
		changepos_y = fabs(fractal->max.im - fractal->min.im) * 0.05;
	fractal->min.re += changepos_x;
	fractal->max.re += changepos_x;
	fractal->min.im += changepos_y;
	fractal->max.im += changepos_y;
	draw_fractal(fractal);
}

int	change_max_iteration(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_PLUS)
		fractal->max_iteration += 10;
	else
		fractal->max_iteration -= 10;
	draw_fractal(fractal);
	return (0);
}

int	key_press(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		move(keycode, fractal);
	else if (keycode == KEY_C)
		colorshift(fractal);
	else if (keycode == KEY_R)
	{
		default_fractal(fractal);
		draw_fractal(fractal);
	}
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		change_max_iteration(keycode, fractal);
	else if (keycode == KEY_SPACE)
		fractal->fix_julia *= -1;
	else
		printf(":c I don't know that key, sorry. :c\n");
	return (0);
}
