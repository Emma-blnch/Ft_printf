/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:10:40 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/25 12:15:49 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function to check which argument we have and what to return
int	ft_check_format(va_list args, char c)
{
	unsigned int	nbr;
	int				formatLength;

	formatLength = 0;
	if (c == 's') // s for string
		formatLength += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i') // d or i for a number
		formatLength += ft_putnbr(va_arg(args, int));
	else if (c == 'c') // c for a char
		formatLength += ft_putchar(va_arg(args, int));
	else if (c == 'u') // u for an unsigned int
		formatLength += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'p') // p for a pointer
		formatLength += ft_putptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X') // x and X for a number in hexadecimal
	{
		nbr = va_arg(args, unsigned int);
		formatLength += ft_put_hexa(nbr, c);
	}
	else if (c == '%') // % to return a %
		formatLength += ft_putchar('%');
	return (formatLength);
}

// main printf function
int	ft_printf(const char *format, ...)
{
	int		index;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	index = 0;
	count = 0;
	while (format[index])
	{
		if (format[index] == '%') // if we encounter a % sign
		{
			count += ft_check_format(args, format[index + 1]); // we call check_format to check what is after the %
			index++;
		}
		else
			count += ft_putchar(format[index]); // if no % then we just write what is in the position we're at
		index++;
	}
	va_end(args);
	return (count);
}
