NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
LIBFT_DIR = libft
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
SRC_LIBFT = $(wildcard $(LIBFT_DIR)/*.c)
OBJ_LIBFT = $(SRC_LIBFT:$(LIBFT_DIR)/%.c=$(LIBFT_DIR)/%.o)
all : $(NAME)
$(NAME) : $(OBJ) $(OBJ_LIBFT)
	- @Make -C libft
	- @cp libft/libft.a $(NAME)
	- @ar rc $(NAME) $(OBJ)
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	- @$(CC) -c $(CFLAGS) $< -o $@
fclean: clean
	- @rm -f $(NAME)
clean:
	- @rm -f $(OBJ) $(OBJ_LIBFT)
re: fclean all

run: re
	- @$(CC) $(CFLAGS) -o printf main.c $(NAME)
	- @./printf

.PHONY: $(NAME) all fclean clean run