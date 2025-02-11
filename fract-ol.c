/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:59:19 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/03 20:14:07 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdlib.h>
#include <mlx.h>

int	clean_exit(t_fractal_data *data, char *error_message)
{
	if (!data)
		exit(EXIT_SUCCESS);
	if (error_message)
		ft_putstr_fd(error_message, 2);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (error_message)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	update_image(t_fractal_data *data)
{
	if (!data || !data->mlx || !data->win)
		clean_exit(data, "Error: struct 'data' not initialized correctly\n");
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
		clean_exit(data, "Error: Can not update the image\n");
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->addr)
		clean_exit(data, "Error: mlx_get_data_addr returned NULL\n");
	render_fractal(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	loop_hook(t_fractal_data *data)
{
	if (data->needs_redraw)
		update_image(data);
	return (0);
}

void	render_fractal(t_fractal_data *data)
{
	if (!data->needs_redraw)
		return ;
	if (data->type == JULIA)
		render_julia(data);
	else if (data->type == MANDELBROT)
		render_mandelbrot(data);
	else if (data->type == BURNING_SHIP)
		render_burning_ship(data);
	data->needs_redraw = 0;
}
