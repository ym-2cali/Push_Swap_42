#include "../inc/push_swap.h"

void    swap(t_list *a)
{
    t_node  *tmp;

    tmp = malloc(sizeof(t_node));
    if (!tmp)
        return ;
    tmp->content = a->tail->content;
    a->tail->content = a->tail->prev->content;
    a->tail->prev->content = tmp->content;
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

void    rotate(t_list *a)
{
    t_node  *tmp;
    int     value;

    tmp = malloc(sizeof(t_node));
    if (!tmp)
        return ;
    tmp = a->head;
    value = a->head->content;
    while (tmp != a->tail)
    {
        tmp->content = tmp->next->content;
        tmp = tmp->next;
    }
    a->tail->content = value; 
}

void    rotate_rotate(t_list *a, t_list *b)
{
    rotate(a);
    rotate(b);
}

void    reverse_rotate(t_list *a)
{
    t_node  *tmp;
    int     value;

    tmp = malloc(sizeof(t_node));
    if (!tmp)
        return ;
    tmp = a->tail;
    value = a->tail->content;
    while (tmp != a->head)
    {
        tmp->content = tmp->prev->content;
        tmp = tmp->prev;
    }
    a->head->content = value; 
}

void    reverse_rotate_rotate(t_list *a, t_list *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}