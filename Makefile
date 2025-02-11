# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 14:19:39 by jcurtido          #+#    #+#              #
#    Updated: 2025/02/11 17:01:10 by jcurtido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre
NAME = fract-ol

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directorios
SRCS_DIR = .
OBJS_DIR = ./objs
LIBFT_DIR = ./libft

# Archivos fuente
SRCS = fract-ol.c main.c utils.c ft_strtod.c julia.c mandelbrot.c burning_ship.c events.c
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# MinilibX
MLX = -I ./minilibx-linux -L minilibx-linux -lmlx -lXext -lX11
LIBFT = $(LIBFT_DIR)/libft.a

# Reglas
all: $(LIBFT) $(NAME)

$(LIBFT):
	@test -f $@ || $(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME) -lm

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
