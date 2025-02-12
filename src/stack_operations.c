#include "../inc/push_swap.h"

void    push(t_list *stack, int content)
{   
    if (!stack)
        return ;
    fill_stack(stack, create_node(content));
}

int pop(t_list *stack)
{
    t_node  *tmp;
    int     cont = 0;

    tmp = stack->tail;
    cont = stack->tail->content;
    // if (stack->size == 1)
    // {
    //     stack->head = NULL;
    //     stack->tail = NULL;
    // }
    stack->tail = stack->tail->prev;
    stack->head->prev = stack->tail;
    stack->tail->next = stack->head;
    stack->size--;

    free(tmp);

    return (cont);
}

