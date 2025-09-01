# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 13:27:55 by dvidal            #+#    #+#              #
#    Updated: 2025/09/01 11:55:28 by dvidal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pushswap

CC := cc
CFLAGS := -Wall -Werror -Wextra -g
LFLAGS := -Lprintf -lftprintf -Llists -llist -Llibft -lft

SRC := parcing.c push_swap.c split.c ft_slen.c ft_strlcpy.c moves.c tester.c

OBJ := $(SRC:.c=.o)

HEADER := push_swap.h

RM := rm -f


all: $(NAME)

$(NAME): $(OBJ)

	$(MAKE) -C ./printf
	$(MAKE) -C ./libft
	$(MAKE) -C ./lists
	$(CC) $(OBJ) -o $(NAME) $(LFLAGS) -I.

clean:
	$(RM) $(OBJ)
	$(MAKE) -C ./printf clean
	$(MAKE) -C ./lists clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./printf fclean
	$(MAKE) -C ./lists fclean


re: fclean all