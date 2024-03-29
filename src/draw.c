/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:34:45 by jsubel            #+#    #+#             */
/*   Updated: 2022/12/08 14:31:50 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"
#include "../incl/errors.h"

void	mlx_pixel_put_img(t_fractal *fractal, int x, int y, t_color color)
{
	int	i;

	i = (x * fractal->img->bpp / 8)
		+ (y * fractal->img->line_len);
	fractal->img->addr[i] = color.channel[3];
	fractal->img->addr[++i] = color.channel[2];
	fractal->img->addr[++i] = color.channel[1];
	fractal->img->addr[++i] = color.channel[0];
}

void	draw_fractal(t_fractal *frctl)
{
	int			x;
	int			y;
	t_color		color;

	frctl->factor = init_complex(
			(frctl->max.re - frctl->min.re) / (WINDOW_WIDTH),
			(frctl->max.im - frctl->min.im) / (WINDOW_HEIGHT)
			);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		frctl->cnum.im = frctl->max.im - y * frctl->factor.im;
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			frctl->cnum.re = frctl->min.re + x * frctl->factor.re;
			color = color_fractal(frctl->set(frctl), frctl);
			mlx_pixel_put_img(frctl, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(frctl->mlx, frctl->win, frctl->img->img, 0, 0);
	string_put(frctl);
}

void	string_put(t_fractal *fractal)
{
	// char	*str;
	(void) fractal;
	// mlx_string_put(fractal->mlx, fractal->win, 25,
	// 	WINDOW_HEIGHT - 100, 0x444444, "C - Shift Color");
	// mlx_string_put(fractal->mlx, fractal->win, 25,
	// 	WINDOW_HEIGHT - 70, 0x444444, "R - Reset");
	// mlx_string_put(fractal->mlx, fractal->win, 25,
	// 	WINDOW_HEIGHT - 40, 0x444444,
	// 	"+ and - - Change Iteration Depth");
	// mlx_string_put(fractal->mlx, fractal->win,
	// 	WINDOW_WIDTH - 260, WINDOW_HEIGHT - 70, 0x444444,
	// 	"Current Iteration Depth:");
	// str = ft_itoa(fractal->max_iteration);
	// mlx_string_put(fractal->mlx, fractal->win,
	// 	WINDOW_WIDTH - 40, WINDOW_HEIGHT - 40, 0x444444,
	// 	str);
	// free(str);
}

t_color	color_fractal(int iteration, t_fractal *fractal)
{
	t_color	color;
	double	t;

	t = (double)iteration / fractal->max_iteration;
	color.channel[0] = 0;
	color.channel[(0 + fractal->color_shift) % 3 + 1]
		= (uint8_t)(9 * (1 - t) * pow(t, 3) * 255);
	color.channel[(1 + fractal->color_shift) % 3 + 1]
		= (uint8_t)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	color.channel[(2 + fractal->color_shift) % 3 + 1]
		= (uint8_t)(8.5 * pow((1 - t), 3) * t * 255);
	return (color);
}
