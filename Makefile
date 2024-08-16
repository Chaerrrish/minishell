# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wonyocho <wonyocho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 17:59:08 by wonyocho          #+#    #+#              #
#    Updated: 2024/08/16 14:28:54 by wonyocho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/opt/homebrew/opt/readline/include
CFLAGS = -I/opt/homebrew/opt/readline/include
LDFLAGS = -L/opt/homebrew/opt/readline/lib -lreadline

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I src/header -I $(LIBFT_DIR)

SRC_FILES = $(shell find src -name "*.c")
OBJ_FILES = $(SRC_FILES:.c=.o)

NAME = minishell

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) $(LIBFT) $(CFLAGS) $(LDFLAGS) -o $@

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re