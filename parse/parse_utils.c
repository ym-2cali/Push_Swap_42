#include "../inc/push_swap.h"

int check_value(char *arg)
{
    int i;
    
	if (count_signs(arg) > 1)
		return (0);
    i = 0;
    while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-')
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

int check_duplicate(char **arr)
{
	int i;
	int	j;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (!ft_strcmp(arr[i], arr[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_input(char **arr)
{
	if (valid_value(arr) && check_duplicate(arr))
		return (1);
	return (0);
}