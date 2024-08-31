# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 17:59:08 by wonyocho          #+#    #+#              #
#    Updated: 2024/08/31 14:56:17 by chaoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEAD = libft.h

# Source files
SRCS = 	ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c \
		ft_strrchr.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c \
		ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c \
		ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
		ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c \
		ft_strncmp.c ft_tolower.c ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c \
		ft_strlcat.c ft_strnstr.c ft_toupper.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

# Bonus source files
BSRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(BOBJS) $(PRINTF_LIB)
	ar -rc $(NAME) $(OBJS) $(BOBJS)
	ar -rc $(NAME) $(PRINTF_LIB)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

clean: ft_printf_clean
	rm -rf $(OBJS) $(BOBJS)

fclean: clean ft_printf_fclean
	rm -rf $(NAME)

re: fclean all

ft_printf_clean:
	$(MAKE) -C $(PRINTF_DIR) clean

ft_printf_fclean:
	$(MAKE) -C $(PRINTF_DIR) fclean

.PHONY: all clean fclean re ft_printf_clean ft_printf_fclean
