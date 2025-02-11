/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:11:14 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/03 21:03:55 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stddef.h>
# include <stdint.h>
# include <math.h>
# include "libft/libft.h"

// Configuracion basica
# define WIN_WIDTH 800
# define WIN_HEIGHT 800
# define MLX_ERR "Error al inicializar MLX\n"
# define WIN_ERR "Error al crear la ventana\n"
# define X_JULIA -0.7
# define Y_JULIA -0.328

// Colores basicos
# define NUM_SCHEMES 3
# define COLOR_BLACK    0x000000  // Negro

// Keys
# define ESC            65307
# define LEFT_KEY       65361
# define UP_KEY         65362
# define RIGHT_KEY      65363
# define DOWN_KEY       65364
# define SPACE          32

// Enumeracion de fractales disponibles
typedef enum e_fractal
{
	JULIA,
	MANDELBROT,
	BURNING_SHIP
}	t_fractal;

// Estructura para guardar parametros de fractal
typedef struct s_fractal_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_fractal		type;
	double			zoom;
	double			x_offset;
	double			y_offset;
	int				max_iter;
	int				needs_redraw;
	double			cr;
	double			ci;
	int				color_scheme;
}	t_fractal_data;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

// Funciones para inicializar y renderizar fractales
void	render_fractal(t_fractal_data *data);
void	my_mlx_pixel_put(t_fractal_data *data, int x, int y, int color);

// Utils
char	*invalid_args_message(void);
double	ft_simple_strtod(const char *str);
int		check_data(double val1, double val2, t_fractal type);

// Window && keys
int		handle_key(int keycode, t_fractal_data *data);
int		clean_exit(t_fractal_data *data, char *error_message);
int		loop_hook(t_fractal_data *data);
void	update_image(t_fractal_data *data);
void	controller_window(t_fractal_data *data, char *title);
int		mouse_zoom(int button, int x, int y, t_fractal_data *data);
int		get_color(int iter, int max_iter, int color_scheme);

// Fractales
void	render_mandelbrot(t_fractal_data *data);
void	render_julia(t_fractal_data *data);
void	render_burning_ship(t_fractal_data *data);
void	controller_julia(int argc, char *argv[]);
void	controller_mandelbrot(int argc);
void	controller_burning_ship(int argc);

#endif
