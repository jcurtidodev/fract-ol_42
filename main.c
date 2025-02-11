/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:36:20 by jcurtido          #+#    #+#             */
/*   Updated: 2025/02/03 20:16:51 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "libft/libft.h"

char	*invalid_args_message(void)
{
	char	*err;

	err = "The availables options are 'julia', 'mandelbrot'\n"
		"and 'burning_ship:'\n"
		"julia:		needs two double numbers between -2 and 2\n"
		"mandelbrot:	do not need values\n"
		"burning_ship:	do not need values\n";
	return (err);
}

int	main(int argc, char *argv[])
{
	if (argc < 2)
		return (ft_printf("%s", invalid_args_message()));
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		controller_julia(argc, argv);
	else if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		controller_mandelbrot(argc);
	else if (ft_strncmp(argv[1], "burning_ship", 13) == 0)
		controller_burning_ship(argc);
	else
		return (ft_printf("%s", invalid_args_message()));
	return (0);
}
