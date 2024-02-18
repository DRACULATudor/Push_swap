
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H "push_swap.h"


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "printf/ft_printf.h"

typedef struct s_list {
    
    int index;
    int data;
    int cost;
    struct s_list* next;
    struct s_list* prev;
    struct s_list* target_node;

}               t_list;

int	ft_check_num(char *str);
int	ft_atoi(const char *str);
int	ft_checkdup(int argc, char **argv);
int check_args(int argc, char *argv[]);
void    add_numbers_to_stack(char *str, t_list **stack);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif