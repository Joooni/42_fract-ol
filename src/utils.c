/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:31:29 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/30 13:51:51 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"
#include "../incl/errors.h"

void	end_process(char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

int	kill_fractol(t_fractal *fractal)
{
	if (fractal->img->img != NULL)
	{
		mlx_destroy_image(fractal->mlx, fractal->img->img);
	}
	if (fractal->win != NULL)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
	}
	exit(0);
}

int	(*get_set(char *name)) (t_fractal *fractal)
{
	size_t			i;
	int				(*set)(t_fractal *fractal);
	static t_set	sets[] = {
	{"Mandelbrot", &iterate_mandelbrot},
	{"Julia", &iterate_julia},
	{"Burning Ship", &iterate_burningship}
	};

	i = 0;
	set = NULL;
	while (i < (sizeof(sets) / sizeof(t_set)))
	{
		if (ft_strncmp(name, sets[i].name, ft_strlen(name)) == 0)
			set = sets[i].set;
		i++;
	}
	return (set);
}

void	print_invalid_parameters(void)
{
	ft_putendl_fd("(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Wrong Input ✧ﾟ･: *ヽ(◕ヮ◕ヽ)", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Please specify name of fractal", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Currently available fractals:", 1);
	ft_putendl_fd(" * Mandelbrot", 1);
	ft_putendl_fd(" * Julia", 1);
	ft_putendl_fd(" * Burning Ship (dont't forget the quotation marks!)", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ Thanks for trying, though ✧ﾟ･: *ヽ(◕ヮ◕ヽ)", 1);
}
