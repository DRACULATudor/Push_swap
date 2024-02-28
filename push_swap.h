/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:17 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/22 15:59:15 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H "push_swap.h"


#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <printf.h>
#include "printf/ft_printf.h"
#include <limits.h>

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
int	ft_checkdup(char **argv);
int check_args(int argc, char *argv[]);
t_list	*ft_lstnew(int content);
char	**ft_split(const char *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	reverse_rotate_b(t_list **stack_b);
void	rotate_b(t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a(t_list **stack_a);
void	push_a(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	reverse_rotate_a(t_list **stack_a);
void 	add_to_Sa(t_list **stack,char **str);
void	free_split_argv(char **str);
int	lenofnums(char **arr);

#endif