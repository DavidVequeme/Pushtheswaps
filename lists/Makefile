# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 13:53:16 by dvidal            #+#    #+#              #
#    Updated: 2025/08/27 14:51:26 by dvidal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := liblist.a

CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC := lst_add.c lst_new.c lstadd_back.c lst_clear.c lst_size.c lst_last.c

OBJ := $(SRC:.c=.o)

HEADER := list.h

AR := ar -rcs
RM := rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $< -I.

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all