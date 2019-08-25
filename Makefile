# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:39:25 by ydonse            #+#    #+#              #
#    Updated: 2019/08/25 17:17:28 by ydonse           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ydonse.filler

SRC_PATH = src

SRC_NAME = main.c

CPPFLAGS = -I libft/includes/ -MMD

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
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) -o $@ -c $<

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
