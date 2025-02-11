/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:35:29 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/03 20:11:13 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdlib.h>
#include <mlx.h>

int	handle_key(int keycode, t_fractal_data *data)
{
	if (keycode == ESC)
		clean_exit(data, NULL);
	else if (keycode == LEFT_KEY)
		data->x_offset -= 0.1 / data->zoom;
	else if (keycode == UP_KEY)
		data->y_offset -= 0.1 / data->zoom;
	else if (keycode == RIGHT_KEY)
		data->x_offset += 0.1 / data->zoom;
	else if (keycode == DOWN_KEY)
		data->y_offset += 0.1 / data->zoom;
	else if (keycode == SPACE)
		data->color_scheme = (data->color_scheme + 1) % 3;
	else
		return (0);
	data->needs_redraw = 1;
	return (0);
}

static void	apply_zoom(t_fractal_data *data, double zoom_factor,
				int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	new_zoom;
	double	scale_x;
	double	scale_y;

	scale_x = 4.0 / WIN_WIDTH;
	scale_y = 4.0 / WIN_HEIGHT;
	new_zoom = data->zoom * zoom_factor;
	mouse_re = (x - WIN_WIDTH / 2.0) * scale_x / data->zoom
		+ data->x_offset;
	mouse_im = (y - WIN_HEIGHT / 2.0) * scale_y / data->zoom
		+ data->y_offset;
	data->x_offset = mouse_re - ((x - WIN_WIDTH / 2.0)
			* scale_x / new_zoom);
	data->y_offset = mouse_im - ((y - WIN_HEIGHT / 2.0)
			* scale_y / new_zoom);
	data->zoom = new_zoom;
	if (zoom_factor == 1.0)
		data->needs_redraw = 0;
	else
		data->needs_redraw = 1;
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	mouse_zoom(int button, int x, int y, t_fractal_data *data)
{
	double	zoom_factor;

	if (button == 4 || button == 5)
	{
		zoom_factor = 1.2;
		if (button == 5)
			zoom_factor = 1.0 / 1.2;
		apply_zoom(data, zoom_factor, x, y);
	}
	return (0);
}
