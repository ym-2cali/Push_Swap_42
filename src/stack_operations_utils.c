#include "../inc/push_swap.h"

void    clear_stack(t_list *stack)
{
    t_node *temp;
    while(stack->head != stack ->tail)
    {
        temp = stack->head;
        stack->head = stack->head->next;
        free(temp);
    }
    free(stack->head);
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

void    les_indices(t_list *stack)
{
    t_node  *tmp;
    int     i;

    if (!stack)
        return ;
    tmp = stack->head;
    tmp->index = 0;
    i = 1;
    tmp = tmp->next;
    while (tmp != stack->tail)
    {
        tmp->index = i++;
        tmp = tmp->next;
    }
    tmp->index = i++;
}

void    sort_index(t_list *stack)
{
    t_node  *tmp;
    t_node  *temp;
    int     tempo;

    tmp = stack->head;
    while (tmp != stack->tail)
    {
        temp = tmp->next;
        while (temp != stack->tail)
        {
            tempo = 0;
            if (tmp->content > temp->content)
            {
                tempo = tmp->index;
                tmp->index = temp->index;
                temp->index = tempo;
            }
            temp = temp->next;
        }
        if (tmp->content > temp->content)
        {
                tempo = tmp->index;
                tmp->index = temp->index;
                temp->index = tempo;
        }
        tmp = tmp->next;
    }
    if (stack->tail->content < stack->tail->prev->content)
    {
        tempo = tmp->index;
        tmp->index = temp->index;
        temp->index = tempo;
    }
}