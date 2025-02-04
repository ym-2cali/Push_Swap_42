#include "../inc/push_swap.h"

void    push(t_list *stack, int content)
{
    // t_node *n;
    
    if (!stack)
        return ;
    fill_stack(stack, create_node(content));
}

// int pop(t_list *stack)
// {
//     // t_node  *tmp;
//     int     content = 0;

//     // content = stack->tail->content;
//     // tmp = stack->tail;
//     // stack->tail = stack->tail->prev;
//     // stack->head->prev = stack->tail;
//     // stack->tail->next = stack->head;
//     // stack->size--;
    
//     // free(tmp);
//     return (content);
// }
