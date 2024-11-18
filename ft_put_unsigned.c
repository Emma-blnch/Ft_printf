/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:29 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/18 15:19:39 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	write_unsigned(unsigned int nb)
{
	if (nb >= 10)
		write_unsigned(nb / 10);
	ft_putchar((nb % 10) + '0');
}

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
