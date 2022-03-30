/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:25:35 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/28 15:01:58 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int	iterate_julia(t_fractal *fractal)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractal->cnum.re, fractal->cnum.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0)
		<= 4 && iteration < fractal->max_iteration)
	{
		z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + fractal->k.re,
				2 * z.re * z.im + fractal->k.im);
		iteration++;
	}
	return (iteration);
}
