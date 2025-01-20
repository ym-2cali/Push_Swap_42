#include "../inc/push_swap.h"

void    clear_stack(t_list *stack)
{
    t_list  *tmp;

    if (!stack)
        return ;
    while (stack->head != stack->tail && stack->head)
    {
        tmp = stack;
        stack->head = stack->head->next;
        if (tmp)
        {
            free(tmp);
            tmp = NULL;
        }
    }
    if (stack->head)
    {
        free(stack->head);
        stack->head = NULL;
    }
}

t_node  *create_node(int *content)
{
    t_node  *node;

    if (!content)
        return (NULL);
    node = malloc(sizeof(t_node));
    if (!node)
        return (free(content), content = NULL, NULL);
    node->content = *content;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void    fill_stack(t_list *stack, t_node *node)
{
    if (!stack || !node)
        return ;
    node->prev = stack->tail;
    node->next = stack->head;
    stack->tail->next = node;
    stack->head->prev = node;
    stack->size++;
    stack->tail = node;
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
    // int n = 19;

    pop(x);
    while (x->head != x->tail && x->head)
    {
        printf("%d\n", x->head->content);
        x->head = x->head->next;
    }
    printf("%d\n", x->head->content);
}