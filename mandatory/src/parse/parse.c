/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:53:05 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/18 17:49:20 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	tab_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	*tab(char **arr)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * tab_size(arr));
	if (!tab)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		tab[i] = ft_atoi(arr[i]);
		i++;
	}
	return (tab);
}

void	build_stack(int *tab, int size, t_list *stack)
{
	int	i;

	i = 0;
	while (i < size)
		push(stack, tab[i++]);
}

void	parse(char **av, t_list *stack)
{
	char	**arr;
	int		size;
	int		*bat;

	arr = join_it(av);
	size = check_errors_size(arr);
	bat = tab(arr);
	ft_freearr(arr);
	check_int_tab_errors(bat, size);
	build_stack(bat, size, stack);
	free(bat);
	if (stack->size != size)
	{
		write(2, "Error\n", 6);
		clear_stack(stack);
		exit(0);
	}
}

char	**join_it(char **av)
{
	int		i;
	char	*str;
	char	**arr;

	i = 1;
	str = ft_strdup(av[i]);
	if (!str || !check_white_spaces(str))
	{
		write(2, "Error\n", 6);
		if (str)
			free(str);
		exit(0);
	}
	i++;
	while (av[i])
	{
		str = str_join(str, av[i]);
		if (!str)
			exit(0);
		i++;
	}
	arr = ft_split(str, ' ');
	free(str);
	return (arr);
}
