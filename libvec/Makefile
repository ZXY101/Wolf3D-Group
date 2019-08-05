CC = gcc
NAME = libvec.a
INC = -I ./includes \
	  -I ../libft/includes
CFLAGS = -Wall -Werror -Wextra
SRC_DIR = src
OBJ_DIR = obj
LIBS = -lm
SRC_NAME =	matrix_vector_multiply.c \
			vector_add.c \
			vector_subtract.c \
			vector_multiply.c \
			vector_divide.c \
			vector_dot_product.c \
			vector_length.c \
			vector_normalise.c \
			vector_cross_product.c \
			matrix_make_identity.c \
			matrix_rotate.c \
			matrix_translate.c \
			matrix_projection.c \
			matrix_matrix_multiply.c \
			matrix_scale.c \
			init_to_zero.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_NAME:.c=.o))

bldcyn=\e[1;36m# Cyan
bldgrn=\e[1;32m# Green
txtred=\e[0;31m# Red
txtwht=\e[0;37m# White
bldpur=\e[1;35m# Purple
bldylw=\e[1;33m# Yellow bld
bldred=\e[1;31m# Red bld
txtrst=\e[0m# Reset

$(NAME) : dirmake $(OBJS) 
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "${bldylw}[COMPILED]${bldpur}%44s${txtrst}\n" "$(NAME)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INCF)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

dirmake:
	@mkdir -p obj

all: dirmake $(NAME)

clean:
	@rm -rf $(OBJS)
	@printf "${txtred}[Removed OBJS]${bldred}%40s${txtrst}\n" "$(NAME)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@printf "${txtred}[Removed]${bldred}%45s${txtrst}\n" "$(NAME)"

re: fclean all

.PHONY: all fclean clean re
