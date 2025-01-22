#include "../inc/push_swap.h"

int valid_input(t_list *stack, char *str)
{
    int i;

    if (!valid_value(str))
        return (0);
    else
        i = check_duplicate(stack, valid_value(str));
    return (i);
}

void    parse(t_liststack)