NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = libft.h
SRCS = 	ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c \
		ft_strrchr.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c \
		ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c \
		ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
		ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c \
		ft_strncmp.c ft_tolower.c ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c \
		ft_strlcat.c ft_strnstr.c ft_toupper.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BSRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all : ft_printf LAST_ALL

bonus : ft_printf LAST_BONUS

ft_printf:
	$(MAKE) -C ft_printf

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS) $(HEAD)

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

LAST_ALL : $(OBJS) $(HEAD)
	rm -f LAST_BONUS
	ar -rc $(NAME) $(OBJS)
	touch $@

LAST_BONUS : $(BOBJS) $(HEAD)
	rm -f LAST_ALL
	ar -rc $(NAME) $(BOBJS)
	touch $@

clean : ft_printf_clean
	rm -rf $(OBJS)
	rm -rf $(BOBJS)
	rm -rf LAST_BONUS LAST_ALL
	
fclean: ft_printf_fclean clean
	rm -rf $(NAME)

re: fclean all

ft_printf_clean:
	$(MAKE) -C ft_printf clean

ft_printf_fclean:
	$(MAKE) -C ft_printf fclean

.PHONY: all clean fclean bonus re ft_printf ft_printf_clean ft_printf_fclean
