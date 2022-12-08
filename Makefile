# -*- MakeFile -*-

NAME = fractol
OS := $(shell uname)
# -*- Compiler -*-
GCC = gcc
FLAGS = -Wall -Wextra -Werror -Imlx -O3

# -*- Includes -*-
SRC_PATH = src
OBJ_PATH = obj
LIBFT = libft
INCL = incl
MLX_MACOS = mlx_macos
MLX_LINUX = mlx_linux

# -*- Source Files -*-
SRC =	main.c \
		draw.c \
		init.c \
		controls_keyboard.c \
		controls_mouse.c \
		utils.c \
		mandelbrot.c \
		julia.c \
		burningship.c \

# -*- Objects -*-
SRCS=$(addprefix $(SRC_PATH)/,$(SRC))
OBJS=$(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: lib tmp $(NAME)

tmp:
	@mkdir -p obj

ifeq ($(OS), Linux)
# -*- Linux -*-
lib:
	make -C $(LIBFT)
	make -C $(MLX_LINUX)
	cp $(MLX_LINUX)/libmlx.dylib .
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(GCC) $(FLAGS) -c -o $@ $^

$(NAME): $(OBJS) $(LIBFT)/libft.a
	$(GCC) $(FLAGS) $(OBJS) $(LIBFT)/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
else
# -*- MacOS -*-
lib:
	make -C $(LIBFT)
	make -C $(MLX_MACOS)
	cp $(MLX_MACOS)/libmlx.dylib .

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(GCC) $(FLAGS) -D M_OS=MACOS -c -o $@ $^

$(NAME): $(OBJS) $(LIBFT)/libft.a
	$(GCC) $(FLAGS) $^ -L $(LIBFT) -Lmlx_macos -lmlx -framework OpenGL -framework AppKit  -lz -lm -O3 -o $(NAME)
endif

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_PATH)

fclean:
	make clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)
	rm -f libmlx.dylib
	rm -f src/libmlx.dylib


re:	fclean all


.PHONY: temporary, re, fclean, clean