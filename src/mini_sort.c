/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:08:18 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 17:50:36 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_2(t_list *stack)
{
	if (sorted(stack))
		return ;
	if (stack->tail->content < stack->head->content)
		swap(stack, 'a');
}

void	sort_3(t_list *stack)
{
	if (sorted(stack))
		return ;
	else if (stack->tail->content < stack->tail->prev->content
		&& stack->tail->content > stack->head->content)
	{
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (stack->head->content > stack->head->next->content
		&& stack->head->content < stack->tail->content)
		swap(stack, 'a');
	else if (stack->head->content < stack->head->next->content
		&& stack->head->content > stack->tail->content)
		reverse_rotate(stack, 'a');
	else if (stack->tail->content < stack->head->content
		&& stack->tail->content > stack->tail->prev->content)
		rotate(stack, 'a');
	else if (stack->tail->prev->content < stack->head->content
		&& stack->tail->prev->content > stack->tail->content)
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
}

int	back_or_front(t_list *stack, int ind)
{
	int		len;
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	i = 0;
	while (tmp->index != ind)
	{
		i++;
		tmp = tmp->next;
	}
	len = (stack->size - 1) / 2;
	if (i < len)
		return (0);
	return (1);
}

void	sort_4(t_list *stack, t_list *stack_b)
{
	if (sorted(stack))
		return ;
	while (stack->head->index != 0)
	{
		if (!back_or_front(stack, 0))
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	if (stack->head->index == 0)
		push_to_head(stack_b, pop(stack), 'b');
	sort_3(stack);
	push_to_head(stack, pop(stack_b), 'a');
}

void	sort_5(t_list *stack, t_list *stack_b)
{
	if (sorted(stack))
		return ;
	sort_index(stack);
	while (stack->head->index != 0)
	{
		if (!back_or_front(stack, 0))
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	if (stack->head->index == 0)
		push_to_head(stack_b, pop(stack), 'b');
	while (stack->head->index != 1)
	{
		if (!back_or_front(stack, 1))
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	if (stack->head->index == 1)
		push_to_head(stack_b, pop(stack), 'b');
	sort_3(stack);
	push_to_head(stack, pop(stack_b), 'a');
	push_to_head(stack, pop(stack_b), 'a');
}
