/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lindex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:58:24 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/11 12:25:05 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
		|| c == '\v');
}

int	lenofnums(char **arr)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (arr[j] != NULL)
	{
		i = 0;
		if (arr[j][0] != '\0')
		{
			while (arr[j][i] != '\0')
			{
				if (!is_whitespace(arr[j][i]) && (i == 0
						|| is_whitespace(arr[j][i - 1])))
					count++;
				i++;
			}
		}
		j++;
	}
	return (count);
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
	int		i;
	t_list	*curr;

	i = 0;
	curr = *stack_a;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
