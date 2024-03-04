/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations4and5num.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:55:17 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/01 09:56:47 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*findmax(t_list **stack_a)
{
	t_list	*curr;
	t_list	*max_node;

	if (stack_a == NULL || *stack_a == NULL)
		return (NULL);
	curr = *stack_a;
	max_node = *stack_a;
	while (curr != NULL)
	{
		if (curr->data > max_node->data)
			max_node = curr;
		curr = curr->next;
	}
	return (max_node);
}

t_list *findmin(t_list **stack_a)
{
	t_list	*curr;
	t_list	*min_node;

	if (stack_a == NULL || *stack_a == NULL)
		return (NULL);
	curr = *stack_a;
	min_node = *stack_a;
	while (curr != NULL)
	{
		if (curr->data < min_node->data)
			min_node = curr;
		curr = curr->next;
	}
	return (min_node);
}

void	move_min_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*min;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	curr = *stack_a;
	min = findmin(stack_a);
	while (curr != min)
	{
		rotate_a(stack_a);
		curr = *stack_a;
	}
	push_b(stack_b, stack_a);
}

void	move_max_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*max;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	curr = *stack_a;
	max = findmax(stack_a);
	while (curr != max)
	{
		rotate_a(stack_a);
		curr = *stack_a;
	}
	push_b(stack_b, stack_a);
}

void	sort_fivelem(t_list **stack_a, t_list **stack_b, int len)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	if (len == 4)
	{
		move_max_to_b(stack_a, stack_b);
		sort_smlen(stack_a);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
	else if (len == 5)
	{
		move_max_to_b(stack_a, stack_b);
		move_min_to_b(stack_a, stack_b);
		sort_smlen(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
}