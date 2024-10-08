# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: denizozd <denizozd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 22:25:40 by denizozd          #+#    #+#              #
#    Updated: 2024/02/11 22:32:23 by denizozd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPATH = ./libft

SRCS = main.c get_map.c draw_map.c utils.c calculations.c events.c events_keys.c event_mouse.c

OBJS = $(SRCS:.c=.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(NAME)

libft:
	@if [ ! -f $(LIBFTPATH)/libft.a ]; then \
		git submodule update --init --recursive; \
	fi

	@if [ ! -f $(LIBFTPATH)/libft.a ]; then \
		make -s -C $(LIBFTPATH); \
	fi

mlx:
	if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	make -C $(MLX_LIB)

$(NAME): libft mlx $(OBJS)
	$(CC) $(OBJS) -L./libft -lft $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $^ -o $@

clean:
	rm -f $(OBJS)
	cd $(LIBFTPATH) && make clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_LIB)
	cd $(LIBFTPATH) && make fclean

re: fclean all

.PHONY: all clean fclean re libft
