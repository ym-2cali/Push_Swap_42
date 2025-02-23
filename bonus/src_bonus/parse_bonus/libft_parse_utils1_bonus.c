/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_parse_utils1_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:43:50 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/23 18:21:55 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc_bonus/push_swap_bonus.h"

int	ft_atoi(const char *str, char **arr, int *tab)
{
	int		s;
	long	result;

	s = 1;
	result = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (INT_MAX - (*str - '0')) / 10 && s != -1)
		{
			write(2, "Error\n", 6);
			ft_freearr(arr);
			free(tab);
			exit(0);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * s));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;
	size_t			i;

	c = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
