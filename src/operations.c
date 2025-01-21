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
