/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:33:37 by jsubel            #+#    #+#             */
/*   Updated: 2022/03/28 15:29:48 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H

# define FRACTAL_H

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include <stdint.h>

/* 
minilibx image structure

img: image identifier
addr: address of image
bpp: bits per pixel
line_len: number of byters to store one line of image
endian: little or big 
*/
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

/* 
Complex Number

re: real part
im: imaginary part
 */
typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

typedef struct s_color
{
	int8_t			channel[4];
}	t_color;

/* 
fractal structure

mlx: holds minilibx instance
win: pointer to corresponding mlx window
color: color value
color_shift: flexible color changing
img: current rendered image
max_iteration: max number of iterations
factor: dependency between complex number and corresponding pixels
min: minimum real and imaginary part
max: maximum real and imaginary part
cnum: complex number
k: constant complex number for Julia set
show_help: shows keyboard controls
fix_julia: lock mouse movement for current julia fractal
set: fractal set to calculate complex number
 */
typedef struct s_fractal {
	void		*mlx;
	void		*win;
	t_color		color;
	int			color_shift;
	t_image		*img;
	int			max_iteration;
	t_complex	factor;
	t_complex	min;
	t_complex	max;
	t_complex	cnum;
	t_complex	k;
	int			show_help;
	int			fix_julia;
	int			(*set)(struct s_fractal *fractal);
}	t_fractal;

typedef struct s_set {
	char	*name;
	int		(*set)(t_fractal *fractal);
}	t_set;

//			initialization
t_complex	init_complex(double re, double im);
t_image		init_window(void *mlx);
t_fractal	*init_fractal(char *name, void *mlx);
void		default_fractal(t_fractal *fractal);

//		calculate fractal sets
int			iterate_mandelbrot(t_fractal *fractal);
int			iterate_julia(t_fractal *fractal);
int			iterate_burningship(t_fractal *fractal);

//	draw functions
void		draw_fractal(t_fractal *fractal);
void		mlx_pixel_put_img(t_fractal *fractal, int x, int y, t_color color);
int			create_trgb(int t, int r, int g, int b);

//	utilities
void		end_process(char *s);
int			(*get_set(char *name))(t_fractal *fractal);
t_color		color_fractal(int iteration, t_fractal *fractal);
void		print_invalid_parameters(void);
void		string_put(t_fractal *fractal);
int			kill_fractol(t_fractal *fractal);

// controls
int			zoom(int mouse_code, int x, int y, t_fractal *fractal);
int			key_press(int keycode, t_fractal *fractal);
int			julia_mouse_controls(int x, int y, t_fractal *fractal);

#endif