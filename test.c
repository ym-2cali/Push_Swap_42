#include "inc/push_swap.h"

void    sort_5(t_list *stack)
{
    int content;
    t_list  stack_b;

    if (if_sorted(stack))
        return ;
    while (stack->tail->index != 1)
        rotate(stack);
    content = pop(stack);
    push(&stack_b, content);
    while (stack->tail->index != 2)
        rotate(stack);
    content = pop(stack);
    push(&stack_b, content);
    sort_3(stack);
    content = pop(&stack_b);
    push(stack, content);
    content = pop(&stack_b);
    push(stack, content);
    print_stack(stack);
}

int main()
{
    t_list stack;
    t_node  *n1 = create_node(15);
    t_node  *n2 = create_node(1);
    t_node  *n3 = create_node(6);
    t_node  *n4 = create_node(3);

    n1->next = n2;
    n1->prev = n4;
    n2->next = n3;
    n2->prev = n1;
    n3->next = n4;
    n3->prev = n2;
    n4->next = n1;
    n4->prev = n3;
    (&stack)->size = 4;
    stack.head = n1;
    stack.tail = n4;
    sort_index(&stack);
    print_stack(&stack);
    printf("\n");
}