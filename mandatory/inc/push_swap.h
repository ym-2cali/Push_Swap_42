/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:28:50 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/25 14:26:19 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef struct s_node {
	struct s_node	*next;
	struct s_node	*prev;
	int				content;
	int				index;
}	t_node;

typedef struct s_list {
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_list;

char	**ft_freearr(char **arr);
void	push(t_list *stack, int content);
int		pop(t_list *stack);
void	clear_stack(t_list *stack);
t_node	*create_node(int content);
void	fill_stack(t_list *stack, t_node *node);
int		ft_strlen(const char *str);
char	*str_join(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		ft_isdigit(char c);
int		ft_atoi(const char *str, char **arr, int *tab);
int		check_value(char *arg);
int		valid_value(char **arr);
int		check_duplicate(int *tab, int size);
int		is_sign(char c);
int		count_signs(char *str);
int		ft_strcmp(char *s1, char *s2);
void	build_stack(int *tab, int size, t_list *stack);
int		*tab(char **arr);
int		tab_size(char **arr);
void	parse(char **av, t_list *stack);
void	swap(t_list *a, char c);
void	rotate(t_list *a, char c);
void	rotate_rotate(t_list *a, t_list *b);
void	reverse_rotate(t_list *a, char c);
void	reverse_rotate_rotate(t_list *a, t_list *b);
int		ft_isspace(char c);
int		check_white_spaces(char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s1);
void	sort_index(t_list *stack);
int		back_or_front(t_list *stack, int ind);
void	sort_5(t_list *stack, t_list *stack_b);
void	sort_3(t_list *stack);
void	sort_algo(t_list *stack, t_list *stack_b);
void	algo(t_list *stack_a, t_list *stack_b);
void	fill_head_stack(t_list *stack, t_node *node);
void	push_to_head(t_list *stack, int content, char c);
int		sorted(t_list *stack);
char	**join_it(char **av);
int		check_errors_size(char **arr);
void	check_int_tab_errors(int *bat, int size);
void	sort_4(t_list *stack, t_list *stack_b);
void	sorting(t_list *stack, t_list *stack_b);
void	sort_2(t_list *stack);
int		failure_case(t_list *stack, int size);
int		chunks(t_list *stack);

#endif
