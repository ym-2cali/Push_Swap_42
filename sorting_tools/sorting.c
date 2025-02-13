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
                push(stack_b, pop(stack), 'a');
                if (stack->head->index > i)
                {
                    reverse_rotate(stack_b, 'b');
                }
                i++;             
            }
            else
                rotate(stack, 'a');
        }
    }
    else
    {
        j = size / 15;
        while (i < size && size > 0)
        {
            if (stack->head->content <= (i + j))
            {
                push(stack_b, pop(stack), 'a');
                if (stack->head->content > i)
                    reverse_rotate(stack_b, 'b');
                i++;             
            }
            else
                reverse_rotate(stack, 'a');
        }
    }
    les_indices(stack_b);
    sort_index(stack_b);
}

// void    algo(t_list *stack_a, t_list *stack_b)
// {
//     while (stack_b->size > 0)
//     {
//         // printf("Tail index: %d, Expected: %d\n", stack_b->tail->index, stack_b->size - 1);
//         while (stack_b->head->index != (stack_b->size  - 1))
//         {
//             // fprintf(stderr, "WARNING: swap: A node is NULL.");
//             if (!back_or_front(stack_b, stack_b->size - 1))
//                 rotate(stack_b);
//             else
//                 reverse_rotate(stack_b);
//         }
//         if (stack_b->head->index == (stack_b->size  - 1))
//             push(stack_a, pop(stack_b));
//     }
// }

void    algo(t_list *stack_a, t_list *stack_b)
{
    int i;

    i = 0;
    while (stack_b->size > 0)
    {
        while (stack_b->head->index != i)
        {
            if (!back_or_front(stack_b, i))
                rotate(stack_b, 'b');
            else
                reverse_rotate(stack_b, 'b');
            
        }
        if (stack_b->head->index == i)
            push(stack_a, pop(stack_b), 'b');
        i++;
    }
}