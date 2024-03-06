/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:10 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/05 16:32:19 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **stack_a)
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

void	targ_node_forb(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*targ_node;
	int		max_index;

	if (stack_b == NULL)
	{
		return;
	}
	
	while (stack_a)
	{
		max_index = INT_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->data > stack_b->data && current_a->data < max_index)
			{
				max_index = current_a->data;
				targ_node = current_a;
			}
			current_a = current_a->next;
		}
		if (max_index == INT_MAX)
			stack_b->target_node = find_min(&stack_a);
		else
			stack_b->target_node = targ_node;
		stack_b = stack_b->next;
	}
}


void 	init_nodes_forb(t_list **stack_a, t_list **stack_b)
{
	  targ_node_forb(*stack_a, *stack_b);
	  curent_s_index(*stack_a);
	  curent_s_index(*stack_b);
}

void 	move_back_sa(t_list **stack_a, t_list **stack_b)
{
	check_push(stack_a, (*stack_b)->target_node, 4);
	push_a(stack_a, stack_b);
}

void min_check(t_list **stack_a)
{
	while ((*stack_a) != find_min(stack_a))
	{
		if (find_min(stack_a)->abovem_med)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
	
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = len_stacbk(stack_a);
	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (len_a-- > 3 && check_list_sorted(stack_a) == 0)
		push_b(stack_b, stack_a);
	if (len_a-- > 3 && check_list_sorted(stack_a) == 0)
		push_b(stack_b, stack_a);
	while (len_a-- > 3 && check_list_sorted(stack_a) == 0)
	{
		init_nodes(*stack_a, *stack_b);
		move_na_to_nb(stack_a, stack_b);
	}
	sort_smlen(stack_a);
	while (stack_b)
	{
		init_nodes_forb(stack_a, stack_b);
		move_back_sa(stack_a, stack_b);
	}
	curent_s_index(*stack_a);
	min_check(stack_a);
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
		return (1);
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (split_argv == NULL)
		{
			free(split_argv);
			return (1);
		}
		add_to_Sa(&stack_a, split_argv);
		free(split_argv);
	}
	else if (argc > 2)
		add_to_Sa(&stack_a, &argv[1]);
	len = lenofnums(&argv[1]);
	if (len <= 0)
		return (1);
	if (check_list_sorted(&stack_a) == 0)
	{
		if (len <= 3)
			sort_smlen(&stack_a);
		else if (len > 3)
			sort(&stack_a, &stack_b);
	}
	current = stack_a;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
	free_errors(&stack_a);
	free(current);
	return(0);
}
