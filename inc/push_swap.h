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
int     check_value(char *arg);
int	    valid_value(char **arr);
int     check_duplicate(char **arr);
int     is_sign(char c);
int     count_signs(char *str);
int     valid_input(char **arr);
int     ft_strcmp(char *s1, char *s2);
t_list  *build_stack(int *tab,int size);
int     *tab(char **arr);
int     tab_size(char **arr);
// int	    check_range(char **av, int ac);
void    parse(char **av);

#endif
