/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:39:26 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/08 18:01:18 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *str)
{
	int	i;
	int	count_minus;
	int	count_plus;
	int	has_digit;

	i = 0;
	count_minus = 0;
	count_plus = 0;
	has_digit = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			count_minus++;
		else if (str[i] == '+')
			count_plus++;
		else if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
        else
            return(0);
		if ((count_minus == 1 && count_plus == 0) || (count_minus == 0 && count_plus))
			return (1);
        else
            return(0);
		i++;
	}
	return (has_digit);
}
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int	ft_checkdup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// int ft_atoi(char *str)
// {
    
// }

int	main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		int i = 1;
		while (i < argc)
		{
			if (ft_check_num(argv[i]) == 0)
			{
                ft_printf("Error\n");
                return(0);
			}
            i++;
		}
        if (ft_checkdup(argc, argv) == 1)
        {
            ft_printf("Error\n");
            return(0);
        }
        
	}
}