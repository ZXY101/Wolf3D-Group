# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcoetzer <rcoetzer@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 17:28:44 by stenner           #+#    #+#              #
#    Updated: 2019/07/30 20:01:10 by rcoetzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIBFT_PATH = ./libft/

VEC_LIB_PATH = ./libvec/

SRC_PATH = ./src/
SDL_LOC = $(CURDIR)/SDL
SDL_CONF = SDLmake/bin/sdl2-config
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
			handle_hooks.c \
			textures.c \
			main_menu.c

LIBS = -L $(LIBFT_PATH) -lft -L $(VEC_LIB_PATH) -lvec  
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

SRCO = $(patsubst %.c, %.o, $(SRC))

ifeq ($(UNAME_S),Linux)
	LDEP = @git clone https://github.com/Rubzy0422/minilibx minilibx;make -C minilibx
	MLX_FLAGS = minilibx/libmlx.a -lXext -lX11 -lm
	LIBS += -L ./SDLmake -l SDL2-2.0

endif
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm
	LIBS += $(shell ./$(SDL2_CONFIG) --cflags --libs)
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


init: destroy
	$(LDEP)
	tar -xvzf SDL_SOURCE.tar.gz
	mkdir -p SDL2-2.0.10/build
	cd SDL2-2.0.10/build; ../configure --prefix=$(SDL_LOC)\
	make; make install
	@make

destroy:
	@rm -rf minilibx
	@rm -rf SDLmake
	@rm -rf SDL2-2.0.10
re: fclean all

.PHONY: all fclean clean re LIBFT VECLIB 
