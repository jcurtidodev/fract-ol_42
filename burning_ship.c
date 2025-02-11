/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:57:28 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/03 20:12:42 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"
#include <math.h>

#include <stdio.h>

static int	burning_ship(t_fractal_data *data)
{
	t_complex	z;
	double		temp_re;
	int			iter;

	iter = 0;
	z.re = data->cr;
	z.im = data->ci;
	while (z.re * z.re + z.im * z.im <= 4.0 && iter < data->max_iter)
	{
		temp_re = z.re * z.re - z.im * z.im + data->cr;
		z.im = fabs(2.0 * z.re * z.im) + data->ci;
		z.re = fabs(temp_re);
		iter++;
	}
	return (iter);
}

static void	render_pixel_burning_ship(t_fractal_data *data, int x, int y)
{
	int		color;
	double	scale_x;
	double	scale_y;

	scale_x = (4.0 / WIN_WIDTH) / data->zoom;
	scale_y = (4.0 / WIN_HEIGHT) / data->zoom;
	data->cr = (x - WIN_WIDTH / 2.0) * scale_x + data->x_offset;
	data->ci = (y - WIN_HEIGHT / 2.0) * scale_y + data->y_offset;
	color = get_color(burning_ship(data),
			data->max_iter, data->color_scheme);
	my_mlx_pixel_put(data, x, y, color);
}

void	render_burning_ship(t_fractal_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			render_pixel_burning_ship(data, x, y);
			x++;
		}
		y++;
	}
}

void	controller_burning_ship(int argc)
{
	t_fractal_data	data;

	data.type = BURNING_SHIP;
	controller_window(&data, "Burning ship");
	if (argc != 2)
		clean_exit(&data, invalid_args_message());
	data.needs_redraw = 1;
	update_image(&data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
