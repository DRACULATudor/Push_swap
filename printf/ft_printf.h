/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:45:46 by tlupu             #+#    #+#             */
/*   Updated: 2023/12/12 15:41:25 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H "ft_printf.h"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_BASE "0123456789ABCDEF"
# define HEX_BASE_LOW "0123456789abcdef"

int	ft_strlen_pf(const char *s);
int	ft_putchar_pf(char c);
int	ft_printf(const char *pholder, ...);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int n);
int	ft_tohexa(unsigned long long n, char check);
int	ft_printf(const char *pholder, ...);
int	ft_putnbru(unsigned int n);

#endif
