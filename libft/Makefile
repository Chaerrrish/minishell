# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 16:44:56 by wonyocho          #+#    #+#              #
#    Updated: 2023/10/23 11:28:27 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlcpy.c ft_strrchr.c

BSRCS = ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c

OBJS_MANDATORY = ${SRCS:.c=.o}

OBJS_BONUS = ${BSRCS:.c=.o}

NAME = libft.a

HEAD = libft.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

${NAME}:	all

.c.o:
	${CC} -c ${CFLAGS} $< -o $@

all:	LAST_ALL

bonus:	LAST_BONUS

LAST_ALL: ${OBJS_MANDATORY} ${HEAD}
	rm -f LAST_BONUS
	ar -rc ${NAME} ${OBJS_MANDATORY}
	touch $@

LAST_BONUS:	${OBJS_BONUS} ${HEAD}
	rm -f LAST_ALL
	ar -rc ${NAME} ${OBJS_BONUS}
	touch $@

clean:
	rm -f ${OBJS_MANDATORY}
	rm -f ${OBJS_BONUS}
	rm -f LAST_ALL LAST_BONUS

fclean:	clean
	rm -f ${NAME}

re:
	rm -f ${OBJS_MANDATORY}
	${MAKE} all

.PHONY: all bonus clean fclean re