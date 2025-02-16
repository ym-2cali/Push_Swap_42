#include "../inc/push_swap.h"

void sort_algo(t_list *stack, t_list *stack_b)
{
    int    size;
    int    i;
    int    j;
    int    tmp;

    size = stack->size;
    i = 0;
    sort_index(stack);
    if(size <=100)
        j = size / 8;
    else
        j = size / 15;
    while (stack->size > 0)
    {
        if (stack->head->index <= (i + j))
        {
            tmp = stack->head->index;
            push_to_head(stack_b, pop(stack), 'b');
            if (tmp > i)
                rotate(stack_b, 'b');  
            i++;
        }
        else
            rotate(stack,'a');
    }
    sort_index(stack_b);
}

void    algo(t_list *stack_a, t_list *stack_b)
{
    while (stack_b->size != 0)
    {
        while (stack_b->head->index != (stack_b->size - 1))
        {
            if (!back_or_front(stack_b, stack_b->size - 1))
                rotate(stack_b, 'b');
            else
                reverse_rotate(stack_b, 'b');
            
        }
        if (stack_b->head->index == (stack_b->size - 1))
        {
            push_to_head(stack_a, pop(stack_b), 'a');
        }
    }
}