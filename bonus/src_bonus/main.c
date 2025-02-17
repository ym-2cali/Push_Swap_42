/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:12:42 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 20:25:05 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_list	stack;
	t_list	stack_b;

	if (ac <= 1)
		return (0);
	ft_bzero(&stack, sizeof(t_list));
	ft_bzero(&stack_b, sizeof(t_list));
	parse(av, &stack);
    while (get_next_line(0))
    {
        
    }
	if (sorted(&stack))
		return (0);
	return (0);
}
