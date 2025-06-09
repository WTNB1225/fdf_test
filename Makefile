CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=undefined

NAME = fdf

SRC_DIR = src/

INCS = -I./includes/

SRC = error.c \
	  draw.c \
	  free.c \
	  parse_map.c \
	  parse_utils.c \
	  read_file.c \
	  main.c \
	  init.c \


SRCS = $(addprefix $(SRC_DIR), $(SRC))

.PHONY: all clean fclean re bonus

$(NAME): $(SRCS)
	make -C libft all
	$(CC) $(CFLAGS) $(INCS) -o $@ $^ -L libft -lft -L mlx -lmlx -lXext -lX11 -lm

all: $(NAME)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all
