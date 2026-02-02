NAME = so_long

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -Ilibft

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a

SRCS = src/main.c \
       src/utils.c \
	   src/render.c \
	   src/init.c \
	   src/cleanup.c \
	   src/parser.c

OBJ_DIR = obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(NAME) $(MLX)

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -sC $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -sC $(LIBFT_DIR) fclean
	rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re