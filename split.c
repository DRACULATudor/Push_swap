/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:38 by tlupu             #+#    #+#             */
/*   Updated: 2024/02/29 16:42:00 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words(char *s, char c)
{
	int	i;
	int	word;
	int	flag;

	i = 0;
	word = 0;
	flag = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (flag == 0 && s[i] != c)
		{
			word++;
			flag = 1;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (word);
}

static int	ft_wordslength(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static char	*ft_strgen(char *s, char c)
{
	int		i;
	char	*d;

	i = 0;
	d = (char *)malloc(ft_wordslength((char *)s, c) + 1);
	if (d == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

static int	ft_free(char **ptr, char *str)
{
	int	index;
	int	errorcode;

	index = 0;
	errorcode = 0;
	if (str == NULL)
	{
		while (ptr[index])
		{
			free(ptr[index]);
			index++;
		}
		free(ptr);
		errorcode = 1;
	}
	return (errorcode);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		i;
	int		index;
	char	*temp;

	str = (char **)malloc((ft_words((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			temp = ft_strgen((char *)(s + i), c);
			if (!temp || ft_free(str, temp))
				return (NULL);
			str[index++] = temp;
			i += ft_wordslength((char *)(s + i), c);
		}
		else
			i++;
	}
	str[index] = NULL;
	return (str);
}
