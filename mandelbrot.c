/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:21:19 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/03 20:19:32 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"

static int	mandelbrot(t_fractal_data *data)
{
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;
	int		iter;

	zr = 0;
	zi = 0;
	zr2 = 0;
	zi2 = 0;
	iter = 0;
	while (zr2 + zi2 <= 4 && iter < data->max_iter)
	{
		zi = 2 * zr * zi + data->ci;
		zr = zr2 - zi2 + data->cr;
		zr2 = zr * zr;
		zi2 = zi * zi;
		iter++;
	}
	return (iter);
}

static void	render_pixel_mandelbrot(t_fractal_data *data, int x, int y)
{
	double	scale_x;
	double	scale_y;
	int		color;

	scale_x = (4.0 / WIN_WIDTH) / data->zoom;
	scale_y = (4.0 / WIN_HEIGHT) / data->zoom;
	data->cr = (x - WIN_WIDTH / 2.0) * scale_x + data->x_offset;
	data->ci = (y - WIN_HEIGHT / 2.0) * scale_y + data->y_offset;
	color = get_color(mandelbrot(data), data->max_iter, data->color_scheme);
	my_mlx_pixel_put(data, x, y, color);
}

void	render_mandelbrot(t_fractal_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			render_pixel_mandelbrot(data, x, y);
			x++;
		}
		y++;
	}
}

void	controller_mandelbrot(int argc)
{
	t_fractal_data	data;

	data.type = MANDELBROT;
	controller_window(&data, "Mandelbrot");
	if (argc != 2)
		clean_exit(&data, invalid_args_message());
	data.needs_redraw = 1;
	update_image(&data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
