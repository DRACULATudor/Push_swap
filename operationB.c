/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:17:33 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/01 11:22:49 by tlupu            ###   ########.fr       */
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
	ft_printf("sb\n");
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
	ft_printf("pb\n");
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
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*tmp_sc_last;
	t_list	*last;

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
	ft_printf("rrb\n");
}

void	swapswap(t_list **stack_a, t_list **stack_b)
{
	int temp;

	if (stack_b != NULL && *stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = temp;
	}

	if (stack_a != NULL && *stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = temp;
	}
	ft_printf("ss\n");
}
