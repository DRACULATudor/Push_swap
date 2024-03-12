/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:55:17 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/12 17:04:49 by tlupu            ###   ########.fr       */
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

t_list	*findmin(t_list **stack_a)
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

int	validate_argc(int argc, char **argv)
{
	int	n;

	n = lenofnums(&argv[1]);
	if (n <= 0)
		errors(1);
	if (argc < 2)
		exit(0);
	return (1);
}
