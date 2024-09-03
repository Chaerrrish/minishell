# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaerin <chaerin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 17:59:08 by wonyocho          #+#    #+#              #
#    Updated: 2024/09/03 19:09:41 by chaerin          ###   ########.fr        #
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
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c ft_printf/ft_putnbr.c ft_printf/print_csdui.c \
		ft_printf/print_hex.c

# Bonus source files
BSRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(BOBJS)
	ar -rc $(NAME) $(OBJS) $(BOBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean: 
	rm -rf $(OBJS) $(BOBJS)

fclean: clean 
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re