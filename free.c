/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:42:30 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/06 09:34:28 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack) 
{
	t_list	*tmp; 
	t_list	*current;

	if (!stack) 
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next; 
		current->data = 0; 
		free(current);
		current = tmp; 
	}
	*stack = NULL;
}

void	free_errors(t_list **stack_a) 
{
	free_stack(stack_a);
	exit(1);
}
