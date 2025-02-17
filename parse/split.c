/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-maa <yael-maa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:58:12 by yael-maa          #+#    #+#             */
/*   Updated: 2025/02/17 14:58:46 by yael-maa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char const *s, char c)
{
	size_t	n_words;
	size_t	i;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			n_words += 1;
		while (s[i] != c && s[i])
			i++;
	}
	return (n_words);
}

static size_t	ft_len2all(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (s[i])
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[i] && s[i] != c)
		{
			len += 1;
			i++;
		}
		return (len);
	}
	return (0);
}

char	**ft_freearr(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

static char	*ft_fullfill(char **arr, char *s, char c, size_t i)
{
	char	*tmp;

	tmp = arr[i];
	if (*s != c && *s)
	{
		while (*s != c && *s)
		{
			*tmp = *s;
			tmp++;
			s++;
		}
		*tmp = '\0';
	}
	return (s);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	n_words;

	if (!s)
		return (NULL);
	n_words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!arr)
		return (free(s), NULL);
	i = 0;
	while (i < n_words)
	{
		while (*s == c)
			s++;
		arr[i] = malloc(sizeof(char) * (ft_len2all(&(*s), c) + 1));
		if (!arr[i])
			return (ft_freearr(arr));
		s = ft_fullfill(arr, s, c, i);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
