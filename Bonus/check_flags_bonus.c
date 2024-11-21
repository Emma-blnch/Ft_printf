/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:53:18 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:59:54 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// initialize all flags to 0 to avoid mistakes
static t_flags	init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.dot = 0;
	return (flags);
}

// parse the argument in printf to check for flags
static int	parse_basic_flags(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (format[i] && ft_strchr("-0+ #", format[i]))
	{
		if (format[i] == '-')
			flags->minus = 1;
		else if (format[i] == '0')
			flags->zero = 1;
		else if (format[i] == '+')
			flags->plus = 1;
		else if (format[i] == ' ')
			flags->space = 1;
		else if (format[i] == '#')
			flags->hash = 1;
		i++;
	}
	return (i);
}

// check the width if there is one in argument
static int	parse_width(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	if (format[i] == '*')
	{
		flags->width = va_args(args, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		return (1);
	}
	while (ft_isdigit(format[i]))
	{
		flags->width = flags-> width * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

// check precision if there is one in argument
static int	parse_precision(const char *format, t_flags *flags, va_list args)
{
	int	i;

	i = 0;
	if (format[i] != '.')
		return (0);
	flags->dot = 1;
	i++;
	if (format[i] == '*')
	{
		flags->precision = va_args(args, int);
		return (i + 1);
	}
	while (ft_isdigit(format[i]))
	{
		flags->precision = flags->precision * 10 + (format[i] - '0');
		i++;
	}
	return (i);
}

// check for the flags
int	parse_flags(const char *format, t_flags *flags, va_list args)
{
	int	i;

	i += parse_basic_flags(format + i, flags);
	i += parse_width(format + i, flags, args);
	i += parse_precision(format + i, flags, args);
	return (i);
}
