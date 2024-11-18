/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:10 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/18 15:33:29 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexa_digits(unsigned int n)
{
	size_t	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 16;
	}
	return (count);
}

static void	write_hexa(unsigned int nbr, const char format)
{
	char	*upper_digits;
	char	*lower_digits;

	upper_digits = "0123456789ABCDEF";
	lower_digits = "0123456789abcdef";
	if (nbr >= 16)
	{
		write_hexa(nbr / 16, format);
		write_hexa(nbr % 16, format);
	}
	else
	{
		if (format == 'x')
			write(1, &lower_digits[nbr % 16], 1);
		if (format == 'X')
			write(1, &upper_digits[nbr % 16], 1);
	}
}

int	ft_put_hexa(unsigned int nbr, const char format)
{
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	else
		write_hexa(nbr, format);
	return (hexa_digits(nbr));
}
