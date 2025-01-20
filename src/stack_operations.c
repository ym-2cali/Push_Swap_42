#include "../inc/push_swap.h"

void    push(t_list *stack, int *content)
{
    t_node  *last;

    if (!stack || !content)
        return ;
    last = malloc(sizeof(t_node));
    if (!last)
    {
        clear_stack(stack);
        return;
    }
    fill_stack(stack, create_node(content));
}

int pop(t_list *stack)
{
    t_list  *tmp;
    int content; 

    content = stack->tail->content;
    if (!stack)
        return (0);
    tmp = stack;
    free(tmp->tail);
    stack->tail = stack->tail->prev;
    stack->head->prev = stack->tail;
    stack->tail->next = stack->head;
    stack->size--;
    return (content);
}