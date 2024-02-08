/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:24:59 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/14 15:56:11 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_tohexa(unsigned long long n, char check)
{
	char					*base_symbol;
	char					my_symbol;
	unsigned long long int	base_value;
	int						count;

	base_value = 16;
	count = 0;
	if (check == 'x')
		base_symbol = HEX_BASE_LOW;
	else
		base_symbol = HEX_BASE;
	if (n >= base_value)
	{
		count += ft_tohexa(n / base_value, check);
	}
	my_symbol = base_symbol[n % base_value];
	while (*base_symbol != my_symbol)
		base_symbol++;
	count += ft_putchar_pf(*base_symbol);
	return (count);
}
// int main()
// {
//     unsigned long long n = ft_tohexa(42 , 'X');
//     printf("%lld", n);
//     return (0);
// }