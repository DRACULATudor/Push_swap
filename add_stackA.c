/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stackA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:53 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/06 11:02:30 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->data = content;
	new->next = NULL;
	return (new);
}

void 	add_to_Sa(t_list **stack,char **str)
{
	int i = 0;
	t_list	*new_node;
	t_list  *temp;
	t_list  *next2;
	
	while (str[i])
		{
			new_node = ft_lstnew(ft_atoi(str[i]));
			if (new_node == NULL)
			{
				temp = *stack;
				while (temp)
				{
					next2 = temp->next;
					free(temp);
					temp = next2;
				}
				free_errors(stack);
				*stack = NULL;
				return;
			}
			ft_lstadd_back(stack, new_node);
			i++;
		}
}