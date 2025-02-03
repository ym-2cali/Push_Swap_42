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

void    sort_5(t_list *stack)
{
    t_list  *tmp;

    tmp = stack;
    if (stack->tail->content < stack->tail->prev->content && stack->tail->content < stack->head->content)
    {
        while (tmp->tail != tmp->head)
        {
            if (tmp->tail->content > stack->tail->content)
                swap(stack);
            tmp->tail = tmp->tail->prev;
        }
    }

}
   
// 5 3 10 55 4
int main(int ac, char **av)
{
    (void)ac;

    t_list	stack;
	ft_bzero(&stack, sizeof(t_list));
    // parse(av, &stack);// 159 
    if (ac > 1)
    {
        parse(av, &stack);// 159 // 15 51
        if (ac == 3)
            sort_2(&stack);
        else if (ac == 4)
            sort_3(&stack);
        else if (ac == 6)
            sort_5(&stack);
        clear_stack(&stack);
    }
    return (0);
}