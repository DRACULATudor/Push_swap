/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:28 by tlupu             #+#    #+#             */
/*   Updated: 2024/03/13 17:08:20 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '0')
		errors(i);
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] > '0' && str[i
				+ 1] <= '9'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
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

void	check_argv(char **argv, char **split_argv, int i)
{
	long	num;

	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (ft_check_num(argv[i]) == 0 || ft_checkdup(&argv[i]) == 1
			|| num > INT_MAX || num < INT_MIN)
			errors(i);
		i++;
	}
	if (split_argv)
		free_split_fail(split_argv);
}

int	check_args(int argc, char **argv)
{
	int		i;
	char	**split_argv;

	i = 0;
	split_argv = NULL;
	if (!validate_argc(argc, argv))
		return (1);
	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (split_argv == NULL)
			free_split_fail(split_argv);
		argv = split_argv;
	}
	if (!ft_strncmp(argv[0], "./push_swap", 10))
		i++;
	check_argv(argv, split_argv, i);
	return (1);
}
