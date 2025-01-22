#include "../inc/push_swap.h"

static int	check_sign(int sign)
{
	if (sign == 1)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		s;
	long	result;

	s = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
			return (check_sign(s));
		result = result * 10 + (*str - '0');
		str++;
	}
	return ((int)(result * s));
}


int valid_value(char *arg)
{
    int i;
    
    i = -1;
    while (arg[++i])
        if (!isdigit(arg[i]) && !is_sign(arg[i]))
            return (0);
    return (ft_atoi(arg));
}

int check_duplicate(t_list *stack, int value)
{
    t_node  *tmp;

    tmp = stack->tail;
    if (stack->tail)
    {
        while (tmp != stack->head)
        {
            if (tmp->content == value)
                return (0);
            tmp = stack->tail->prev;
        }
    }
    return (1);        
}
