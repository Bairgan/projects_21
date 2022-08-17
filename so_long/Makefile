# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dswarm <dswarm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 23:28:56 by dswarm            #+#    #+#              #
#    Updated: 2022/01/25 16:09:45 by dswarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=		gcc
NAME	=	so_long
HEADER	=	so_long.h
CFLAGS	=	-Wall -Wextra -Werror

MLX	=		-lmlx -framework OpenGL -framework AppKit

SRC	=		main.c\
			ft_key.c\
			ft_key2.c\
			ft_render.c\
			ft_enemy_moves.c\
			ft_free.c\
			get_collect.c
			
OBJ	=		${SRC:.c=.o}
LIBFTDIR	=	libft
LIBFT	=	$(LIBFTDIR)/libft.a
LIBMLXDIR	=	mlx
LIBMLX	=	$(LIBMLXDIR)/libmlx.a

MAKE	=	make

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(LIBMLX) $(HEADER) Makefile
			$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(LIBMLX) $(OBJ) -o $(NAME)

$(LIBFT):	Makefile $(LIBFTDIR)/libft.h $(LIBFTDIR)/Makefile
			$(MAKE) -C $(LIBFTDIR)

$(LIBMLX):	Makefile $(LIBMLXDIR)/mlx.h $(LIBMLXDIR)/Makefile
			$(MAKE) -C $(LIBMLXDIR)

%.o:	%.c Makefile $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean		:
			rm -f $(OBJ)
			make -C $(LIBFTDIR) clean
			make -C $(LIBMLXDIR) clean

fclean		:	clean
			rm -f $(LIBMLX)
			rm -f $(LIBFT)
			rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
