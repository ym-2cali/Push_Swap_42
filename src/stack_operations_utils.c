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
    t_node  *start;
    t_node  *start_next;
    int     tmp;

    start = stack->head;
    tmp = 0;
    while (start != stack->tail)
    {
        start_next = start->next;
        while (start_next != stack->head)
        {
            if ((start->content > start_next->content && start->index < start_next->index) || (start->content < start_next->content && start->index > start_next->index))
            {
                tmp = start->index;
                start->index = start_next->index;
                start_next->index = tmp;
            }
            start_next = start_next->next;
        }
        // if ((start->content > stack->tail->content && start->index < stack->tail->index) || (start->content > stack->tail->content && start->index < stack->tail->index))
        // {
        //     tmp = start->index;
        //     start->index = stack->tail->index;
        //     stack->tail->index = tmp;
        // }
        start = start->next;
    }
    start = stack->head;
    start_next = start->next;
    while (start_next != start)
    {
        if ((start->content > start_next->content && start->index < start_next->index) 
            || (start->content < start_next->content && start->index > start_next->index))
        {
            tmp = start->index;
            start->index = start_next->index;
            start_next->index = tmp;
        }
        start_next = start_next->next;
    }

}