CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=undefined -g 

NAME = fdf

SRC_DIR = src/

INCS = -I./includes/

SRC = error.c \
	  draw_utils.c \
	  draw.c \
	  free.c \
	  parse_map.c \
	  parse_utils.c \
	  read_file.c \
	  key_event.c \
	  mouse_event.c \
	  event.c \
	  main.c \
	  orthograpic.c \
	  rotate.c \
	  translate.c \
	  zoom.c \
	  init.c \
	  isometric.c \


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
