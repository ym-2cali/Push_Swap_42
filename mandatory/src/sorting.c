/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:53 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/23 17:20:39 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int	failure_case(t_list *stack, int size)
{
	t_node	*tmp;
	int		count;
	int		dif;

	count = 0;
	tmp = stack->head;
	while (tmp != stack->tail)
	{
		dif = tmp->index - tmp->next->index;
		if (dif == 2 || dif == 3 || dif == 4)
			count++;
		tmp = tmp->next;
	}
	dif = tmp->index - tmp->next->index;
	if (dif == 2 || dif == 3 || dif == 4)
		count++;
	if (((count * 100) / size) >= 60)
		return (1);
	return (0);
}

int	chunks(t_list *stack)
{
	if (stack->size <= 100)
		return (16);
	return (32);
}

void	sort_algo(t_list *stack, t_list *stack_b)
{
	int	i;
	int	j;
	int	k;
	int	tmp;

	i = 0;
	k = failure_case(stack, stack->size);
	j = chunks(stack);
	while (stack->size > 0)
	{
		if (stack->head->index <= (i + j))
		{
			tmp = stack->head->index;
			push_to_head(stack_b, pop(stack), 'b');
			if (tmp > i)
				rotate(stack_b, 'b');
			i++;
		}
		else if (k == 1)
			reverse_rotate(stack, 'a');
		else
			rotate(stack, 'a');
	}
}

void	algo(t_list *stack_a, t_list *stack_b)
{
	sort_index(stack_b);
	while (stack_b->size != 0)
	{
		while (stack_b->head->index != (stack_b->size - 1))
		{
			if (!back_or_front(stack_b, stack_b->size - 1))
				rotate(stack_b, 'b');
			else
				reverse_rotate(stack_b, 'b');
		}
		if (stack_b->head->index == (stack_b->size - 1))
		{
			push_to_head(stack_a, pop(stack_b), 'a');
		}
	}
}
