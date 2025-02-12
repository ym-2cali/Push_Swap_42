#include "../inc/push_swap.h"

void sort_algo(t_list *stack, t_list *stack_b)
{
    // t_node  *tmp;
    int    size;
    int    i;
    int    j;

    size = stack->size;
    i = 0;
    if (size <= 100)
    {
        j = size / 8;
        while (stack->size > 0)
        {
            if (stack->head->index <= (i + j))
            {
                push(stack_b, pop(stack));
                if (stack->head->index > i)
                {
                    reverse_rotate(stack_b);
                }
                i++;             
            }
            else
                rotate(stack);
        }
    }
    else
    {
        j = size / 15;
        while (i < size && size > 0)
        {
            if (stack->head->content <= (i + j))
            {
                push(stack_b, pop(stack));
                if (stack->head->content > i)
                    reverse_rotate(stack_b);
                i++;             
            }
            else
                reverse_rotate(stack);
        }
    }
}