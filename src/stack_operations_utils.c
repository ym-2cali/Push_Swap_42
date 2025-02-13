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
    // fprintf(stderr, "DEBUG: fill-stack entry.\n");
    if (!stack || !node)
        return ;
    // fprintf(stderr, "DEBUG: fill-stack after first if.\n");
    if (stack->size == 0)
    {
        stack->head = node;
        stack->tail = node;
        node->next = node;
        node->prev = node;
        stack->size++;
        // fprintf(stderr, "DEBUG: fill-stack  inside second if.\n");
        return ;
    }
    // fprintf(stderr, "DEBUG: fill-stack  inside second if.\n");
    node->prev = stack->tail;
    node->next = stack->head;
    stack->tail->next = node;
    stack->head->prev = node;
    stack->size++;
    stack->tail = node;        
    // fprintf(stderr, "DEBUG: fill-stack after after second if.\n");
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
    if (stack->size > 1)
    {
        tmp = tmp->next;
        while (tmp != stack->tail)
        {
            tmp->index = i++;
            tmp = tmp->next;
        }
        tmp->index = i++;
    }
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
            if (tmp->content > temp->content && tmp->index < temp->index)
            {
                tempo = tmp->index;
                tmp->index = temp->index;
                temp->index = tempo;
            }
            temp = temp->next;
        }
        tempo = 0;
        if (tmp->content > temp->content && tmp->index < temp->index)
        {
            tempo = tmp->index;
            tmp->index = temp->index;
            temp->index = tempo;
        }
        tmp = tmp->next;
    }
    tempo = 0;
    if (stack->tail->content < stack->tail->prev->content && stack->tail->index > stack->tail->prev->index)
    {
        tempo = stack->tail->index;
        stack->tail->index = stack->tail->prev->index;
        stack->tail->prev->index = tempo;
    }
    tmp = stack->head;
    while (tmp != stack->tail)
    {
        tempo = 0;
        if (tmp->content < stack->tail->content && tmp->index > stack->tail->index)
        {
            tempo = stack->tail->index;
            stack->tail->index = tmp->index;
            tmp->index = tempo;
        }
        tmp = tmp->next;
    }
}