/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lindex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:58:24 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/04 11:59:20 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenofnums(char **arr)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (arr[j] != NULL)
	{
		i = 0;
		if (arr[j][0] != '\0')
			while (arr[j][i] != '\0')
			{
				if ((arr[j][i] != ' ' && arr[j][i] != '\t' && arr[j][i] != '\n'
						&& arr[j][i] != '\r' && arr[j][i] != '\f'
						&& arr[j][i] != '\v') && (i == 0 || (arr[j][i
							- 1] == ' ' || arr[j][i - 1] == '\t' || arr[j][i
							- 1] == '\n' || arr[j][i - 1] == '\r' || arr[j][i
							- 1] == '\f' || arr[j][i - 1] == '\v')))
					len++;
				i++;
			}
		j++;
	}
	return (len);
}

int	check_list_sorted(t_list **stack)
{
	t_list	*current;

	if (stack == NULL || *stack == NULL)
		return (1);
	current = *stack;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	len_stack(t_list **stack_a)
{
	int i;
	t_list *curr;
	i = 0;
	curr = *stack_a;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}