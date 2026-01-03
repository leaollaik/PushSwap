NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c \
	operations.c operations2.c \
	index.c complex.c \
	simple_sort.c medium_sort.c adaptive_sort.c \
	strategy_utils.c bench.c \
	utils.c utils_2.c utils_3.c utils_4.c \
	t_node_helpers.c parsing.c

OBJ = $(SRC:.c=.o)

INCLUDES = -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lm -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
