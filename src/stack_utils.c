#include "../inc/push_swap.h"

void    clear_stack(t_list *stack)
{
    t_list  *tmp;

    if (!stack)
        return ;
    while (stack->head != stack->tail || !(stack->head))
    {
        tmp = stack;
        if (tmp)
            free(tmp);
        stack->head = stack->head->next;
    }
    free(tmp->tail);
}

int main()
{
    t_list  *x = malloc(sizeof(t_list));
    t_node  *a = malloc(sizeof(t_node));
    t_node  *b = malloc(sizeof(t_node));
    t_node  *c = malloc(sizeof(t_node));
    
    x->head = a;
    x->tail = c;
    x->size = 3;
    a->next = b;
    a->prev = c;
    a->content = 1;
    b->next = c;
    b->prev = a;
    b->content = 9;
    c->next = a;
    c->prev = b;
    c->content = 3;

    clear_stack(x);
    while (x->head != x->tail)
    {
        printf("%d\n", x->head->content);
        x->head = x->head->next;
    }
    printf("%d\n", x->tail->content);
}