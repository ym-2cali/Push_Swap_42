#include "../inc/push_swap.h"

void    swap(t_list *stack)
{
    int tmp;

    if (!stack)
    {
        fprintf(stderr, "WARNING: swap: A node is NULL.");
        return;
    }
    tmp = stack->head->content;
    stack->head->content = stack->head->next->content;
    stack->head->next->content = tmp;
    tmp = stack->head->index;
    stack->head->index = stack->head->next->index;
    stack->head->next->index = tmp;
    write(1, "pab\n", 4);
}

void    swap_swap(t_list *a, t_list *b)
{
    swap(a);
    swap(b);
}

void    push_ab(t_list *a, t_list *b)
{
    t_node  *node;

    node = create_node(b->tail->content);

    if (!node)
    {
        fprintf(stderr, "WARNING: push-ab: create-node is NULL.");
        return;
    }
    (*node).prev = a->tail;
    node->next = a->head;

    a->tail->next = node;
    a->head->prev = node;

    a->tail = node;

    a->size++;
}

void    reverse_rotate(t_list *a)
{
    if (!a|| a->size <= 1)
        return ;
    a->head = a->tail; 
    a->tail = a->tail->prev;
}

void    rotate(t_list *a)
{
    if (!a || a->size <= 1)
        return ;
    a->tail = a->head;
    a->head = a->head->next;
}

void    rotate_rotate(t_list *a, t_list *b)
{
    rotate(a);
    rotate(b);
}
void    reverse_rotate_rotate(t_list *a, t_list *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}