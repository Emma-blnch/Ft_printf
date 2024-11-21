/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:29 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:52:20 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function that counts the length of our unsigned
static size_t	unsigned_count(unsigned int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

// function that writes unsigned int
static void	write_unsigned(unsigned int nb)
{
	if (nb >= 10)
		write_unsigned(nb / 10); // we divide by 10 to write each number (for 12 we write 1 first then 2)
	ft_putchar((nb % 10) + '0'); // we convert each number to char
}

// main function that calls our other two to write an unsigned int and return its length
int	ft_put_unsigned(unsigned int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	write_unsigned(nb);
	return (unsigned_count(nb));
}
