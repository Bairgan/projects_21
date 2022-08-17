NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c \
		libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c \
		libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c\
		libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c \
		libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c \
		libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
		libft/ft_putstr_fd.c libft/ft_split.c 	libft/ft_strchr.c \
		libft/ft_strdup.c libft/ft_strjoin.c libft/ft_strlcat.c \
		libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c \
		libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_strrchr.c \
		libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c \
		libft/ft_strcmp.c libft/ft_strcat.c\
		gnl/get_next_line_utils.c gnl/get_next_line.c \
		ft_printf/ft_pars_ast.c ft_printf/ft_pars_wd.c ft_printf/ft_pars_zero.c \
		ft_printf/ft_parsing.c ft_printf/ft_print_c.c ft_printf/ft_print_d.c \
		ft_printf/ft_print_p.c ft_printf/ft_print_s.c ft_printf/ft_print_u.c \
		ft_printf/ft_print_x.c ft_printf/ft_printf.c  ft_printf/ft_utils.c \

OBJS		= ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
		$(AR) $(NAME) $?


clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
