#include "../inc/push_swap.h"

void ft()
{
    system("leaks push_swap");
}

void    sort_2(t_list *stack)
{
    if (stack->tail->content < stack->head->content)
    {
        swap(stack);
        print_stack(stack);
        write(1, "sa\n", 3);
    }
    else
    {
        print_stack(stack);
        write(1, "Sorted\n", 8);
    }    
}

void    sort_3(t_list *stack)
{
        if (stack->tail->content < stack->tail->prev->content && stack->tail->content > stack->head->content)
        {
            swap(stack);// 195 g
            print_stack(stack);
            write(1, "sa\n", 3);
        }
        else if (stack->tail->content > stack->head->content && stack->head->content > stack->tail->prev->content)
        {
            swap(stack);// 519 g
            rotate(stack);
            print_stack(stack);
            write(1, "sa\nra\n", 7);
        }
        else if (stack->tail->content < stack->head->content && stack->tail->content > stack->tail->prev->content)
        {
            reverse_rotate(stack);// 9 1 5 g
            print_stack(stack);
            printf("stack->head = [%d]\n", stack->head->content);
            write(1, "rra\n", 4);
        }
        else if (stack->tail->content < stack->head->content && stack->tail->content < stack->tail->prev->content && stack->tail->prev->content < stack->head->content)
        {
            swap(stack);
            reverse_rotate(stack);// 9 5 1 g
            print_stack(stack);
            printf("stack->head = [%d]\n", stack->head->content);
            write(1, "sa\nrra\n", 7);
        }
        else if (stack->tail->content < stack->head->content && stack->tail->content < stack->tail->prev->content && stack->tail->prev->content > stack->head->content)
        {
            rotate(stack);// 5 9 1 g 
            print_stack(stack);
            write(1, "ra\n", 4);
        }
        else
        {
            print_stack(stack);
            write(1, "Sorted\n", 7);
        }
}

int back_or_front(t_list *stack)
{
    int     len;

    len = (stack->size / 2) - 1;
    if (stack->head->index < len)
        return (0);
    return (1);
}

int if_sorted(t_list *stack)
{
    t_node *tmp;
    int     i;

    tmp = stack->head;
    i = 1;
    while (tmp != stack->tail)
    {
        if (i > tmp->index)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    sort_5(t_list *stack)
{
    int content;
    t_list  stack_b;

    if (if_sorted(stack))
        return ;
    while (stack->tail->index != 1)
        rotate(stack);
    content = pop(stack);
    push(&stack_b, content);
    while (stack->tail->index != 2)
        rotate(stack);
    content = pop(stack);
    push(&stack_b, content);
    sort_3(stack);
    content = pop(&stack_b);
    push(stack, content);
    content = pop(&stack_b);
    push(stack, content);
    print_stack(stack);
}

// 5 3 10 55 4
int main(int ac, char **av)
{
    t_list	stack;
	ft_bzero(&stack, sizeof(t_list));
    // parse(av, &stack);// 159 
    if (ac < 1)
        return (1);
    parse(av, &stack);// 159 // 15 51
    if (ac == 3)
        sort_2(&stack);
    else if (ac == 4)
        sort_3(&stack);
    else if (ac == 6)
        sort_5(&stack);
    clear_stack(&stack);
    return (0);
}