# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 22:13:34 by dswarm            #+#    #+#              #
#    Updated: 2022/02/03 22:16:30 by dswarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
HEADER		=	philo.h
CFLAGS		=	-Wall -Werror -Wextra -pthread
CC			=	clang
SRC			=	main.c
OBJ			=	$(SRC:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(HEADER) Makefile
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o			:	%.c Makefile $(HEADER)
			$(CC) $(CFLAGS) -c $< -o $@

clean		:
			rm -f $(OBJ)

fclean		:	clean
			rm -f $(NAME)

re			:	fclean all

.PHONY: all clean fclean re bonus
