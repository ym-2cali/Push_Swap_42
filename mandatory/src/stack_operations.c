/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:59 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 15:44:13 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	rotate(a, 's');
	rotate(b, 's');
	write(1, "rab\n", 4);
}

void	reverse_rotate_rotate(t_list *a, t_list *b)
{
	reverse_rotate(a, 's');
	reverse_rotate(b, 's');
	write(1, "rrr\n", 4);
}
