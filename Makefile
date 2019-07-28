
NAME = doom-nukem

SRC_PATH = src

SRC_NAME =	main.c						\
			editor/controls.c			\
			editor/actions.c			\
			editor/images.c				\
			editor/editor.c				\
			editor/errors.c				\
			editor/structs_initialize.c	\
			editor/editor_controls.c	\
			editor/lines.c				\
			editor/mouse.c				\
			editor/parsing.c			\
			editor/chainlist.c			\
			editor/utils_1.c			\
			editor/utils_2.c			\
			editor/anchors_general.c	\
			editor/mode_vertex.c		\
			editor/remove_sectors.c		\
			editor/wall.c				\
			editor/mode_deplacement.c	\
			editor/ft_is_in_sector.c	\
			editor/piles.c				\
			editor/fill_sector.c		\
			editor/display_map.c		\
			editor/player.c				\
			editor/mode_floor.c			\
			editor/free.c				\
			editor/fixed_float.c		\
			editor/parser_tga.c			\
			editor/list_utils.c			\
			game/visu.c					\
			game/visu_joan.c			\
			game/visu_joan_drawing.c	\
			game/utils_2.c


CPPFLAGS = -I libft/includes/ -I /usr/local/include/ -MMD

LDFLAGS = -L libft/ -lft  -L /usr/local/include/

CC = gcc

CFLAGS = -Wall -Wextra -g3 #-Werror

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

HEADER_PATH = includes/
HEADER_NAME = doom.h

ID = $(shell id -un)

SDLINCL = $(shell $(ABSOLUTE_DIR)/SDL2/bin/sdl2-config --cflags)
SDLFLAGS =  $(SDLINCL) $(shell $(ABSOLUTE_DIR)/SDL2/bin/sdl2-config --libs)

MIXINCL = -I ./SDL2/include/SDL2/
MIXFLAGS = $(MIXINCL) -L./SDL2/lib -lSDL2_MIXER

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

ABSOLUTE_DIR = $(shell pwd)
SDL2_SRC = $(ABSOLUTE_DIR)/SDL2-2.0.9
SDL2_MIX_SRC = $(ABSOLUTE_DIR)/SDL2_mixer-2.0.4

OK = echo "[32m OK ✓ [0m"

all: $(NAME)

sdl :
	if test ! -f SDL_2.0.9.tar.gz; \
	then curl http://libsdl.org/release/SDL2-2.0.9.tar.gz -o SDL_2.0.9.tar.gz; \
	fi
	if test ! -d SDL2-2.0.9; \
	then tar xvf SDL_2.0.9.tar.gz; \
	fi
	mkdir -p SDL2 2> /dev/null || true
	mkdir -p SDL2/build 2> /dev/null || true
	cd SDL2/build; \
		$(SDL2_SRC)/configure --prefix $(ABSOLUTE_DIR)/SDL2; \
		@make -j6; \
		make install;
	cd $(ABSOLUTE_DIR)
	if test ! -f SDL2_mixer-2.0.4.tar.gz; \
	then curl https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-2.0.4.tar.gz -o SDL2_mixer-2.0.4.tar.gz; \
	fi
	if test ! -d SDL2_mixer-2.0.4; \
	then tar xvf SDL2_mixer-2.0.4.tar.gz; \
	fi
	cd SDL2/build; \
		$(SDL2_MIX_SRC)/configure --prefix $(ABSOLUTE_DIR)/SDL2; \
		@make -j6; \
		make install;

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) $(LDFLAGS) $(SDLFLAGS) $(MIXFLAGS) $(MIXINCL) $(LDLIBS) $(SDLFMK) $^ -o $@
	@$(OK)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) $(SDLINCL) $(MIXINCL) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

sdlclean:
	@rm -rf $(SDL2_SRC) $(SDL2_MIX_SRC) SDL_2.0.9.tar.gz SDL2_mixer-2.0.4.tar.gz SDL2
	@$(OK)

clean:
	@make clean -C libft/
	@rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(OK)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
	@$(OK)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re sdl sdlclean

-include $(OBJ:.o=.d)
