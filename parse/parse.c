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

    tab = malloc(sizeof(int) * tab_size(arr));
    if (!tab)
        return (NULL);
    i = 0;
	while (arr[i])
	{
		tab[i] = ft_atoi(arr[i]);
		i++;
	}
    return (tab);
}


void	build_stack(int *tab, int size, t_list *stack)
{
    int     i;

    i = 0;
    while(i < size)
		push(stack, tab[i++]);
}


void	parse(char **av, t_list *stack)
{
    int     i;
    char    **arr;
    char    *str;
    int     size;
	int		*bat;
    // t_node *tmp;
    i = 1;
    str = ft_strdup(av[i]); // ft_strdup(av[i]);
	if (!str)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
    i++;
    while (av[i])
    {
        str =  str_join(str, av[i]);
		if (!str)
			exit(0);
        i++;
    }
    arr = ft_split(str, ' ');
	free(str);
	if (!arr)
	{
		write(2, "Error\n", 6); 
		exit(0);
	}
    if (!valid_value(arr))
    {
        write(2, "Error\n", 6);
		ft_freearr(arr);
        exit(0);
    }
    size = tab_size(arr);
	bat = tab(arr);
	ft_freearr(arr);
	if (!bat)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	if (check_duplicate(bat, size))
	{
		write(2, "Error\n", 6);
		free(bat);
		exit(0);
	}
    build_stack(bat, size, stack);
	free(bat);
	if (stack->size != size)
	{
		write(2, "Error\n", 6);
		clear_stack(stack);
		exit(0);
	}
    // tmp = stack->head;
    // printf("%d\n", stack->size);
    // printf("[%d]\n[%d]\n[%d]\n", stack->head->content ,stack->head->prev->content,stack->head->prev->prev->content);
    les_indices(stack);
    // printf("----------\n");
    // fprintf(stderr, "here");
    sort_index(stack);
    // sleep(10);  
    // print_stack(stack);
    // printf("----------\n");
    // while (tmp && tmp != stack->tail)
    // {
    //     printf("%d\n", tmp->content);
    //     tmp = tmp->next;
    // }
    // printf("%d\n", stack->tail->content);
    // print_stack(stack);
}
void    print_rstack(t_list *stack)
{
    t_node  *tmp;

    tmp = stack->tail;
    // printf("%d\n", stack->tail->content);
    // printf("%d\n", stack->tail->prev->content);
    // printf("%d\n", stack->tail->next->content);
    // printf("%d\n", stack->head->next->content);
    while (tmp != stack->head)
    {
        printf("%d\n", tmp->content);
        tmp = tmp->prev;
    }
    printf("%d\n", tmp->content);
}
   