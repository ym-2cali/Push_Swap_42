#include "../inc/push_swap.h"

void ft()
{
    system("leaks push_swap");
}

void    sort_2(t_list *stack) //  | 
{
    if (sorted(stack)) // 1 9
        return ;
    if (stack->tail->content < stack->head->content) // 9 1
        swap(stack, 'a');
}

void   sort_3(t_list *stack) 
{
    if (sorted(stack)) //  1 5 9
        return ;
    else if (stack->tail->content < stack->tail->prev->content && stack->tail->content > stack->head->content) // 1 9 5
    {
        reverse_rotate(stack, 'a');
        swap(stack, 'a');
    }
    else if (stack->head->content > stack->head->next->content && stack->head->content < stack->tail->content) // 5 1 9
        swap(stack, 'a');
    else if (stack->head->content < stack->head->next->content && stack->head->content > stack->tail->content) // 5 9 1
        reverse_rotate(stack, 'a');
    else if (stack->tail->content < stack->head->content && stack->tail->content > stack->tail->prev->content) // 9 1 5
        rotate(stack, 'a');
    else if (stack->tail->prev->content < stack->head->content && stack->tail->prev->content > stack->tail->content) // 9 5 1 
    {
        rotate(stack, 'a');
        swap(stack, 'a');
    }
}

int back_or_front(t_list *stack, int ind)
{
    int     len;
    int     i;
    t_node  *tmp;

    tmp = stack->head;
    i = 0;
    while (tmp->index != ind)
    {
        i++;           
        tmp = tmp->next;
    }
    len = (stack->size - 1) / 2;
    if (i < len)
        return (0);
    return (1);
}

void    sort_5(t_list *stack, t_list *stack_b)
{
    if (sorted(stack))
        return ;
    sort_index(stack);
    while (stack->head->index != 0)
    {
        if (!back_or_front(stack, 0))
            rotate(stack, 'a');
        else
            reverse_rotate(stack, 'a');
    }
    if (stack->head->index == 0)
        push_to_head(stack_b, pop(stack), 'b');
    while (stack->head->index != 1)
    {
        if (!back_or_front(stack, 1))
            rotate(stack, 'a');
        else
            reverse_rotate(stack, 'a');
    }
    if (stack->head->index == 1)
        push_to_head(stack_b, pop(stack), 'b');
    sort_3(stack);
    push_to_head(stack, pop(stack_b), 'a');    
    push_to_head(stack, pop(stack_b), 'a');    
    // print_stack(stack);
    // clear_stack(stack_b);
}

void    fill_head_stack(t_list *stack, t_node *node)
{
    if (!stack || !node)
        return ;
    if (stack->size == 0)
    {
        stack->head = node;
        stack->tail = node;
        node->next = node;
        node->prev = node;
        stack->size++;
        return ;
    }
    node->prev = stack->tail;
    node->next = stack->head;
    stack->tail->next = node;
    stack->head->prev = node;
    stack->size++;
    stack->head = node;        
}
void    push_to_head(t_list *stack, int content, char c)
{
    if (!stack)
        return ;
    fill_head_stack(stack, create_node(content));
    if(c == 'a')
        write(1,"pa\n",3);
    if(c == 'b')
        write(1,"pb\n",3);
}

int main(int ac, char **av)
{
    t_list	stack;
    t_list  stack_b;

	ft_bzero(&stack, sizeof(t_list));
	ft_bzero(&stack_b, sizeof(t_list));
    if (ac < 1)
        return (1);

    parse(av, &stack);
    if (sorted(&stack))
        exit(0);
    // les_indices(&stack);
    sort_index(&stack);
    // printf("-----------------------\n");
    // print_stack(&stack);
    // printf("-----------------------\n");
    if (stack.size == 2)
        sort_2(&stack);
    else if (stack.size == 3)
        sort_3(&stack);
    else if (stack.size == 5)
        sort_5(&stack, &stack_b);
    else
    {
        sort_algo(&stack, &stack_b);
        algo(&stack, &stack_b);
    }
    clear_stack(&stack);
    return (0);
}