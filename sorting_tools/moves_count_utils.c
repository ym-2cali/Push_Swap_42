#include "../inc/push_swap.h"

int before_push(t_list *stack, t_node *node)
{
    int counter;
    t_list      *tmp_a;
    t_list      stack_b;
    t_node      *tmp;

    counter = 0;
    tmp_a = stack;
    if (node == stack->head)
    {
        rotate(tmp_a);
        push(&stack_b, pop(tmp_a));
        return (2);
    }
    else if (node == stack->tail)
    {
        push(&stack_b, pop(tmp_a));
        return (1);
    }
    else
    {
        tmp = node;
        if (!back_or_front(stack, tmp->index))
        {
            while (tmp != stack->tail)
            {
                rotate(tmp_a);
                counter++;
            }
        }
        else
        {
            while (tmp != stack->tail)
            {
                reverse_rotate(tmp_a);
                counter++;
            }
        }
        push(&stack_b, pop(tmp_a));
        counter++;
    }
    return (counter);
}

int sort_moves_counter(t_list *stack)
{
    int     counter;
    t_node  *tmp;

    counter = 0;
    tmp = stack->head;
    while (tmp->content > stack->tail->content)
        tmp = tmp->next;
    // if (!back_or_front())
}

void    fill_moves_number(t_list *stack)
{
    t_node  *tmp;

    tmp = stack->head;
    while (tmp != stack->tail)
    {
        tmp->moves_number = 
        tmp = tmp->next;
    }
}