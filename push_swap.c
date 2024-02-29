/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:10 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/29 17:12:48 by tlupu            ###   ########.fr       */
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
		{
			max_node = curr;
		}
		curr = curr->next;
	}
	return (max_node);
}

t_list *findmin(t_list **stack_a)
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
		{
			min_node = curr;
		}
		curr = curr->next;
	}
	return (min_node);
}
void	move_min_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*min;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	curr = *stack_a;
	min = findmin(stack_a);
	while (curr != min)
	{
		rotate_a(stack_a);
		curr = *stack_a;
	}
	push_b(stack_b, stack_a);
}

void	move_max_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	t_list	*max;

	if (stack_a == NULL || *stack_a == NULL)
		return ;
	curr = *stack_a;
	max = findmax(stack_a);
	while (curr != max)
	{
		rotate_a(stack_a);
		curr = *stack_a;
	}
	push_b(stack_b, stack_a);
}

void	sort_fivelem(t_list **stack_a, t_list **stack_b, int len)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	if (len == 4)
	{
		move_max_to_b(stack_a, stack_b);
		sort_smlen(stack_a);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
	else if (len == 5)
	{
		move_max_to_b(stack_a, stack_b);
		move_min_to_b(stack_a, stack_b);
		sort_smlen(stack_a);
		push_a(stack_a, stack_b);
		// rotate_a(stack_a);
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
	
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split_argv;
	int		len;
	t_list	*current;

	stack_a = NULL;
	stack_b = NULL;
	split_argv = NULL;
	len = 0;
	if (!check_args(argc, argv))
		return (0);
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (split_argv == NULL)
		{
			free(split_argv);
			return (0);
		}
		add_to_Sa(&stack_a, split_argv);
		free(split_argv);
	}
	else if (argc > 2)
		add_to_Sa(&stack_a, &argv[1]);
	len = lenofnums(&argv[1]);
	if (len <= 0)
		return (0);
	if (check_list_sorted(&stack_a) == 0)
	{
		if (len <= 3)
			sort_smlen(&stack_a);
		else if (len <= 5 && len >= 3)
			sort_fivelem(&stack_a, &stack_b, len);
	}
	current = stack_a;
	while (current != NULL)
	{
		current = current->next;
	}
}
