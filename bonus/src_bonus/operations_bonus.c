/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:50 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/18 20:12:10 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

void	swap(t_list *stack)
{
	int	tmp;

	if (!stack)
		return ;
	tmp = stack->head->content;
	stack->head->content = stack->head->next->content;
	stack->head->next->content = tmp;
	tmp = stack->head->index;
	stack->head->index = stack->head->next->index;
	stack->head->next->index = tmp;
}

void	swap_swap(t_list *a, t_list *b)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
}

void	reverse_rotate(t_list *a)
{
	if (!a || a->size <= 1)
		return ;
	a->head = a->tail;
	a->tail = a->tail->prev;
}

void	rotate(t_list *a)
{
	if (!a || a->size <= 1)
		return ;
	a->tail = a->head;
	a->head = a->head->next;
}

void	error(t_list *stack)
{
	write(2, "Error\n", 6);
	clear_stack(stack);
	exit(0);
}
