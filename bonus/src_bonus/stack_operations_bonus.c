/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:59 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/18 19:56:04 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	push(t_list *stack, int content)
{
	if (!stack)
		return ;
	fill_stack(stack, create_node(content));
}

int	pop(t_list *stack)
{
	int		cont;
	t_node	*node;

	cont = 0;
	node = stack->head;
	if (stack->size == 1)
	{
		cont = stack->head->content;
		stack->size--;
		clear_stack(stack);
		return (cont);
	}
	cont = stack->head->content;
	stack->head = stack->head->next;
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->size--;
	free(node);
	return (cont);
}

void	rotate_rotate(t_list *a, t_list *b)
{
	if (!a || !b)
		return ;
	rotate(a);
	rotate(b);
}

void	reverse_rotate_rotate(t_list *a, t_list *b)
{
	if (!a || !b)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
}

int	sorted(t_list *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->head;
	while (node != stack->tail)
	{
		tmp = node->next;
		while (tmp != stack->head)
		{
			if (node->content > tmp->content)
				return (0);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}
