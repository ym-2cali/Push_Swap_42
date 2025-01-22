#include "../inc/push_swap.h"

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


int check_value(char *arg)
{
    int i = 0;

    while (arg[i])
    {
        
        i++;
    }
}