NAME = so_long

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

# paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -Ilibft

MLX_DIR = minilibx-linux

MLX = $(MLX_DIR)/libmlx_Linux.a

SRCS = src/main.c \
       src/utils.c \

OBJS = $(SRCS:.c=.o)

# ===== rules =====

all: $(LIBFT) $(NAME) $(MLX)

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -sC $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) fclean
	$(MAKE) -sC $(MLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
