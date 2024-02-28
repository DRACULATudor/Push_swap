/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:17:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/21 18:21:32 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_list **stack_b)
{
	int	temp;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = temp;
}

void	push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list *tmp_sc_last;
	t_list *last;

	last = *stack_b;
	tmp_sc_last = NULL;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	while (last->next)
	{
		tmp_sc_last = last;
		last = last->next;
	}
	tmp_sc_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
}