SRC = src/main.c src/operations.c src/stack_operations.c src/stack_operations_utils.c parse/parse_utils.c parse/libft_parse_utils.c parse/parse.c parse/split.c parse/libft_parse_utils1.c parse/parse.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror #-ggdb3 -fsanitize=address

NAME = push_swap

all:$(NAME)

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