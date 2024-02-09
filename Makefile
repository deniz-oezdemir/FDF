NAME = fdf
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFTPATH = ./libft

SRCS = main.c get_map.c draw_map.c utils.c calculations.c events.c events_keys.c event_mouse.c

OBJS = $(SRCS:.c=.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm #check necessity of these links

all: $(NAME)

makelibft:
	make -C $(LIBFTPATH)
	cp $(LIBFTPATH)/$(LIBFTNAME) .
	mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	make -C $(MLX_LIB)
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
