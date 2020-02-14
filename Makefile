# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:39:25 by ydonse            #+#    #+#              #
#    Updated: 2020/02/14 14:39:01 by ydonse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = players/ydonse.filler

SRC_PATH = src

SRC_NAME = 	main.c 		\
			parsing.c 	\
			visu.c

ID = $(shell id -un)

CPPFLAGS = -I libft/includes/ -MMD

SDLFLAGS =  $(SDLINCL) -L$(HOME)/.brew/Cellar/sdl2/2.0.10/lib -lSDL2

IMGINCL = -I /Users/$(ID)/.brew/Cellar/sdl2_image/2.0.5/include/SDL2

IMGFLAGS = $(IMGINCL) -L/Users/$(ID)/.brew/Cellar/sdl2_image/2.0.5/lib -lSDL2_image

SDLINCL = -I $(HOME)/.brew/Cellar/sdl2/2.0.10/include/SDL2

LDFLAGS = -L libft/ -lft

CC = gcc

CFLAGS = -Werror -Wall #-Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj


OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER_PATH = includes/

HEADER_NAME = filler.h

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(MIXINCL) $(LDFLAGS) $(SDLFLAGS) $(IMGFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) $(SDLINCL) $(IMGINCL) -o $@ -c $<

clean:
	make clean -C libft/
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
