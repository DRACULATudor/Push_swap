/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:35:24 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/12 15:45:45 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_pf('-');
	}
	if (n > 9)
	{
		count += ft_putnbru(n / 10);
	}
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}
