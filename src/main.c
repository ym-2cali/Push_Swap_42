#include "../inc/push_swap.h"

void ft()
{
    system("leaks push_swap");
}

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
    parse(av, &stack);
	clear_stack(&stack);
	// if (!stack)
	// {
	// 	write(2, "Error\n", 6);
	// 	exit(0);
	// }
    // printf("--%d--%d--\n", stack->head->content, stack->tail->content);
    return (0);
}