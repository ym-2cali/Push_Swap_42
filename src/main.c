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

    char *str = av[i];
    while (++i < ac)
    {
        str = str_join(str, av[i]);
    }
    printf("%s\n", str);
    return (0);
}