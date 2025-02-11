/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:52:01 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/04 15:44:37 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "libft/libft.h"
#include <math.h>
#include "mlx.h"

#include <stdio.h>
int	check_data(double val1, double val2, t_fractal type)
{
	int	flag;

	flag = 0;
	if (type == JULIA)
	{
		if (val1 < (-2) || val1 > 2)
			flag = 1;
		if (val2 < (-2) || val2 > 2)
			flag = 1;
	}
	return (flag);
}

void	controller_window(t_fractal_data *data, char *title)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		clean_exit(data, "Error: Can not connect to MLX.");
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, title);
	if (!data->win)
		clean_exit(data, "Error: Can not create a window.");
	data->zoom = 1;
	data->x_offset = 0;
	data->y_offset = 0;
	data->max_iter = 75;
	data->color_scheme = 0;
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		clean_exit(data, "Error: Can not create initial image\n");
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->needs_redraw = 1;
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, handle_key, data);
	mlx_mouse_hook(data->win, mouse_zoom, data);
	mlx_hook(data->win, 17, 0, (int (*)(void *))clean_exit, NULL);
}

void	my_mlx_pixel_put(t_fractal_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		*(unsigned int *)dst = color;
}

static int	calculate_color(double t, int color_scheme)
{
	int	r;
	int	g;
	int	b;

	if (color_scheme == 0)
	{
		r = (int)(7 * (1 - t) * t * t * t * 255);
		g = (int)(14 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(9.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (color_scheme == 1)
	{
		r = (int)(3 * (1 - t) * t * t * t * 255);
		g = (int)(200 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(44 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (color_scheme == 2)
	{
		r = (int)(255 * (1 - t) * t * t * t * 255);
		g = (int)(0 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(32 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else
		return (COLOR_BLACK);
	return ((r << 16) | (g << 8) | b);
}

int	get_color(int iter, int max_iter, int color_scheme)
{
	double	t;

	if (iter == max_iter)
		return (COLOR_BLACK);
	t = (double)iter / (double)max_iter;
	return (calculate_color(t, color_scheme));
}
