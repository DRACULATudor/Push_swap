/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:46:20 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/13 22:04:41 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mcsdui(const char *pholder, va_list arg, int index)
{
	int	count;

	count = 0;
	if (pholder[index + 1] == 'c')
		count += ft_putchar_pf(va_arg(arg, int));
	else if (pholder[index + 1] == 's')
		count += ft_putstr_pf(va_arg(arg, char *));
	else if (pholder[index + 1] == 'd' || pholder[index + 1] == 'i')
		count += ft_putnbr_pf(va_arg(arg, int));
	else if (pholder[index + 1] == '%')
		count += ft_putchar_pf('%');
	return (count);
}

int	ft_puxx(const char *pholder, va_list arg, int index)
{
	int	count;

	count = 0;
	if (pholder[index + 1] == 'p')
	{
		count += ft_putstr_pf("0x");
		count += ft_tohexa((unsigned long long)va_arg(arg, void *), 'x');
	}
	else if (pholder[index + 1] == 'u')
		count += ft_putnbru(va_arg(arg, unsigned));
	else if (pholder[index + 1] == 'x')
		count += ft_tohexa(va_arg(arg, unsigned), 'x');
	else if (pholder[index + 1] == 'X')
		count += ft_tohexa(va_arg(arg, unsigned), 'X');
	return (count);
}

int	check_symbol(const char *pholder, va_list arg, int index)
{
	int	count;

	count = 0;
	if (pholder[index + 1] == 'c' || pholder[index + 1] == 's'
		|| pholder[index + 1] == 'd' || pholder[index + 1] == 'i'
		|| pholder[index + 1] == '%')
		count += ft_mcsdui(pholder, arg, index);
	if (pholder[index + 1] == 'p' || pholder[index + 1] == 'u'
		|| pholder[index + 1] == 'x' || pholder[index + 1] == 'X')
		count += ft_puxx(pholder, arg, index);
	return (count);
}

int	ft_printf(const char *pholder, ...)
{
	va_list	arg;
	int		count_num;
	int		count;
	int		index;

	va_start(arg, pholder);
	count_num = ft_strlen_pf((char *)pholder);
	index = 0;
	count = 0;
	while (index < count_num)
	{
		if (pholder[index] != '%')
		{
			count += ft_putchar_pf(pholder[index]);
			index++;
		}
		else if (pholder[index] == '%')
		{
			count += check_symbol(pholder, arg, index);
			index += 2;
		}
	}
	va_end(arg);
	return (count);
}
