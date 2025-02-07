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
    int index;
}   t_node;

typedef struct s_list {
    int size;
    t_node  *head;
    t_node *tail;
}   t_list;

char	**ft_freearr(char **arr);
void    push(t_list *stack, int content);
int     pop(t_list *stack);
void    clear_stack(t_list *stack);
t_node  *create_node(int content);
void    fill_stack(t_list *stack, t_node *node);
int     ft_strlen(const char *str);
char    *str_join(char *s1, char *s2);
char	**ft_split(char *s, char c);
int	    ft_isdigit(char c);
int     ft_atoi(const char *str);
int     check_value(char *arg);
int	    valid_value(char **arr);
int     check_duplicate(int *tab, int size);
int     is_sign(char c);
int     count_signs(char *str);
int     ft_strcmp(char *s1, char *s2);
void	build_stack(int *tab,int size, t_list *stack);
int     *tab(char **arr);
int     tab_size(char **arr);
void	print_stack(t_list *stack);
void	parse(char **av, t_list *stack);
void    swap(t_list *a);
void    rotate(t_list *a);
void    rotate_rotate(t_list *a, t_list *b);
void    reverse_rotate(t_list *a);
void    push_ab(t_list *a, t_list *b);
void    reverse_rotate_rotate(t_list *a, t_list *b);
int     ft_isspace(char c);
int     check_white_spaces(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
void    les_indices(t_list *stack);
void    sort_index(t_list *stack);
int     back_or_front(t_list *stack);
void    sort_5(t_list *stack);
int     if_sorted(t_list *stack);
void    sort_3(t_list *stack);
void    print_rstack(t_list *stack);

#endif
