/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 02:31:18 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/11 21:55:33 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_ptr(unsigned long nbr, char *base, int mod)
{
	int	result;

	result = 0;
	if (!nbr)
		return (write(1, "(nil)", 5));
	if (mod == 0)
		result += write(1, "0x", 2);
	if (nbr >= 16)
		result += print_ptr(nbr / 16, base, 1);
	result += print_char(base[nbr % 16]);
	return (result);
}

int	print_unsigned_nbr(unsigned int arg)
{
	int	result;

	result = 0;
	if (arg > 9)
		result += print_unsigned_nbr(arg / 10);
	result += print_char(arg % 10 + 48);
	return (result);
}

int	print_str(char *arg)
{
	if (!arg)
		return (write(1, "(null)", 6));
	return (write(1, arg, ft_strlen(arg)));
}

int	print_nbr(int arg)
{
	int				result;
	long long int	n;

	n = arg;
	result = 0;
	if (n < 0)
	{
		n *= -1;
		result += write(1, "-", 1);
	}
	if (n > 9)
		result += print_nbr(n / 10);
	result += print_char(n % 10 + 48);
	return (result);
}

int	print_hex(unsigned int nbr, char *base)
{
	long int	n;
	int			result;

	n = nbr;
	result = 0;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 16)
		result += print_hex(n / 16, base);
	result += print_char(base[n % 16]);
	return (result);
}
