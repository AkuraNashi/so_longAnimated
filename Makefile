# ------------  COLORS  ------------------------------------------------------ #
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_ORANGE=\033[0;34m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[0;33m
COLOUR_CYAN=\033[0;36m

# ------------  PROJECT  ----------------------------------------------------- #
NAME		= so_long

# ------------  DIRECTORIES  ------------------------------------------------- #
LIB				= libftprintfgnl
MINILIBX		= mlx
SRC_PATH		= src/
HEADERS			= includes
HEADERS_LIB		= libftprintfgnl/includes

# ------------  FLAGS  ------------------------------------------------------- #
CFLAGS 		= -I$(HEADERS) -I$(HEADERS_LIB) -I$(MINILIBX) -Werror -Wextra -Wall -fsanitize=address
CC			= @cc
RM			= rm -rf
OPENGL		= -Lmlx -lmlx -lXext -lX11 -lm -lbsd
# ------------  SOURCE FILES  ------------------------------------------------ #
SRC 		= 	main.c checking.c drawing.c

# ------------  FILEPATHS  --------------------------------------------------- #
OBJS				= ${SRC:.c=.o}
OBJS_DIR			= objs
DIRS				= objs
_OBJS				= $(addprefix $(OBJS_DIR)/, $(OBJS))

all: lib minimlx $(NAME)

lib:
			@echo "$(COLOUR_CYAN)Compilation LPG..."
			make -C $(LIB)
			@echo "$(COLOUR_YELLOW)Fin de la compilation LPG $(COLOUR_END)"

minimlx:
			echo "$(COLOUR_CYAN)Compilation mlx..."
			make -C $(MINILIBX)
			@echo "$(COLOUR_YELLOW)Fin de la compilation MLX $(COLOUR_END)"

$(NAME): $(_OBJS)
			@echo "$(COLOUR_CYAN)Compile..."
			$(CC) $(_OBJS) $(CFLAGS) -o $@ -L libftprintfgnl  -lft $(OPENGL)
			@echo "$(COLOUR_RED)${NAME} ready. $(COLOUR_END)"

$(OBJS_DIR)/%.o: $(SRC_PATH)/%.c
		@mkdir -p $(DIRS)
		${CC} $(CFLAGS) -c $< -o $@ -g3

clean:
			$(RM) ${_OBJS} ${OBJS_DIR}
			make fclean -C $(LIB)
			make clean -C $(MINILIBX)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: re ignore fclean clean all $(NAME)