CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_putnbr.c print_hex.c print_csdui.c
OBJS = ft_printf.o ft_putnbr.o print_hex.o print_csdui.o

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all