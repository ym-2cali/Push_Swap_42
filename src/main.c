#include "../inc/push_swap.h"

int main(int ac, char **av)
{
    int i = 1;
    char *str = av[i];
    char **arr;
    i++;
    if (ac > 1)
    {
        while (av[i])
        {
            str =  str_join(str,av[i]);
            i++;
        }
        arr = ft_split(str, ' ');
        printf("valid input : [%d]\n", valid_input(arr));
        i = 0;
        while (arr[i])
        {
            printf("%s\n", arr[i]);
            i++;
        }
    }
    return (0);
}