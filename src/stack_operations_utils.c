#include "../inc/push_swap.h"

void    clear_stack(t_list *stack)
{
    while (stack->size)
        pop(stack);
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

// int main()
// {
//     t_list  x;

//     bzero(&x, sizeof(t_list));
//     push(&x, 3);
//     push(&x, 4);
//     push(&x, 5);
//     push(&x, 6);
//     push(&x, 7);
//     push(&x, 8);

//     t_node  *tmp;
//     tmp = x.tail;
//     printf("------------------------------\n");
//     while (tmp != x.head && tmp)
//     {
//         printf("%d\n", tmp->content);
//         tmp = tmp->prev;
//     }
//     printf("%d\n", tmp->content);
//     printf("------------------------------\n");
//     printf("%d\n", pop(&x));
//     tmp = x.tail;
//     printf("------------------------------\n");
//     while (tmp != x.head && tmp)
//     {
//         printf("%d\n", tmp->content);
//         tmp = tmp->prev;
//     }
//     printf("%d\n", tmp->content);
//     printf("------------------------------\n");
//     clear_stack(&x);
// }