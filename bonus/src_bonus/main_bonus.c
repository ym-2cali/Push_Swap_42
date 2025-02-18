/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:12:42 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/18 18:08:13 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	fill_head_stack(t_list *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->head = node;
		stack->tail = node;
		node->next = node;
		node->prev = node;
		stack->size++;
		return ;
	}
	node->prev = stack->tail;
	node->next = stack->head;
	stack->tail->next = node;
	stack->head->prev = node;
	stack->size++;
	stack->head = node;
}

void	push_to_head(t_list *stack, int content)
{
	if (!stack)
		return ;
	fill_head_stack(stack, create_node(content));
}

int	main(int ac, char **av)
{
	t_list	stack;
	t_list	stack_b;
    char    *str;
    
	if (ac <= 1)
		return (0);
	ft_bzero(&stack, sizeof(t_list));
	ft_bzero(&stack_b, sizeof(t_list));
	parse(av, &stack);
	str = NULL;
    while ((str = get_next_line(0)) != NULL)
    {
        if (!ft_strncmp(str, "sa\n", 3))
			swap(&stack);
		else if (!ft_strncmp(str, "sb\n", 3))
			swap(&stack_b);
		else if (!ft_strncmp(str, "ss\n", 3))
			swap_swap(&stack_b, &stack);
		else if (!ft_strncmp(str, "pa\n", 3))
			push_to_head(&stack, pop(&stack_b));
		else if (!ft_strncmp(str, "pb\n", 3))
			push_to_head(&stack_b, pop(&stack));
		else if (!ft_strncmp(str, "ra\n", 3))
			rotate(&stack);
		else if (!ft_strncmp(str, "rb\n", 3))
			rotate(&stack_b);
		else if (!ft_strncmp(str, "rr\n", 3))
			rotate_rotate(&stack_b, &stack);
		else if (!ft_strncmp(str, "rra\n", 4))
			reverse_rotate(&stack);
		else if (!ft_strncmp(str, "rrb\n", 4))
			reverse_rotate(&stack_b);
		else if (!ft_strncmp(str, "rrr\n", 4))
			reverse_rotate_rotate(&stack, &stack_b);
		else
		{
			write(2, "Error\n", 6);
			clear_stack(&stack);
			return (0);
		}
    }
	if (sorted(&stack) && !stack_b.size)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stack(&stack);
	return (0);
}
