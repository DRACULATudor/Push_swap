/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:17 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/11 12:45:17 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H "push_swap.h"

# include "printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				data;
	int				cost;
	bool			abovem_med;
	bool			cheapest;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*target_node;

}					t_list;

int					ft_check_num(char *str);
int					ft_atoi(const char *str);
int					ft_checkdup(char **argv);
int					check_args(int argc, char *argv[]);
t_list				*ft_lstnew(int content);
char				**ft_split(const char *s, char c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				reverse_rotate_b(t_list **stack_b);
void				rotate_b(t_list **stack_b);
void				push_b(t_list **stack_b, t_list **stack_a);
void				swap_b(t_list **stack_b);
void				swap_a(t_list **stack_a);
void				swapswap(t_list **stack_a, t_list **stack_b);
void				rotaterotate(t_list **stack_a, t_list **stack_b);
void				reverse_rotaterotate(t_list **stack_a, t_list **stack_b);
void				push_a(t_list **stack_a, t_list **stack_b);
void				rotate_a(t_list **stack_a);
void				reverse_rotate_a(t_list **stack_a);
void				add_to_sta(t_list **stack, char **str);
void				free_split_argv(char **str);
int					lenofnums(char **arr);
void				sort_smlen_helper(t_list **stack);
void				sort_smlen(t_list **stack);
int					check_list_sorted(t_list **stack);
void				move_max_to_b(t_list **stack_a, t_list **stack_b);
void				move_min_to_b(t_list **stack_a, t_list **stack_b);
t_list				*findmin(t_list **stack_a);
t_list				*findmax(t_list **stack_a);
int					len_stack(t_list **stack_a);
void				free_stack(t_list **stack);
void				init_nodes(t_list *stack_a, t_list *stack_b);
void				cheapest_node(t_list *stack_a);
void				set_targ_node(t_list *stack_a, t_list *stack_b);
void				curent_s_index(t_list *stack);
void				cost_analytics(t_list *stack_a, t_list *stack_b);
t_list				*cheapest(t_list *stack_a);
void				rotate(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node);
void				reverse_rotation(t_list **stack_a, t_list **stack_b,
						t_list *cheapest_node);
void				check_push(t_list **stack, t_list *cheap_node, int num);
void				move_na_to_nb(t_list **stack_a, t_list **stack_b);
void				free_errors(t_list **stack_a);
void				sort(t_list **stack_a, t_list **stack_b);
void				min_check(t_list **stack_a);
void				move_back_sa(t_list **stack_a, t_list **stack_b);
void				init_nodes_forb(t_list *stack_a, t_list *stack_b);
void				targ_node_forb(t_list *stack_a, t_list *stack_b);
t_list				*find_min(t_list **stack_a);
void				free_split_fail(char **arr);
int					validate_argc(int argc);

#endif