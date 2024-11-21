/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:54:53 by eblancha          #+#    #+#             */
/*   Updated: 2024/11/21 12:01:59 by eblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define PRINTF_VALID_FORMATS "cspdiuxX\%"
# define PRINTF_VALID_FLAGS " -.*0123456789"
# define HEXALOWER "0123456789abcdef"
# define HEXAUPPER "0123456789ABCDEF"

int		ft_printf(const char *format, ...);
int		ft_putptr(void *ptr);
int		ft_put_hexa(unsigned int nbr, const char format);
int		ft_put_unsigned(unsigned int nb);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
char	*ft_itoa(int n);

// added a struct containing all the possible flags
typedef struct s_flags {
	int	minus;
	int	zero;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	precision;
	int	dot;
}	t_flags;

#endif
