/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:07:50 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/13 15:58:03 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	targ_node_forb(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*targ_node;
	long	max_index;

	if (stack_b == NULL)
		return ;
	while (stack_b)
	{
		max_index = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->data > stack_b->data && current_a->data < max_index)
			{
				max_index = current_a->data;
				targ_node = current_a;
			}
			current_a = current_a->next;
		}
		if (max_index == LONG_MAX)
			stack_b->target_node = findmin(&stack_a);
		else
			stack_b->target_node = targ_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_forb(t_list *stack_a, t_list *stack_b)
{
	curent_s_index(stack_a);
	curent_s_index(stack_b);
	targ_node_forb(stack_a, stack_b);
}

void	move_back_sa(t_list **stack_a, t_list **stack_b)
{
	check_push(stack_a, (*stack_b)->target_node, 4);
	push_a(stack_a, stack_b);
}

void	min_check(t_list **stack_a)
{
	while ((*stack_a)->data != find_min(stack_a)->data)
	{
		if (find_min(stack_a)->abovem_med)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = len_stack(stack_a);
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (len_a-- > 3 && check_list_sorted(stack_a) == 0)
		push_b(stack_b, stack_a);
	if (len_a-- > 3 && check_list_sorted(stack_a) == 0)
		push_b(stack_b, stack_a);
	while (len_a-- > 3 && check_list_sorted(stack_a) == 0)
	{
		init_nodes(*stack_a, *stack_b);
		move_na_to_nb(stack_a, stack_b);
	}
	sort_smlen(stack_a);
	while (*stack_b)
	{
		init_nodes_forb(*stack_a, *stack_b);
		move_back_sa(stack_a, stack_b);
	}
	curent_s_index(*stack_a);
	min_check(stack_a);
}
