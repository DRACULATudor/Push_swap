/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:10 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/28 15:57:40 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_nodes(t_list **a, t_list **b)
{
    t_list *temp = *a;
    *a = *b;
    *b = temp;
}

void sort_three_nodes(t_list **first, t_list **second, t_list **third)
{
    if ((*first)->data > (*second)->data)
        swap_nodes(first, second);
    if ((*first)->data > (*third)->data)
        swap_nodes(first, third);
    if ((*second)->data > (*third)->data)
        swap_nodes(second, third);
}

void update_links(t_list **stack_a, t_list *first, t_list *second, t_list *third)
{
    first->next = second;
    second->next = third;
    third->next = NULL;
    *stack_a = first;
}

void sort_smlen(t_list **stack_a)
{
    t_list	*first;
    t_list	*second;
    t_list	*third;

    if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    first = *stack_a;
    second = first->next;
    if (second != NULL)
        third = second->next;
    else
        third = NULL;
    if (second != NULL && third != NULL)
    {
        sort_three_nodes(&first, &second, &third);
        update_links(stack_a, first, second, third);
    }
}


int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split_argv;
	int		len;
	t_list	*temp;

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
			ft_printf("Error\n");
			free(split_argv);
			return (0);
		}
		add_to_Sa(&stack_a, split_argv);
		free(split_argv);
	}
	else if (argc > 2)
		add_to_Sa(&stack_a, &argv[1]);
	len = lenofnums(&argv[1]);
	if (len <= 3)
		sort_smlen(&stack_a);
	temp = stack_a;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return (0);
}
