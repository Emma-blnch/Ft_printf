NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INC)

SRCS = ft_printf.c ft_put_unsigned.c ft_putchar.c ft_put_hexa.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_strlen.c ft_itoa.c

OBJS = $(SRCS:.c=.o)

INC = ft_printf.h

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar rsc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
