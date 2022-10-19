NAME = libftprintf.a

RM = rm -f
CC = cc
# CFLAGS = -Wall -Wextra -Werror

AR		= ar
ARFLAGS = -rcs
INCFLAG	= -I .

LIBFT_DIR = libft

MANDO = ft_printf.c ft_flags.c ft_convert.c

BONUS = 

MANDOOBJ	= $(MANDO:.c=.o)
BONUSOBJ = $(BONUS:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:$(LIBFT_DIR)/%.c=$(LIBFT_DIR)/%.o)

$(NAME): $(MANDOOBJ) $(OBJ_LIBFT)
	- @Make -C $(LIBFT_DIR)
	- @cp libft/libft.a $(NAME)
	- @$(AR) $(ARFLAGS) $(NAME) $(MANDOOBJ)

run: re
	- @$(CC) $(CFLAGS) -o printf main.c $(NAME)
	- @./printf

bonus: $(BONUSOBJ)
	@$(AR) $(ARFLAGS) $(NAME) $^

%.o : %.c
	@$(CC) -c $(CFLAGS) $(INCFLAG) $< -o $@

clean:
	- @$(RM) $(MANDOOBJ) $(BONUSOBJ)

fclean: clean
	- @$(RM) ${NAME}

re: fclean all

all: $(NAME) #bonus

.PHONY: all clean fclean re bonus