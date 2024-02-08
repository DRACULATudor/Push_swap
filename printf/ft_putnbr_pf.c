/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:58:52 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/13 20:15:58 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calclen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_pf(int n)
{
	int	count;

	count = ft_calclen(n);
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648"));
	else
	{
		if (n < 0)
		{
			ft_putchar_pf('-');
			n = -n;
			count++;
		}
		if (n > 9)
		{
			ft_putnbr_pf(n / 10);
		}
		ft_putchar_pf((n % 10) + '0');
	}
	return (count);
}
