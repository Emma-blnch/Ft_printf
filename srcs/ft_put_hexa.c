/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:10 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:52:37 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function that counts the number of digits for printf to return
static size_t	count_hexa_digits(unsigned int number)
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

// function that writes our number in hexadecimal form
static void	write_hexa_number(unsigned int number, const char format)
{
	char	*upper_digits;
	char	*lower_digits;

	upper_digits = "0123456789ABCDEF";
	lower_digits = "0123456789abcdef";
	if (number >= 16)
	{
		write_hexa(number / 16, format);
		write_hexa(number % 16, format);
	}
	else
	{
		if (format == 'x')
			write(1, &lower_digits[number % 16], 1);
		if (format == 'X')
			write(1, &upper_digits[number % 16], 1);
	}
}


// main function that calls our other two to write in hexadecimal and return the length of the number
int	ft_put_hexa(unsigned int number, const char format)
{
	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	write_hexa_number(number, format);
	return (count_hexa_digits(number));
}
