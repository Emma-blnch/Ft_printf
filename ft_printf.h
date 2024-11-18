#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PRINTF_VALID_FORMATS "cspdiuxX\%"
#define PRINTF_VALID_FLAGS " -.*0123456789"
#define HEXALOWER "0123456789abcdef"
#define HEXAUPPER "0123456789ABCDEF"

int ft_check_format(char c, int count);
int ft_printf(const char *format, ...);
int ft_putptr(void *ptr);
int ft_puthexa(unsigned int nbr, const char format);
int ft_put_unsigned(unsigned int nb);
size_t ft_strlen(const char *s);
void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putstr(char *s);

#endif
