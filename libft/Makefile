# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcoetzer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 07:34:13 by rcoetzer          #+#    #+#              #
#    Updated: 2019/08/03 18:13:20 by rcoetzer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
CC= gcc
SRC = ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strdup.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strstr.c\
	ft_strnstr.c\
	ft_strcmp.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_memalloc.c\
	ft_memdel.c\
	ft_strnew.c\
	ft_strdel.c\
	ft_strclr.c\
	ft_striter.c\
	ft_striteri.c\
	ft_strmap.c\
	ft_strmapi.c\
	ft_strequ.c\
	ft_strnequ.c\
	ft_strsub.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strsplit.c\
	ft_itoa.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstdelone.c\
	ft_lstdel.c\
	ft_lstadd.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_pow.c\
	ft_lststrsplit.c\
	ft_lstprint.c\
	ft_wordc.c\
	ft_lstcount.c\
	get_next_line.c\
	ft_del.c\
	ft_atof.c\
	ft_freearr.c\
	ft_strjoin_free.c\
	ft_hyperbole.c\
	ft_realloc.c\
	ft_swap.c

INC = -I ./includes
SRC_DIR = src
OBJ_DIR = obj
OBJ			= $(SRC:.c=.o)
SRCS		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

txtblk=\e[0;30m
txtred=\e[0;31m # Red
txtgrn=\e[0;32m # Green
txtylw=\e[0;33m # Yellow
txtblu=\e[0;34m # Blue
txtpur=\e[0;35m # Purple
txtcyn=\e[0;36m # Cyan
txtwht=\e[0;37m # White
bldblk=\e[1;30m # Black - Bold
bldred=\e[1;31m # Red
bldgrn=\e[1;32m # Green
bldylw=\e[1;33m # Yellow
bldblu=\e[1;34m # Blue
bldpur=\e[1;35m # Purple
bldcyn=\e[1;36m # Cyan
bakblk=\e[40m
bakred=\e[41m   # Red
bakgrn=\e[42m   # Green
bakylw=\e[43m   # Yellow
bakblu=\e[44m   # Blue
bakpur=\e[45m   # Purple
bakcyn=\e[46m   # Cyan
bakwht=\e[47m   # White
txtrst=\e[0m


all: directory $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "${bldylw}[COMPILED]${bldpur}%40s${txtrst}\n" "$(NAME)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $^ -o $@ $(INC)

directory: $(OBJ_DIR)

$(OBJ_DIR):
	@printf "${bldgrn}%40s${bldpur}%s${bldgrn}%s\n${txtrst}" "[Compiling" "$(NAME)!" "]"
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean directory
