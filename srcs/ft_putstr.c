/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:18:19 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:46:55 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function that writes a string
int	ft_putstr(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6); // protection if the string is NULL
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1); // we parse s with our index and write every char
		i++;
	}
	return (i); // we return the number of char we wrote
}
