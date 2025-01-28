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
    // t_list *stack;
    // int     size;

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
    //     while (stack->head && stack->head != stack->tail)
    //     {
    //         printf("%d\n", stack->head->content);
    //         stack->head = stack->head->next;
    //     }
    //     printf("%d\n", stack->tail->content);
    // }
    parse(av);
    return (0);
}