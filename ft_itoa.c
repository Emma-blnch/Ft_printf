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

// allocate size_total memoryfor our number and make sure the new string is empty
static char	*pre_conv(int len)
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
	int		i;
	char	*result;
	long	nb;

	nb = n; // store number into a long
	size = size_total(nb); // count the total size
	result = pre_conv(size); // allocate memory
	if (!result) // safety if allocation failed
		return (NULL);
	if (nb < 0)
		nb = -nb;
	i = size - 1; // start at end of the number we converted into a string
	while (nb != 0) // as long as we don't reach the start of the number
	{
		result[i] = (nb % 10) + '0'; // we convert the final caracter of our string into a char
		nb /= 10;
		i--; // then we do the sam for the one before
	}
	if (n < 0)
		result[0] = '-'; // if it's a negative number we put a minus sign at the start
	result[size] = '\0'; // we add the null caracter terminating our string
	return (result); // and we return our number converted into a char string
}
