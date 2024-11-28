NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(INC)

SRCS = ft_printf.c \
srcs/ft_put_unsigned.c \
src/ft_putchar.c \
srcs/ft_put_hexadecimal.c \
srcs/ft_putnbr.c \
srcs/ft_putstr.c \
srcs/ft_strlen.c \
srcs/ft_itoa.c

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
