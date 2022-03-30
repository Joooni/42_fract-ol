/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:00:43 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/30 09:50:31 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"
#include "../incl/errors.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!image)
		end_process(ERR_IMAGE_INIT);
	image->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image->img)
		end_process(ERR_IMAGE_INIT);
	image->addr = mlx_get_data_addr(
			image->img,
			&(image->bpp),
			&(image->line_len),
			&(image->endian));
	return (image);
}

void	default_fractal(t_fractal *fractal)
{
	fractal->max_iteration = 100;
	fractal->min = init_complex(-2.0, -2.0);
	fractal->max.re = 2.0;
	fractal->max.im = fractal->min.im
		+ (fractal->max.re - fractal->min.re) * (WINDOW_HEIGHT / WINDOW_WIDTH);
	fractal->color_shift = 0;
	fractal->k = init_complex(-0.4, 0.6);
	fractal->show_help = 1;
	fractal->fix_julia = -1;
}

t_fractal	*init_fractal(char *name, void *mlx)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)ft_calloc(1, sizeof(t_fractal));
	if (!fractal)
		end_process(ERR_FRACTAL_INIT);
	fractal->mlx = mlx;
	fractal->win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, name);
	if (!fractal->win)
		end_process(ERR_WINDOW_INIT);
	fractal->img = init_image(mlx);
	default_fractal(fractal);
	fractal->set = get_set(name);
	if (fractal->set == NULL)
		end_process(ERR_SET_NAME);
	mlx_hook(fractal->win, 2, 1L << 0, key_press, fractal);
	mlx_mouse_hook(fractal->win, zoom, fractal);
	mlx_hook(fractal->win, 17, 0, kill_fractol, fractal);
	if (ft_strncmp("Julia", name, ft_strlen(name)) == 0)
		mlx_hook(fractal->win, 6, 1L << 6, julia_mouse_controls, fractal);
	return (fractal);
}
