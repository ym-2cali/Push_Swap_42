SRC =  $(addprefix mandatory/src/, main.c  operations.c  stack_operations_utils.c parse/parse_utils.c parse/libft_parse_utils.c \
parse/parse.c parse/split.c parse/libft_parse_utils1.c sorting.c  stack_operations.c parse/errors.c mini_sort.c)

SRC_BONUS = $(addprefix bonus/src_bonus/, main_bonus.c  operations_bonus.c  stack_operations_bonus.c  stack_operations_utils_bonus.c \
parse_bonus/errors_bonus.c  parse_bonus/libft_parse_utils1_bonus.c  parse_bonus/libft_parse_utils_bonus.c  parse_bonus/parse_bonus.c  parse_bonus/parse_utils_bonus.c  parse_bonus/split_bonus.c \
get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c)

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

NAME_BONUS = checker

all:$(NAME)

$(NAME):$(OBJ) mandatory/inc/push_swap.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus:$(NAME_BONUS)

$(NAME_BONUS):$(OBJ_BONUS) bonus/inc_bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean