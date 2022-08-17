NAME			=	libftprintf.a

SRC_DIR			=	./srcs
INC_DIR			=	./includes
OBJ_DIR			=	./.obj

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-I$(INC_DIR) -I.

C_FILES			=	$(wildcard $(SRC_DIR)/*.c)
H_FILES			=	$(wildcard $(INC_DIR)/*.h) libftprintf.h
O_FILES			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_FILES))

all: $(NAME)

$(NAME):  $(O_FILES)
	@printf "Creating archive $(NAME)\n"
	@ar rcs $(NAME) $(O_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(H_FILES)
	@mkdir -p $(OBJ_DIR)
	@printf "Making object $<\n"
	@$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)

.SECONDARY: $(O_FILES)
.PHONY:	all clean fclean re dev
