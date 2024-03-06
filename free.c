/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:42:30 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/22 13:42:43 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack) //Define a function to free a stack if there are errors
{
	t_list	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
	t_list	*current;

	if (!stack) //Check for an empty stack
		return ;
	current = *stack;
	while (current) //As long as a node exist in the stack
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->data = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp; //Assign `tmp` as the current first node
	}
	*stack = NULL;
}

void	free_errors(t_list **stack_a) //Define a function that, upon encountering a unique error, to free the stack and print an error message
{
	free_stack(stack_a);
	ft_printf("Error\n");
	exit(1);
}
