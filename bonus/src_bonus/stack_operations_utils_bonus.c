/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:11:32 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/25 17:20:01 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	clear_stack(t_list *stack)
{
	t_node	*temp;

	while (stack->head != stack->tail)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
	free(stack->head);
}

t_node	*create_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = content;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	fill_stack(t_list *stack, t_node *node)
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
	stack->tail = node;
}
