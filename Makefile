# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stenner <stenner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 17:28:44 by stenner           #+#    #+#              #
#    Updated: 2019/08/06 14:52:55 by stenner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#sudo apt-get install libfreetype6-dev make gcc pkg-config \
 libx11-dev libxext-dev libasound2-dev libpulse-dev

NAME = wolf3d

LIBFT_PATH = ./libft/
VEC_LIB_PATH = ./libvec/

SRC_PATH = ./src/

SDL_LOC = $(CURDIR)/SDL
SDL_CONF = $(SDL_LOC)/lib/pkgconfig
SDL_SRC=SDL2-2.0.10
SDL_MIX_SRC=SDL2_mixer-2.0.4
SDL_TTF_SRC=SDL2_ttf-2.0.15

LIBS=

INCLUDES_PATH = ./includes/
UNAME_S := $(shell uname -s)
FLAGS = -Wall -Werror -Wextra -g

INCLUDES =	-I $(LIBFT_PATH)/includes \
			-I $(VEC_LIB_PATH)/includes \
			-I $(INCLUDES_PATH) \
			-I $(SDL_LOC)/include \
			-I $(MLX_PATH)

MLX_PATH = ./MinilibX

SRC_NAME =	main.c \
			images.c \
			draw_line.c \
			gfx_utility.c \
			handle_hooks.c \
			textures.c \
			keys.c \
			render_rays.c \
		    main_menu.c \
			draw_textures.c \
			misc.c \
			text.c \
			map_split.c \
			map_validator.c \
			map_validator2.c \
			map_interpreter.c \
			sdl.c \
			sound.c

LIBS = -L $(LIBFT_PATH) -lft -L $(VEC_LIB_PATH) -lvec 
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
SRCO = $(patsubst %.c, %.o, $(SRC))

ifeq ($(UNAME_S),Linux)
	MLX_FLAGS = $(MLX_PATH)/libmlx.a -lXext -lX11 -lm
	LIBS += $(shell export PKG_CONFIG_PATH=$(SDL_CONF); pkg-config --cflags --libs sdl2 SDL2_ttf SDL2_mixer)
endif
ifeq ($(UNAME_S),Darwin)
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm
	LIBS += $(shell export PKG_CONFIG_PATH=$(SDL_CONF); pkg-config --cflags --libs sdl2 SDL2_ttf SDL2_mixer)
endif

all: $(LIBFT_PATH) $(VEC_LIB_PATH) $(NAME) 

$(LIBFT_PATH):
	@git clone https://github.com/Rubzy0422/libft.git $(LIBFT_PATH)

$(VEC_LIB_PATH):
	@git clone https://github.com/Rubzy0422/libvec.git $(VEC_LIB_PATH)
	
$(LIBFT_PATH)libft.a:
	@make -C $(LIBFT_PATH)

$(VEC_LIB_PATH)libvec.a:
	@make -C $(VEC_LIB_PATH)

$(NAME): $(SRCO) $(LIBFT_PATH)libft.a $(VEC_LIB_PATH)libvec.a
	@gcc $(FLAGS) $(SRCO) $(LIBS) -o $(NAME) $(MLX_FLAGS)
	@printf "\e[32mBinary \e[1;32m$(NAME)\e[1;0m\e[32m Created.\e[0m\n"

$(SRC_PATH)%.o: $(SRC_PATH)%.c $(INCLUDES_PATH)$(NAME).h
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@/bin/rm -rf $(SRCO)
	@printf "\e[31mObjects Files \e[1;31m$(OBJS_LIST)\e[1;0m\e[31mRemoved.\e[0m\n"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@make -C $(VEC_LIB_PATH)/ fclean
	@rm -rf SDL2*
	@/bin/rm -rf $(NAME)
	@printf "\e[31mBin \e[1;31m$(NAME)\e[1;0m\e[31m Removed.\e[0m\n"

SDL: $(SDL_SRC) $(MLX_PATH) $(SDL_TTF_SRC) $(SDL_MIX_SRC)
	@make
	@rm -rf SDL2*

destroy: fclean
	@rm -rf $(MLX_PATH)
	@rm -rf SDL*
	@rm -rf *.tar.gz

$(SDL_MIX_SRC):
	curl -L https://www.libsdl.org/projects/SDL_mixer/release/$(SDL_MIX_SRC).tar.gz -o $(SDL_MIX_SRC).tar.gz
	@tar -xvzf $(SDL_MIX_SRC).tar.gz
	mkdir -p $(SDL_MIX_SRC)/build
	cd $(SDL_MIX_SRC)/build; ../configure --prefix=$(SDL_LOC); make install;

$(SDL_TTF_SRC): 
	curl -L https://www.libsdl.org/projects/SDL_ttf/release/$(SDL_TTF_SRC).tar.gz -o $(SDL_TTF_SRC).tar.gz
	@tar -xvzf $(SDL_TTF_SRC).tar.gz
	mkdir -p $(SDL_TTF_SRC)/build
	cd $(SDL_TTF_SRC)/build; ../configure --prefix=$(SDL_LOC); make install;

$(SDL_SRC):
	curl -L https://www.libsdl.org/release/$(SDL_SRC).tar.gz -o $(SDL_SRC).tar.gz
	@tar -xvzf $(SDL_SRC).tar.gz
	mkdir -p $(SDL_SRC)/build
	cd $(SDL_SRC)/build; ../configure --prefix=$(SDL_LOC); make install;

$(MLX_PATH):
	@git clone https://github.com/Rubzy0422/minilibx $(MLX_PATH);make -C $(MLX_PATH)

Brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

pkg-config:
	brew install pkg-config

re: fclean all

.PHONY: all fclean clean re LIBFT VECLIB init destroy 
