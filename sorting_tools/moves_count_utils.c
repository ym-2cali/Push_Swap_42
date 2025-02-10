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

int distance(t_list *stack)
{
    int     reference;
    int     counter;
    t_node  *node;
    t_node  *tmp;

    counter = 0;
    tmp = stack->head;
    reference = stack->tail->content;
    while (tmp->content > reference && tmp->next->content > reference && tmp != stack->tail)
    {
        counter++;
        tmp = tmp->next;
    }
    return (counter);
}

int sort_moves_counter(t_list *stack)
{
    int     counter;
    t_list *stack_b;
    t_node  *tmp;

    counter = 0;
    stack_b = stack;
    if (stack->size == 3)
    {
        if (stack->tail->content < stack->tail->prev->content && stack->tail->content > stack->head->content)
        {// 195 
            rotate(stack_b);
            counter += 1;
        }
        else if (stack->head->content > stack->head->next->content && stack->head->content < stack->tail->content)
        {
            reverse_rotate(stack_b);// 519 
            counter += 1;
        }
        else if (stack->head->content < stack->head->next->content && stack->head->content > stack->tail->content)
        {
            swap(stack_b);//  591 
            counter += 1;
        }
        else if (stack->tail->content < stack->head->content && stack->tail->content > stack->tail->prev->content)
        {
            rotate(stack_b);//915g
            swap(stack_b);
            counter += 2;
        }
        else if (if_sorted(stack_b))
        {
            swap(stack_b);
            reverse_rotate(stack_b);// 951
            counter += 1;
        }
        else
            counter += 0;
    }
    else if (stack_b->size > 3)
    {
        tmp = stack_b->tail;
        if (tmp->content > stack_b->head->content)
        {
            rotate(stack_b);
            counter += 1;
        }
        else
        {
            if (distance(stack_b) < (stack_b->size / 2))
            {
                while (tmp->content < tmp->next->content && tmp->content > tmp->prev->content)
                {
                    counter++;
                    tmp = tmp->next;
                }
            }
            // else if (distance(stack_b) >= (stack_b->size / 2))

        }
        // while (stack->tail->prev->content < tmp->content )
    }
    return (counter);
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