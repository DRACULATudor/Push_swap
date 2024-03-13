/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations3num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:06:50 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/13 15:58:11 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_smlen(t_list **stack)
{
	t_list	*bnode;

	bnode = findmax(stack);
	if (bnode == *stack)
		rotate_a(stack);
	else if ((*stack)->next == bnode)
		reverse_rotate_a(stack);
	if ((*stack)->data > (*stack)->next->data)
		swap_a(stack);
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp_sc_last;
	t_list	*last;

	if (stack != NULL && *stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		tmp_sc_last = NULL;
		while (last->next)
		{
			tmp_sc_last = last;
			last = last->next;
		}
		tmp_sc_last->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	reverse_rotaterotate(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
