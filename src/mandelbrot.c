/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 08:53:41 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/07 09:27:42 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	iterate_mandelbrot(t_fractal *fractal)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractal->cnum.re, fractal->cnum.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && iteration < fractal->max_iteration)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractal->cnum.re,
				2 * z.re * z.im + fractal->cnum.im);
		iteration++;
	}
	return (iteration);
}
