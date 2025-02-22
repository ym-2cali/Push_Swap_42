/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:47 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 18:22:30 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	push_to_head(t_list *stack, int content, char c)
{
	if (!stack)
		return ;
	fill_head_stack(stack, create_node(content));
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	sorting(t_list *stack, t_list *stack_b)
{
	sort_index(stack);
	if (stack->size == 2)
		sort_2(stack);
	else if (stack->size == 3)
		sort_3(stack);
	else if (stack->size == 4)
		sort_4(stack, stack_b);
	else if (stack->size == 5)
		sort_5(stack, stack_b);
	else
	{
		sort_algo(stack, stack_b);
		algo(stack, stack_b);
	}
	clear_stack(stack);
}

int	main(int ac, char **av)
{
	t_list	stack;
	t_list	stack_b;

	if (ac <= 1)
		return (0);
	ft_bzero(&stack, sizeof(t_list));
	ft_bzero(&stack_b, sizeof(t_list));
	parse(av, &stack);
	if (sorted(&stack))
		return (0);
	sorting(&stack, &stack_b);
	if (stack.size > 0)
		clear_stack(&stack);
	return (0);
}
