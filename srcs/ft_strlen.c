/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:13:41 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:46:43 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// function that returns the size of a string
size_t	ft_strlen(const char *string)
{
	size_t	index;

	index = 0;
	while (string[index])
		index++;
	return (index);
}
