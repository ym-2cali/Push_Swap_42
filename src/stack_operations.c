#include "../inc/push_swap.h"

void    push(t_list *stack, int content)
{   
    if (!stack)
        return ;
    fill_stack(stack, create_node(content));
}

int pop(t_list *stack)
{
    int     cont = 0;

    if (stack->size == 1)
    {
        stack->size--;
        clear_stack(stack);
        return (stack->head->content);
    }
    cont = stack->head->content;
    stack->head = stack->head->next;
    stack->head->prev = stack->tail;
    stack->tail->next = stack->head;
    stack->size--;
    return (cont);
}

