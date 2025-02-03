#include "../inc/push_swap.h"

int check_value(char *arg)
{
    int i;
	long nb;
	int	sign;
    
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
		if ((nb > INT_MAX && sign == 1) || (nb > (long)(INT_MAX) + 1 && sign == -1))
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

int check_duplicate(int *tab, int size)
{
	int i;
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

void	print_stack(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while (tmp->head != tmp->tail)
	{
		printf("%d\n", tmp->head->content);
		tmp->head = tmp->head->next;
	}
	printf("%d\n", tmp->head->content);
}