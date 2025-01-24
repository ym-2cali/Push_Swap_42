#include "../inc/push_swap.h"

int tab_size(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}

int *tab(char **arr)
{
    int *tab;
    int i;
    int content;

    tab = malloc(sizeof(int *) * tab_size(arr));
    if (!tab)
        return (NULL);
    i = 0;
    if (valid_input(arr))
    {
        while (arr[i])
        {
            content = ft_atoi(arr[i]);
            tab[i] = content;
            i++;
        }
    }
    return (tab);
}


    t_list  *parse(int *tab, int size)
    {
        t_node  *node;
        t_list  *stack;
        int     i;

        if (!tab)
            return (NULL);
        stack = malloc(sizeof(t_list));
        if (!stack)
            return (NULL);
        i = 0;
        while(i < size)
        {
            node = create_node(tab[i]);
            fill_stack(stack, node);
            i++;
        }
        return (stack);
    }