SRC = src/operations.c src/stack_utils.c src/stack_operations.c libft/ft_strjoin.c libft/ft_strlen.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -ggdb3

NAME = push_swap

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c inc/push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm $(OBJ)

fclean: clean
	@rm $(NAME)

re: fclean all

.PHONY: clean