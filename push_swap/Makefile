# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 21:52:08 by dswarm            #+#    #+#              #
#    Updated: 2021/10/15 23:32:55 by dswarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

LH = push_swap.h

CC = clang

LA = push_swap.a

SRC =	push_swap.c\
		ft_atoi.c\
		function.c\
		function2.c\
		function3.c\
		function4.c\
		function5.c\
		function6.c\
		oper.c\
		oper2.c\
		oper3.c\

SRC_B =	checker.c\
		ft_atoi.c\
		function.c\
		function2.c\
		function3.c\
		function4.c\
		function5.c\
		function6.c\
		oper.c\
		oper2.c\
		oper3.c\
		oper_bonus.c\
		oper_bonus2.c\
		oper_bonus3.c\
		function_bonus.c\


CFLAGS  = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	 $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.c $(LH) Makefile
	$(CC) $(CFLAGS) -c $<

bonus: $(CHECKER)

$(CHECKER) : $(OBJ_B)
	 $(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_B)

clean:
		rm -f $(OBJ)
		rm -f $(OBJ_B)
fclean:	clean
		rm -f $(NAME)
		rm -f $(CHECKER)

re: fclean all

.PHONY: clean fclean all re
