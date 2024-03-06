/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:28 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/01 11:08:20 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_checkdup(char **argv)
{
	int	i;
	int	j;
	int	argc;

	i = 0;
	j = 0;
	argc = 0;
	while (argv[argc])
		argc++;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] != '\0' && s1[i] == s2[i] && i <= n)
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_args(int argc, char **argv)
{
	int i;
	char **split_argv;

	i = 0;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (split_argv == NULL)
		{
			ft_printf("Error\n");
			return (0);
		}
		argv = split_argv;
	}
	if (!ft_strncmp(argv[0], "./push_swap", 10))
		i++;
	while (argv[i])
	{
		if (ft_check_num(argv[i]) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		if (ft_checkdup(&argv[i]) == 1)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
