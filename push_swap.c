/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:10 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/04 15:53:58 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*cheapest(t_list *stack_a)
{
	if (!stack_a)
		return (NULL);
	while (stack_a)
	{
		if (stack_a->cheapest)
			return (stack_a);
		stack_a = stack_a->next;
	}
	return (NULL);
}

void	move_na_to_nb(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = cheapest(*stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = len_stack(stack_a);
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
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split_argv;
	int		len;
	t_list	*current;
	int		i;

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
	i = len_stack(&stack_a);
	printf("%d", i);
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
		// printf("%d\n", current->data);
		current = current->next;
	}
}
