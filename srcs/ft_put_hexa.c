/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:10 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/27 09:55:47 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function that counts the number of digits for printf to return
static size_t	count_base16_digits(unsigned int number)
{
	size_t	count;

	count = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		count++;
		number /= 16;
	}
	return (count);
}

// function that writes our number in hexadecimal form (with "0x" if its a pointer)
static void	write_base16(unsigned long number, const char format, int prefix)
{
	char	*upper_digits;
	char	*lower_digits;

	upper_digits = "0123456789ABCDEF";
	lower_digits = "0123456789abcdef";
	if (prefix != 0)
		write(1, "0x", 2);
	if (number >= 16)
		write_base16(number / 16, format, 0);
	if (format == 'x')
		write(1, &lower_digits[number % 16], 1);
	if (format == 'X')
		write(1, &upper_digits[number % 16], 1);
}


// main function that calls our other two to write in hexadecimal and return the length of the number
int	ft_put_hexa(unsigned int number, const char format)
{
	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	write_base16(number, format, 0);
	return (count_base16_digits(number));
}

int	ft_putptr(void *pointer)
{
	if (!pointer)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write_base16((unsigned long)pointer, 'x', 1);
	return (count_base16_digits((unsigned long)pointer) + 2);
}
