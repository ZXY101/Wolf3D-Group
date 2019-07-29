# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stenner <stenner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 17:28:44 by stenner           #+#    #+#              #
#    Updated: 2019/07/29 12:17:41 by rcoetzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIBFT_PATH = ./libft/

VEC_LIB_PATH = ./libvec/

SRC_PATH = ./src/

INCLUDES_PATH = ./includes/
UNAME_S := $(shell uname -s)


INCLUDES =	-I $(LIBFT_PATH)/includes \
			-I $(VEC_LIB_PATH)/includes \
			-I $(INCLUDES_PATH)

MLX_PATH = ./MinilibX/

SRC_NAME =	main.c \
			images.c \
			draw_line.c \
			gfx_utility.c \
			handle_hooks.c

LIBS = -L $(LIBFT_PATH) -lft -L $(VEC_LIB_PATH) -lvec
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(patsubst %.c, %.o, $(SRC))

ifeq ($(UNAME_S),Linux)
	LDEP = @git clone https://github.com/Rubzy0422/minilibx minilibx;make -C minilibx
	MLX_FLAGS = minilibx/libmlx.a -lXext -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm
endif

FLAGS = -Wall -Werror -Wextra

all: LIBFT VECLIB $(NAME)

LIBFT:
	@make -C $(LIBFT_PATH)

VECLIB:
	@make -C $(VEC_LIB_PATH)


$(LIBFT_PATH)libft.a:
	@make -C $(LIBFT_PATH)

$(VEC_LIB_PATH)libvec.a:
	@make -C $(VEC_LIB_PATH)

$(NAME): $(SRCO) $(LIBFT_PATH)libft.a $(VEC_LIB_PATH)libvec.a
	@gcc $(FLAGS) $(SRCO) $(LIBS) -o $(NAME) $(MLX_FLAGS)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m Created.\033[0m"

$(SRC_PATH)%.o: $(SRC_PATH)%.c $(INCLUDES_PATH)$(NAME).h
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@/bin/rm -rf $(SRCO)
	@echo "\033[31mObjects Files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31mRemoved.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@make -C $(VEC_LIB_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m Removed.\033[0m"

re: fclean all

.PHONY: all fclean clean re LIBFT VECLIB 
