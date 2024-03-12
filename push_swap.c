/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:10 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/12 17:03:22 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	len_sort(t_list **stack_a, t_list **stack_b, int len)
{
	if (len <= 0)
		return ;
	if (check_list_sorted(stack_a) == 0)
	{
		if (len <= 3)
			sort_smlen(stack_a);
		else if (len > 3)
			sort(stack_a, stack_b);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split_argv;
	int		len;

	stack_a = NULL;
	stack_b = NULL;
	if (!check_args(argc, argv))
		return (1);
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
			return (1);
		add_to_sta(&stack_a, split_argv);
		free(split_argv);
	}
	else if (argc > 2)
		add_to_sta(&stack_a, &argv[1]);
	len = lenofnums(&argv[1]);
	len_sort(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	return (0);
}
