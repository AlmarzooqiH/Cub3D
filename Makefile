NAME   = cub3D
CC     = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCLOC = src
UTILSLOC = utils
LIBFT_A = libft/libft.a

SRCS = $(SRCLOC)/name.c main.c\
		$(UTILSLOC)/name.c \

OBJS       = $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJS) -o $(NAME)

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

clean:
	cd libft && make clean
	$(RM) $(OBJS)

fclean:
	cd libft && make fclean
	$(RM) $(OBJS) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re libft libft_clean libft_fclean libft_re
