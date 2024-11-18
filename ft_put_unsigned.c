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
	write_unsigned(nb);
	return (unsigned_count(nb));
}
