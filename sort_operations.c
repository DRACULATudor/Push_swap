/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:06:50 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/29 14:08:22 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_smlen_helper(t_list **stack)
{
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data)
		swap_a(stack);
	else if ((*stack)->data > (*stack)->next->next->data
		&& (*stack)->next->data < (*stack)->next->next->data)
	{
		reverse_rotate_a(stack);
		reverse_rotate_a(stack);
	}
}

void	sort_smlen(t_list **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	if ((*stack)->next->next == NULL)
	{
		if ((*stack)->data > (*stack)->next->data)
		{
			swap_a(stack);
		}
		return ;
	}
	sort_smlen_helper(stack);
	if ((*stack)->next->data > (*stack)->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		reverse_rotate_a(stack);
		if ((*stack)->next->data < (*stack)->next->next->data
			&& (*stack)->next->data < (*stack)->data)
			swap_a(stack);
	}
	else if ((*stack)->data < (*stack)->next->next->data
		&& (*stack)->next->next->data < (*stack)->next->data)
		rotate_a(stack);
}
