/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:37:05 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/03 20:15:47 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "mlx.h"

static double	get_zr_zi(int x, int y, t_fractal_data *data, int flag)
{
	double	scale_x;
	double	scale_y;
	double	zr;
	double	zi;

	if (flag)
	{
		scale_x = (4.0 / WIN_WIDTH) / data->zoom;
		zr = (x - WIN_WIDTH / 2.0) * scale_x + data->x_offset;
		return (zr);
	}
	else
	{
		scale_y = (4.0 / WIN_HEIGHT) / data->zoom;
		zi = (y - WIN_HEIGHT / 2.0) * scale_y + data->y_offset;
		return (zi);
	}
}

static int	julia(double zr, double zi, t_fractal_data *data)
{
	double	temp;
	int		iter;

	iter = 0;
	while ((zr * zr + zi * zi) <= 4 && iter < data->max_iter)
	{
		temp = zr * zr - zi * zi + data->cr;
		zi = 2 * zr * zi + data->ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

static void	render_pixel_julia(t_fractal_data *data, int x, int y)
{
	double	zr;
	double	zi;
	int		color;

	zr = get_zr_zi(x, y, data, 1);
	zi = get_zr_zi(x, y, data, 0);
	color = get_color(julia(zr, zi, data), data->max_iter, data->color_scheme);
	my_mlx_pixel_put(data, x, y, color);
}

void	render_julia(t_fractal_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			render_pixel_julia(data, x, y);
			x++;
		}
		y++;
	}
}

void	controller_julia(int argc, char *argv[])
{
	t_fractal_data	data;

	data.type = JULIA;
	controller_window(&data, "Julia");
	if (argc <= 2)
	{
		data.cr = X_JULIA;
		data.ci = Y_JULIA;
	}
	else if (argc == 3)
		clean_exit(&data, invalid_args_message());
	else if (argv[2] && argv[3])
	{
		if (check_data(ft_simple_strtod(argv[2]), ft_simple_strtod(argv[3]),
				data.type))
			clean_exit(&data, invalid_args_message());
		data.cr = ft_simple_strtod(argv[2]);
		data.ci = ft_simple_strtod(argv[3]);
	}
	data.needs_redraw = 1;
	update_image(&data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
