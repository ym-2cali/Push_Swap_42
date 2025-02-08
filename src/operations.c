#include "../inc/push_swap.h"

void    swap(t_list *a)
{
    int tmp;

    tmp = a->head->content;
    a->head->content = a->head->next->content;
    a->head->next->content = tmp;
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
    node->prev = a->tail;
    node->next = a->head;
    a->tail->next = node;
    a->head->prev = node;
    a->tail = node;
    a->size++;
}

void    reverse_rotate(t_list *a)
{
    a->head = a->tail;
    a->tail = a->tail->prev;
}

void    rotate(t_list *a)
{
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