/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:16:58 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:52:07 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function to count and returns length of the pointer
static size_t	count_digits(unsigned long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

// function to write the pointer
static void	write_ptr(unsigned long pointer)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (pointer >= 16)
		write_ptr(pointer / 16);
	write(1, &digits[pointer % 16], 1);
}

// main function that calls the other two
int	ft_putptr(void *pointer)
{
	if (!pointer)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	write_ptr((unsigned long)pointer);
	return (count_digits((unsigned long)pointer) + 2);
}
