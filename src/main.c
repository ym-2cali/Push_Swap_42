#include "../inc/push_swap.h"

void ft()
{
    system("leaks push_swap");
}

// static void    print_stack(t_list *stack)
// {
//     while (stack->head != stack->tail)
//     {
//         printf("%d\n", stack->head->content);
//         stack->head = stack->head->next;
//     }
//     printf("%d\n", stack->tail->content);
// }

int main(int ac, char **av)
{
    (void)ac;
    // atexit(ft);
    // int i = 1;
    // char *str = av[i];
    // char **arr;
    // i++;
    t_list	stack;
	bzero(&stack, sizeof(t_list));
    // int     size;
    // t_node  *tmp;

    // if (ac > 1)
    // {
    //     while (av[i])
    //     {
    //         str =  str_join(str,av[i]);
    //         i++;
    //     }
    //     arr = ft_split(str, ' ');
    //     printf("valid input : [%d]\n", valid_input(arr));
    //     // i = 0;
    //     // while (arr[i])
    //     // {
    //     //     printf("%s\n", arr[i]);
    //     //     i++;
    //     // }

    //     size = tab_size(arr);
    //     stack = build_stack(tab(arr),size);
    //     tmp = stack->head;
    //     // swap(stack);
    //     reverse_rotate(stack);
    //     while (tmp && tmp != stack->tail)
    //     {
    //         printf("%d\n", tmp->content);
    //         tmp = tmp->next;
    //     }
    //     printf("%d\n", tmp->content);
    //     printf("stack head is [%d]\n", stack->head->content);
    // }
    if (ac > 1)
    {
        parse(av, &stack);// 159      951
        if (stack.tail->content < stack.tail->prev->content && stack.tail->content > stack.head->content)
        {
            swap(&stack);// 195
            while (stack.head != stack.tail)
            {
                printf("%d\n", stack.head->content);
                stack.head = stack.head->next;
            }
            printf("%d\n", stack.tail->content);
            write(1, "sa\n", 3);
        }
        else if (stack.tail->content > stack.tail->prev->content && stack.tail->content > stack.head->content)
        {
            swap(&stack);// 519
            rotate(&stack);
            while (stack.head != stack.tail)
            {
                printf("%d\n", stack.head->content);
                stack.head = stack.head->next;
            }
            printf("%d\n", stack.tail->content);
            write(1, "sa\nra\n", 7);
        }
        else if (stack.tail->content < stack.head->content && stack.tail->content > stack.tail->prev->content)
        {
            reverse_rotate(&stack);// 9 1 5
            while (stack.head != stack.tail)
            {
                printf("%d\n", stack.head->content);
                stack.head = stack.head->next;
            }
            printf("%d\n", stack.tail->content);
            printf("stack->head = [%d]\n", stack.head->content);
            write(1, "rra\n", 4);
        }
        else if (stack.tail->content < stack.head->content && stack.tail->content < stack.tail->prev->content)
        {
            swap(&stack);
            reverse_rotate(&stack);// 9 1 5
            while (stack.head != stack.tail)
            {
                printf("%d\n", stack.head->content);
                stack.head = stack.head->next;
            }
            printf("%d\n", stack.tail->content);
            printf("stack->head = [%d]\n", stack.head->content);
            write(1, "sa\nrra\n", 7);
        }
        else
        {
            rotate(&stack);// 591
            while (stack.head != stack.tail)
            {
                printf("%d\n", stack.head->content);
                stack.head = stack.head->next;
            }
            printf("%d\n", stack.tail->content);
            write(1, "ra\n", 4);
        }
	    clear_stack(&stack);// 
    }

	// if (!stack)
	// {
	// 	write(2, "Error\n", 6);
	// 	exit(0);
	// }
    // printf("--%d--%d--\n", stack->head->content, stack->tail->content);
    return (0);
}