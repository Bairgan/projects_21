# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 22:09:08 by dswarm            #+#    #+#              #
#    Updated: 2021/12/25 22:26:28 by dswarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
SRC =	ft_atoi.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_memset.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_putnbr_fd.c\
		ft_putnbr_fd.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_strmapi.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		get_next_line.c\
		get_next_line_utils.c

SRC2 = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\

CFLAGS  = -Wall -Wextra -Werror

OBJ = ft_atoi.o\
		ft_bzero.o\
		ft_isalnum.o\
		ft_memset.o\
		ft_isalpha.o\
		ft_isascii.o\
		ft_isdigit.o\
		ft_isprint.o\
		ft_memccpy.o\
		ft_memchr.o\
		ft_memcmp.o\
		ft_memcpy.o\
		ft_memmove.o\
		ft_memset.o\
		ft_strlcat.o\
		ft_strlcpy.o\
		ft_strlen.o\
		ft_tolower.o\
		ft_toupper.o\
		ft_strchr.o\
		ft_strrchr.o\
		ft_strnstr.o\
		ft_strncmp.o\
		ft_calloc.o\
		ft_strdup.o\
		ft_substr.o\
		ft_strjoin.o\
		ft_putnbr_fd.o\
		ft_putnbr_fd.o\
		ft_putchar_fd.o\
		ft_putstr_fd.o\
		ft_putendl_fd.o\
		ft_strmapi.o\
		ft_strtrim.o\
		ft_split.o\
		ft_itoa.o\
		get_next_line.o\
		get_next_line_utils.o

OBJ2 = ft_lstnew.o\
		ft_lstadd_front.o\
		ft_lstsize.o\
		ft_lstlast.o\

LIB = libft.h

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?
bonus : $(OBJ2)
	ar rcs $(NAME) $?
%.o : %.c $(LIB)
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

clean:
		rm -f $(OBJ) $(OBJ2)
fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
