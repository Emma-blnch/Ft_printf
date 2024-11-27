#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *src;

	src = "bonjour la france";
	
	ft_printf("my function with d: %d\n", 42);
	printf("printf : %d\n", 42);
	ft_printf("my function: dgs%dxx\n", 10);
	printf("printf : dgs%dxx\n", 10);
	ft_printf("my function: %d\n", 0);
	printf("printf : %d\n", 0);
	ft_printf("my function: %d\n", -200000);
	printf("printf : %d\n", -200000);
	ft_printf("my function: %d %dd%d %d\n", 1, 2, -3, 45);
	printf("printf : %d %dd%d %d\n", 1, 2, -3, 45);
	ft_printf("my function: %d\n", 2147483647);
	printf("printf : %d\n\n", 2147483647);
	
	printf("-------------\n");
	ft_printf("my function with c: %c\n", 'a');
	printf("printf : %c\n", 'a');
	ft_printf("my function: %c%cc%c\n", 'a', 'b', 'C');
	printf("printf : %c%cc%c\n\n", 'a', 'b', 'C');
	
	printf("-------------\n");
	ft_printf("my function with s: %s\n", src);
	printf("printf : %s\n", src);
	ft_printf("my function: %s\n", (char *)NULL);
	printf("printf : %s\n", (char *)NULL);
	ft_printf("my function: %s\n", "can it handle \t and \n?");
	printf("printf: %s\n", "can it handle \t and \n?");
	ft_printf("my function: %s\n", "{} al$#@@@^&$$^#^@@^$*((&");
	printf("printf : %s\n", "{} al$#@@@^&$$^#^@@^$*((&");
	ft_printf("my function: %ss%ss    %s %ssss\n", "And ", "some other", "joined ", "sentences.");
	printf("printf: %ss%ss    %s %ssss\n\n", "And ", "some other", "joined ", "sentences.");
	
	printf("-------------\n");
	ft_printf("my function with p: %p\n", "");
	printf("printf : %p\n", "");
	ft_printf("my function: %p\n", NULL);
	printf("printf : %p\n", NULL);
	ft_printf("my function: %p\n", (void *)-14523);
	printf("printf : %p\n", (void *)-14523);
	ft_printf("my function: %p\n", (void *)2147483647);
	printf("printf : %p\n\n", (void *)2147483647);
	
	printf("-------------\n");
	ft_printf("my function with i: %i\n", -42);
	printf("printf : %i\n", -42);
	ft_printf("my function: %i\n", 0);
	printf("printf : %i\n", 0);
	ft_printf("my function: %i\n", 2147483647);
	printf("printf : %i\n", 2147483647);
	ft_printf("my function: %i\n", -2147483648);
	printf("printf : %li\n", -2147483648);
	ft_printf("my function: %i\n", 10000);
	printf("printf : %i\n\n", 10000);
	
	printf("-------------\n");
	ft_printf("my function with u: %u\n", 356);
	printf("printf : %u\n", 356);
	ft_printf("my function: %u\n", 0);
	printf("printf : %u\n", 0);
	ft_printf("my function: %u\n", -2000000);
	printf("printf : %u\n", -2000000);
	ft_printf("my function: %u\n", 2147483647);
	printf("printf : %u\n", 2147483647);
	ft_printf("my function: %u\n", -2147483648);
	printf("printf : %lu\n\n", -2147483648);
	
	printf("-------------\n");
	ft_printf("my function with x: %x\n", 0);
	printf("printf : %x\n", 0);
	ft_printf("my function: %x\n", 10);
	printf("printf : %x\n", 10);
	ft_printf("my function: %x\n", -200000);
	printf("printf : %x\n", -200000);
	ft_printf("my function: %x\n", 2147483647);
	printf("printf : %x\n", 2147483647);
	ft_printf("my function: %x\n", -2147483648);
	printf("printf : %lx\n", -2147483648);
	ft_printf("my function: dgs%xxx\n", 42);
	printf("printf : dgs%xxx\n\n", 42);
	
	printf("-------------\n");
	ft_printf("my function with X: %X\n", 0);
	printf("printf : %X\n", 0);
	ft_printf("my function: %X\n", 10);
	printf("printf : %X\n", 10);
	ft_printf("my function: %X\n", -200000);
	printf("printf : %X\n", -200000);
	ft_printf("my function: %X\n", 2147483647);
	printf("printf : %X\n", 2147483647);
	ft_printf("my function: %X\n", -2147483648);
	printf("printf : %lX\n", -2147483648);
	ft_printf("my function: dgs%XXX\n", 42);
	printf("printf : dgs%XXX\n\n", 42);
	
	printf("-------------\n");
	ft_printf("my function with percent sign: %%\n");
	printf("printf : %%\n");
	ft_printf("my function: %%%c\n", 'x');
	printf("printf : %%%c\n", 'x');
	ft_printf("my function: %%%%%%\n");
	printf("printf : %%%%%%\n\n");
	
	printf("-------------\n");
	ft_printf("my function with format = 0: %d\n", ft_printf(0));
	printf("printf: %d\n", printf(0));
}

// for testing : 
// cc -Wall -Wextra -Werror ft_printf.c ft_itoa.c ft_putchar.c ft_put_hexa.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_put_unsigned.c ft_strlen.c main.c -o ptf_test
