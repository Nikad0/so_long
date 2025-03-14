/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:35:00 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/11 21:50:50 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

static int	check_format(va_list args, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += print_char(va_arg(args, unsigned int));
	else if (format == 's')
		result += print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		result += print_nbr(va_arg(args, int));
	else if (format == 'u')
		result += print_unsigned_nbr(va_arg(args, unsigned int));
	else if (format == 'p')
		result += print_ptr(va_arg(args, unsigned long long),
				"0123456789abcdef", 0);
	else if (format == 'x')
		result += print_hex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		result += print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		result += print_char('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	result;
	va_list			args;

	result = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				result += check_format(args, *format);
			else if (format == 0)
				return (-1);
		}
		else
			result += print_char((int)*format);
		format++;
	}
	va_end(args);
	return (result);
}
