/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:14:00 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:47:09 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// function that writes a char
int	ft_putchar(char c)
{
	int	i;

	i = 1;
	write(1, &c, 1); // write the char
	return (i); // printf return the number of char so we return 1 for our 1 char
}
