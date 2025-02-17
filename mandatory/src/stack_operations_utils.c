/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:56 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 18:20:36 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	clear_stack(t_list *stack)
{
	t_node	*temp;

	while (stack->head != stack ->tail)
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

int	count_bigger(t_list *stack, int i)
{
	int		count;
	t_node	*list;

	count = 0;
	list = stack->head;
	while (list != stack->tail)
	{
		if (list->content < i)
			count++;
		list = list->next;
	}
	if (list && list->content < i)
		count++;
	return (count);
}

void	sort_index(t_list *stack)
{
	t_node	*start;

	start = stack->head;
	while (start != stack->tail)
	{
		start->index = count_bigger(stack, start->content);
		start = start->next;
	}
	if (start)
		start->index = count_bigger(stack, start->content);
}
