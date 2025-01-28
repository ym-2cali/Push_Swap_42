#include "../inc/push_swap.h"

void    clear_stack(t_list *stack)
{
    while (stack->size)
        pop(stack);
}

t_node  *create_node(int content)
{
    t_node  *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->content = content;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}
    
void    fill_stack(t_list *stack, t_node *node)
{
    if (!stack || !node)
        return ;
    if (stack->size == 0)
    {
        stack->head = node;
        stack->tail = node;
        stack->size++;
        return ;
    }
    node->prev = stack->tail;
    node->next = stack->head;
    stack->tail->next = node;
    stack->head->prev = node;
    stack->size++;
    stack->tail = node;
}
