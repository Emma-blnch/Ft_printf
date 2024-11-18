/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:10:40 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/18 15:32:00 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(va_list args, char c)
{
	int	len;
	unsigned int	nbr;

	len = 0;
	if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 'u')
		len += ft_put_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
	{
		nbr = va_args(args, unsigned int);
		len += ft_put_hexa(nbr, c);
	}
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

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
		if (format[i] == '%')
		{
			count += ft_check_format(args, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
