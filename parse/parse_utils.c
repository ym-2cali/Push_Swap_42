/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:45:22 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 12:52:52 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_value(char *arg)
{
	int		i;
	long	nb;
	int		sign;

	i = count_signs(arg);
	if (i > 1)
		return (0);
	if (i == 1 && !is_sign(arg[0]))
		return (0);
	sign = -1 * (arg[0] == '-') + 1 * (arg[0] == '+');
	nb = 0;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		nb = nb * 10 + (arg[i] - '0');
		if ((nb > INT_MAX && sign == 1)
			|| (nb > (long)(INT_MAX) + 1 && sign == -1))
			return (0);
		i++;
	}
	return (1);
}

int	valid_value(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!check_value(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

char	*str_join(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s2 || s2[0] == '\0' || !check_white_spaces(s2))
	{
		write(2, "Error\n", 6);
		free(s1);
		return (NULL);
	}
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!s3)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	s3[i] = ' ';
	i++;
	j = -1;
	while (s2[++j])
		s3[i + j] = s2[j];
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}
