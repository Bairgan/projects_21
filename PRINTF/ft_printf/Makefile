# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/13 10:50:18 by dswarm            #+#    #+#              #
#    Updated: 2021/07/13 20:33:12 by dswarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

SRC = ft_printf.c\
		ft_function.c\

CFLAGS  = -Wall -Wextra -Werror

OBJ = ft_printf.o\
		ft_function.o\

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

PRINTF = printf.h

%.o : %.c $(PRINTF)
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

clean:
		rm -f $(OBJ)
fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
