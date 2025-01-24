#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_node {
    struct s_node    *next;
    struct s_node    *prev;
    int content;
} t_node;

typedef struct s_list {
    int size;
    t_node  *head;
    t_node *tail;

}   t_list;

void    push(t_list *stack, int content);
int     pop(t_list *stack);
void    clear_stack(t_list *stack);
t_node  *create_node(int content);
void    fill_stack(t_list *stack, t_node *node);
int     ft_strlen(char *str);
char    *str_join(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int	    ft_isdigit(char c);
int     ft_atoi(const char *str);
int     valid_value(char *arg);
int     check_duplicate(t_list *stack, int value);
int     is_sign(char c);
int     count_signs(char *str);
int     valid_input(t_list *stack, char *str);
t_list  *parse(char **arr);
int     ft_strcmp(char *s1, char *s2);

#endif
