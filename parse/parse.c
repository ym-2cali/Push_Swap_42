#include "../inc/push_swap.h"

int valid_input(char **arr, char *)
{
    int i;
    if (!valid_value(str))
    {

        return (0);
    }    
    else{
        puts("here");
        i = check_duplicate(stack, valid_value(str));
    }
    return (i);
}

t_list  *parse(char **arr)
{
    t_list  *stack;
    int     i;

    i = 0;
    stack = NULL;
    while(arr[i++])
    {
        if (valid_input(stack, arr[i]))
        {

            puts("here");
            push(stack, valid_value(arr[i]));
        }
    }
    return (stack);
}