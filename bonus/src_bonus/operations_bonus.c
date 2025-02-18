/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:59:50 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/18 17:14:06 by yael-maa         ###   ########.fr       */
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
