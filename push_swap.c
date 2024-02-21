/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:10 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/21 16:54:17 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	add_to_Sa(t_list **stack,char **str)
{
	int i = 0;
	t_list	*new_node;
	
	while (str[i])
		{
			new_node = ft_lstnew(ft_atoi(str[i]));
			if (new_node == NULL)
			{
				ft_printf("Error\n");
				return;
			}
			ft_lstadd_back(stack, new_node);
			i++;
		}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split_argv;

	stack_a = NULL;
	stack_b = NULL;
	split_argv = NULL;
	if (!check_args(argc, argv))
		return (0);
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (split_argv == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		add_to_Sa(&stack_a, split_argv);
	}
	else if (argc > 2)
		add_to_Sa(&stack_a, &argv[1]);	
	while (stack_a != NULL)
	{
		printf("%d\n", stack_a ->data);
		stack_a = stack_a ->next;
	}
	return (0);
}
