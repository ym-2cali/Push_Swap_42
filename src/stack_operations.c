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
    t_node *node;

    node = stack->head;
    if (stack->size == 1)
    {
        cont = stack->head->content;
        stack->size--;
        clear_stack(stack);
        return (cont);
    }
    cont = stack->head->content;
    stack->head = stack->head->next;
    stack->head->prev = stack->tail;
    stack->tail->next = stack->head;
    stack->size--;
    free(node);
    return (cont);
}

