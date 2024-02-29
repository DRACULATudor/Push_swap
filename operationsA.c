/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:55:54 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/29 13:33:01 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	int	temp;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = temp;
	ft_printf("sa\n");
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_b == NULL || *stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_printf("pa\n");
}

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list *tmp_sc_last;
	t_list *last;

	last = *stack_a;
	tmp_sc_last = NULL;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	while (last->next)
	{
		tmp_sc_last = last;
		last = last->next;
	}
	tmp_sc_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	ft_printf("rra\n");
}