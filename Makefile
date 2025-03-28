
CC = gcc
CFLAGS = -Wall -Werror -Wextra -fPIE
NAME = so_long
INCLUDES = -I./includes -I./Libft -I./rsrcs
MLX_FLAGS = -L./rsrcs -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
LIBFT = -L./Libft -lft

SRC = core/main.c               \
	  core/render_image.c       \
	  core/render_move.c        \
	  core/set_data.c           \
	  core/render_ennemy_move.c \
	  core/collision.c          \
	  core/map.c                \
	  core/get_content.c        \
	  core/map_checker.c 		\
	  core/map_dup.c			\
	  core/fire_ball.c          \
	  core/fd_checker.c         \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C Libft/
	@make -C rsrcs/
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c includes/so_long.h
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJ)
	@make clean -C Libft/
	@make clean -C rsrcs/

fclean: clean
	rm -f $(NAME)
	@make fclean -C Libft/

re: fclean all

.PHONY: all clean fclean re mlx libft