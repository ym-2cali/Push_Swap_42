#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct s_node {
    int content;
    struct s_node    *next;
    struct s_node    *prev;
} t_node;

typedef struct s_list {
    int size;
    t_node  *head;
    t_node *tail;

}   t_list;

#endif
