/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:49:16 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/08 09:55:30 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"
#include "../incl/errors.h"

static void	main_fractal(char *name_of_set)
{
	t_fractal	*fractal;
	void		*mlx;

	mlx = mlx_init();
	fractal = init_fractal(name_of_set, mlx);
	draw_fractal(fractal);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		main_fractal(argv[1]);
	}
	else
		print_invalid_parameters();
	return (0);
}
