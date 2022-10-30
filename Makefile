MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

VPATH = src

# Compiler Variables
CC		= cc
# CFLAGSS	= -Wall -Wextra -Werror -g
INCFLAG	= -I include -I libft
AR		= ar
ARFLAGS = -rcs
# File Variables
NAME	= libftprintf.a
SRC		= $(wildcard src/*.c)
OBJ		= $(addprefix _bin/,$(notdir $(SRC:.c=.o)))

$(NAME): $(OBJ) | libft/libft.a
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^

libft/libft.a :
	(cd libft && make && make clean)

_bin :
	mkdir _bin

_bin/%.o : %.c libft/libft.a | _bin
	$(CC) -c $(CFLAGSS) $(INCFLAG) $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:		fclean all

all:	$(NAME)

run: re
	$(CC) -o printf $(CFLAGSS) $(INCFLAG) $(NAME) main.c
	./printf

.PHONY: clean fclean re all run