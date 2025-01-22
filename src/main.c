#include "../inc/push_swap.h"

// int main(int ac, char **av)
// {
//     t_list  a;
//     t_list  b;

//     bzero(&a, sizeof(t_list));
//     bzero(&b, sizeof(t_list));
//     parsing(ac, av, &a);
//     // sort(&a, &b);
//     clear_stack(&a);
//     clear_stack(&b);
//     return (0);
// }
int main(int ac, char **av)
{
    int     i = 1;
    t_list  *stack;

    stack = NULL;
    char    **arr;
    char    *str = av[i];

    while (i < ac)
    {

        str = str_join(str, av[i]);
        i++ ;
    } 
    arr = ft_split(str, ' ');
    int j= 0;
    while (arr[j])
    {
        printf("[%s]\n", arr[j++]);
        /* code */
    }
    
    stack = parse(arr);
        puts("here");
    printf("%d\n", stack->head->content);
    stack->head = stack->head->next;
    while (stack->head != stack->tail)
    {
        printf("%d\n", stack->head->content);
        stack->head = stack->head->next;
    }
    printf("%d\n", stack->tail->content);
    return (0);
}