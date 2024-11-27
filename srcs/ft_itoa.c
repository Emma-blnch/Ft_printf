/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:10:35 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 11:44:47 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// allocate size_total memory for our number and make sure the new string is empty
static char	*allocation_and_initilization(int len)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

// count the total size of our number
static int	size_total(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

// Convert int to char
char	*ft_itoa(int n)
{
	size_t	size;
	int		index;
	char	*result;
	long	number;

	number = n; // store number into a long
	size = size_total(number); // count the total size
	result = allocation_and_initilization(size); // allocate memory
	if (!result) // safety if allocation failed
		return (NULL);
	if (number < 0)
		number = -number;
	index = size - 1; // start at end of the number we converted into a string
	while (number != 0) // as long as we don't reach the start of the number
	{
		result[index] = (number % 10) + '0'; // we convert the final caracter of our string into a char
		number /= 10;
		index--; // then we do the sam for the one before
	}
	if (n < 0)
		result[0] = '-'; // if it's a negative number we put a minus sign at the start
	result[size] = '\0'; // we add the null caracter terminating our string
	return (result); // and we return our number converted into a char string
}
