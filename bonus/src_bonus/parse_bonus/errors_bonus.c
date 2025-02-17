/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:56:23 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 20:15:20 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/push_swap_bonus.h"

int	check_errors_size(char **arr)
{
	int	size;

	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (!valid_value(arr))
	{
		write(2, "Error\n", 6);
		ft_freearr(arr);
		exit(0);
	}
	size = tab_size(arr);
	return (size);
}

void	check_int_tab_errors(int *bat, int size)
{
	if (!bat)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (check_duplicate(bat, size))
	{
		write(2, "Error\n", 6);
		free(bat);
		exit(0);
	}
}
