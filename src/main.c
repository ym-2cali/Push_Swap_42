#include "../inc/push_swap.h"

void ft()
{
    system("leaks push_swap");
}

void    sort_2(t_list *stack)
{
    if (stack->tail->content < stack->head->content)
    {
        swap(stack, 'a');
        print_stack(stack);
        // write(1, "sa\n", 3);
    }
    else
    {
        print_stack(stack);
        write(1, "Sorted\n", 8);
    }    
}

int   sort_3(t_list *stack)// 159 / / /    
{
    int counter;

    counter = 0;
        if (stack->tail->content < stack->tail->prev->content && stack->tail->content > stack->head->content)
        {// 195 
            swap(stack, 'a');// 195 
            rotate(stack, 'a');
            // print_stack(stack);
            // counter = 2;
            write(1, "sa\nra\n", 6);
        }
        else if (stack->head->content > stack->head->next->content && stack->head->content < stack->tail->content)
        {
            swap(stack, 'a');// 519 
            // counter = 1;
            // print_stack(stack);
            write(1, "sa\n", 3);
        }
        else if (stack->head->content < stack->head->next->content && stack->head->content > stack->tail->content)
        {
            reverse_rotate(stack, 'a');//  591 
            // print_stack(stack);
            // printf("stack->head = [%d]\n", stack->head->content);
            // counter = 1;
            write(1, "rra\n", 4);
        }
        else if (stack->tail->content < stack->head->content && stack->tail->content > stack->tail->prev->content)
        {
            rotate(stack, 'a');//915g
            // print_stack(stack);
            // printf("stack->head = [%d]\n", stack->head->content);
            // counter = 1;
            write(1, "ra\n", 3);
        }
        else if (stack->tail->prev->content < stack->head->content && stack->tail->prev->content > stack->tail->content)
        {
            swap(stack, 'a');
            reverse_rotate(stack, 'a');// 951
            // print_stack(stack);
            // counter = 1;
            write(1, "sa\nrra\n", 8);
        }
        else
        {
            // print_stack(stack);
            write(1, "Sorted\n", 7);
        }
    print_stack(stack);
    return (0);
}

int back_or_front(t_list *stack, int ind)
{
    int     len;
    int     i;
    t_node  *tmp;

    tmp = stack->head;
    i = 0;
    while (tmp->index != ind)
    {
        i++;           
        tmp = tmp->next;
    }
    len = (stack->size - 1) / 2;
    if (i < len)
        return (0);
    return (1);
}

int if_sorted(t_list *stack)
{
    t_node *tmp;
    int     i;

    tmp = stack->head;
    i = 1;
    while (tmp != stack->tail)
    {
        if (i > tmp->index)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

void    sort_5(t_list *stack)
{
    int content;
    t_list  *stack_b;

    if (if_sorted(stack))
        return ;
    stack_b = malloc(sizeof(t_list));
    if (!stack_b)
        return ;
    stack_b->size = 0;
    int ind = stack->size - 1;
    while (stack->tail->index != (stack->size - 1))
    {
        if (back_or_front(stack, ind))
        {
            reverse_rotate(stack, 'a');
            write(1, "rra\n", 4);
        }
        else if (!back_or_front(stack, ind))
        {
            rotate(stack, 'a');
            write(1, "ra\n", 3);
        }

    }
    // print_stack(stack);
    // printf("-------------");
    // sleep(2);
    content = pop(stack);
        // printf("content = %d\n", content);
    push(stack_b, content);
    ind = stack->size - 1;
    while (stack->tail->index != (stack->size - 1))
    {
        
        if (back_or_front(stack, ind))
        {
            reverse_rotate(stack, 'a');
            write(1, "rra\n", 3);
        }
        else if (!back_or_front(stack, ind))
        {
            rotate(stack, 'a');
            write(1, "ra\n", 4);
        }
        // sort_index(stack);
    }
    content = pop(stack);
    push(stack_b, content);
    sort_3(stack);
    content = pop(stack_b);
    push(stack, content);
    content = pop(stack_b);
    push(stack, content);
    print_stack(stack);
    // printf("-------------");
    // printf("[[%d]]", stack->size);
    // clear_stack(stack_b);
}

void    fill_head_stack(t_list *stack, t_node *node)
{
    // fprintf(stderr, "DEBUG: fill-stack entry.\n");
    if (!stack || !node)
        return ;
    // fprintf(stderr, "DEBUG: fill-stack after first if.\n");
    if (stack->size == 0)
    {
        stack->head = node;
        stack->tail = node;
        node->next = node;
        node->prev = node;
        stack->size++;
        // fprintf(stderr, "DEBUG: fill-stack  inside second if.\n");
        return ;
    }
    // fprintf(stderr, "DEBUG: fill-stack  inside second if.\n");
    node->prev = stack->tail;
    node->next = stack->head;
    stack->tail->next = node;
    stack->head->prev = node;
    stack->size++;
    stack->head = node;        
    // fprintf(stderr, "DEBUG: fill-stack after after second if.\n");
}
void    push_to_head(t_list *stack, int content, char c)
{
    if (!stack)
        return ;
    fill_head_stack(stack, create_node(content));
    if(c == 'a')
        write(1,"pa\n",3);
    if(c == 'b')
        write(1,"pb\n",3);
}
// 5 3 10 55 4
int main(int ac, char **av)
{
    t_list	stack;
    t_list  stack_b;

	ft_bzero(&stack, sizeof(t_list));
	ft_bzero(&stack_b, sizeof(t_list));
    // parse(av, &stack);// 159 
    if (ac < 1)
        return (1);

    parse(av, &stack);// 159 // 15 51
    // print_stack(&stack);
    // if (ac == 3)
    //     sort_2(&stack);
    // else if (ac == 4)
    //     sort_3(&stack);
    // else if (ac == 6)
    //     sort_5(&stack);
    // else id (ac > 6)
    // {
    les_indices(&stack);
    sort_index(&stack);
    // }
    //  push(&stack_b, pop(&stack), 'a');
    //  push(&stack_b, pop(&stack), 'a');
    //  push(&stack_b, pop(&stack), 'a');
    //  push(&stack_b, pop(&stack));
    // swap(&stack);
    
    // swap(&stack);
    // printf("%d\n" ,stack_b.tail->content);
    // printf("%d\n" ,stack_b.head->content);
    // reverse_rotate(&stack_b);
    // print_stack(&stack);
    // printf("here\n");
    sort_algo(&stack, &stack_b);
    // les_indices(&stack_b);
    // sort_index(&stack_b);
    // printf("-------------------\n");
    // print_stack(&stack_b);
    // printf("----------[%d]---------\n", stack_b.size);
    algo(&stack, &stack_b);
   // printf("-------------------\n");
    //print_stack(&stack);
    // printf("%d\n%d\n%d\n", stack_b.head->content, stack_b.head->next->content, stack_b.tail->content);
    //printf("------------------\n");
    // print_rstack(&stack);
    // printf("%d\n%d\n", stack_b.tail->content, stack_b.tail->index);
    // printf("%d\n", stack_b.size);
    //clear_stack(&stack);
    return (0);
}