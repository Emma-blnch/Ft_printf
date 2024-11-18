#include "ft_printf.h"

static size_t count_digits(unsigned long n)
{
    size_t count;

    count = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        count++;
        n /= 16;
    }
    return (count);
}

static void write_ptr(unsigned long ptr)
{
    char digits[] = "0123456789abcdef";

    if (ptr >= 16)
        write_ptr(ptr / 16);
    write(1, &digits[ptr % 16], 1);
}

int ft_putptr(void *ptr)
{
    if (!ptr)
    {
        write(1, "(nil)", 5);
        return (5);
    }
    write(1, "0x", 2);
    write_ptr((unsigned long)ptr);
    return (count_digits((unsigned long)ptr) + 2);
}
