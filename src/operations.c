#include "../inc/push_swap.h"

void    swap(t_list *a)
{
    t_node  *tmp;

    tmp = malloc(sizeof(t_node));
    tmp->content = a->tail->content;
    a->tail->content = a->tail->prev->content;
    a->tail->prev->content = tmp->content;
}


int main()
{


    int i = 0;
    t_list  *a = malloc(sizeof(t_list));
    t_node  *b = malloc(sizeof(t_node));
    t_node  *c = malloc(sizeof(t_node));
    t_node  *d = malloc(sizeof(t_node));
    t_node  *e = malloc(sizeof(t_node));

    b->next = c;
    b->prev = e;
    c->next = d;
    c->prev = b;
    d->next = e;
    d->prev = c;
    e->next = b;
    e->prev = d;
    b->content = 10;
    c->content = 20;
    d->content = 1;
    e->content = 9;
    a->head = b;
    a->tail = e;
    a->size = 4;
    swap(a);
    while (i < a->size)
    {
        printf("%d\n", a->head->content);
        a->head = a->head->next;
        i++;
    }
}