PROGRAM_NAME   = cub3d
CC     = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCLOC = src
UTILSLOC = utils
LIBFT_A = libft/libft.a
LINUX_MINIMLX_A = minilibx-linux/libmlx_Linux.a  -lX11 -lXext -lm
MACOS_MINIMLX_A = minilibx/libmlx.a -framework OpenGL -framework AppKit
DEBUG_FLAGS = -fsanitize=address,undefined -Werror=address -Wnull-dereference -g

MINIMLX_A =
OS = $(shell uname -s)

ifeq ($(OS), Linux)
	MINIMLX_A +=$(LINUX_MINIMLX_A)
else ifeq ($(OS), Darwin)
	MINIMLX_A +=$(MACOS_MINIMLX_A)
endif

SRCS = $(SRCLOC)/main.c $(SRCLOC)/init.c $(SRCLOC)/error.c $(SRCLOC)/events.c $(SRCLOC)/clean.c $(SRCLOC)/validation.c \
	   $(SRCLOC)/validation_utils.c $(SRCLOC)/validation_utils2.c $(SRCLOC)/render.c $(SRCLOC)/validation_utils3.c \
	   $(SRCLOC)/rendering_utils.c $(SRCLOC)/init2.c $(SRCLOC)/events2.c $(SRCLOC)/rendering_utils2.c $(SRCLOC)/rendering_utils3.c \
	   $(SRCLOC)/rendering_utils4.c

OBJS       = $(SRCS:.c=.o)

all: libft libmlx $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MINIMLX_A) -o $(PROGRAM_NAME)

debug: re libft libmlx $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(OBJS) $(LIBFT_A) $(MINIMLX_A) -o $(PROGRAM_NAME)

libft_all:
	cd libft ; make

libft:
	cd libft ; make

libft_clean:
	cd libft ; make clean

libft_fclean:
	cd libft ; make fclean

libft_re: libft_clean
	cd libft ; make re

libmlx:
 ifeq ($(OS), Linux)
	cd minilibx-linux ; make
 else ifeq ($(OS), Darwin)
	cd minilibx ; make
 endif
libmlx_clean:
 ifeq ($(OS), Linux)
	cd minilibx-linux ; make clean
 else ifeq ($(OS), Darwin)
	cd minilibx ; make clean
 endif

clean: libft_clean libmlx_clean
	cd libft && make clean
	$(RM) $(OBJS)

fclean: libft_fclean clean
	cd libft && make fclean
	$(RM) $(OBJS) $(PROGRAM_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re libft libft_clean libft_fclean libft_re libmlx libmlx_clean
