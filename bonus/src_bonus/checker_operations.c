/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:14:34 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/25 17:20:25 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

int	check_opration(char *str, char *arr)
{
	char	**opers;
	int		i;

	opers = (char *[]){"pa\n", "pb\n", "ra\n", "rb\n", "rr\n", "rra\n",
		"rrb\n", "rrr\n", "sa\n", "sb\n", "ss\n", NULL};
	i = 0;
	while (opers[i])
	{
		if (!ft_strcmp(opers[i], str))
			return (1);
		i++;
	}
	free(arr);
	return (0);
}

void	apply_operation(char **opers, t_list *stack, t_list *stack_b)
{
	while (*opers)
	{
		if (!ft_strncmp(*opers, "sa\n", 3))
			swap(stack);
		else if (!ft_strncmp(*opers, "sb\n", 3))
			swap(stack_b);
		else if (!ft_strncmp(*opers, "ss\n", 3))
			swap_swap(stack_b, stack);
		else
			operations2(stack, stack_b, *opers);
		opers++;
	}
}
