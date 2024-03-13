/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:09:40 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/13 15:58:33 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_analytics(t_list *stack_a, t_list *stack_b)
{
	int	length_a;
	int	length_b;

	length_a = len_stack(&stack_a);
	length_b = len_stack(&stack_b);
	while (stack_a)
	{
		stack_a->cost = stack_a->index;
		if (!(stack_a->abovem_med))
			stack_a->cost = length_a - (stack_a->index);
		if (stack_a->target_node->abovem_med)
			stack_a->cost += stack_a->target_node->index;
		else
			stack_a->cost += length_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	curent_s_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = len_stack(&stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->abovem_med = true;
		else
			stack->abovem_med = false;
		stack = stack->next;
		++i;
	}
}

void	set_targ_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*targ_node;
	long	min_index;

	while (stack_a)
	{
		min_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->data < stack_a->data && current_b->data > min_index)
			{
				min_index = current_b->data;
				targ_node = current_b;
			}
			current_b = current_b->next;
		}
		if (min_index == LONG_MIN)
			stack_a->target_node = findmax(&stack_b);
		else
			stack_a->target_node = targ_node;
		stack_a = stack_a->next;
	}
}

void	cheapest_node(t_list *stack_a)
{
	int		max;
	t_list	*cheapest_node;

	if (!stack_a)
		return ;
	max = INT_MAX;
	while (stack_a)
	{
		if (stack_a->cost < max)
		{
			max = stack_a->cost;
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_list *stack_a, t_list *stack_b)
{
	curent_s_index(stack_a);
	curent_s_index(stack_b);
	set_targ_node(stack_a, stack_b);
	cost_analytics(stack_a, stack_b);
	cheapest_node(stack_a);
}
