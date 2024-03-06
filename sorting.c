/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:26:43 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/05 16:27:09 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*cheapest(t_list *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a)
	{
		if (stack_a->cheapest)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

void	rotate(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while ((*stack_b) != cheapest_node->target_node && (*stack_a) != cheapest_node)
		rotaterotate(stack_a, stack_b);
	curent_s_index(*stack_a);
	curent_s_index(*stack_b);
}

void	reverse_rotation(t_list **stack_a, t_list **stack_b,
		t_list *cheapest_node)
{
	while ((*stack_b) != cheapest_node->target_node && (*stack_a) != cheapest_node)
		reverse_rotaterotate(stack_a, stack_b);
	curent_s_index(*stack_a);
	curent_s_index(*stack_b);
}

void	check_push(t_list **stack, t_list *cheap_node, int num)
{
	if (num == 4)
	{
		if (cheap_node->abovem_med)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
	else if (num == 8)
	{
		if (cheap_node->abovem_med)
			rotate_b(stack);
		else
			reverse_rotate_b(stack);
	}
}

void	move_na_to_nb(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = cheapest(*stack_a);
	if (cheapest_node->abovem_med && cheapest_node->target_node->abovem_med)
		rotate(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->abovem_med)
		&& !(cheapest_node->target_node->abovem_med))
		reverse_rotation(stack_a, stack_b, cheapest_node);
	check_push(stack_a, cheapest_node, 4);
	check_push(stack_b, cheapest_node, 8);
	push_b(stack_b, stack_a);
}
