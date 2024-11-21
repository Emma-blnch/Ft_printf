/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:10:40 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:56:20 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function to check which argument we have and what to return
int	ft_check_format(va_list args, char c)
{
	unsigned int	nbr;
	int				len;

	len = 0;
/* each if condition checks what is the argument and calls the associated function to return what is expected */
	if (c == 's') // s for string
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i') // d or i for a number
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'c') // c for a char
		len += ft_putchar(va_arg(args, int));
	else if (c == 'u') // u for an unsigned int
		len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'p') // p for a pointer
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X') // x and X for a number in hexadecimal
	{
		nbr = va_arg(args, unsigned int);
		len += ft_put_hexa(nbr, c);
	}
	else if (c == '%') // % to return a %
		len += ft_putchar('%');
	return (len); // we don't forget to return the length expected by printf
}

// main printf function
int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%') // if we encounter a % sign
		{
			count += ft_check_format(args, format[i + 1]); // we call check_format to check what is after the %
			i++;
		}
		else
			count += ft_putchar(format[i]); // if no % then we just write what is in the position we're at
		i++;
	}
	va_end(args);
	return (count);
}
