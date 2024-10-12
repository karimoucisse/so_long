NAME = so_long
CC = cc
SRC = src/
UTILS = utils/
CFLAGS = -Wall -Werror -Wextra
GNL = gnl/
LIBFT = libft/
GNL_FILES = $(GNL)get_next_line_utils.c  $(GNL)get_next_line.c
LIBFT_FILES = $(LIBFT)ft_substr.c $(LIBFT)ft_strjoin.c $(LIBFT)ft_strtrim.c $(LIBFT)ft_split.c $(LIBFT)ft_itoa.c\
	$(LIBFT)ft_putendl_fd.c $(LIBFT)ft_putchar_fd.c $(LIBFT)ft_putstr_fd.c $(LIBFT)ft_putnbr_fd.c\
	$(LIBFT)ft_strmapi.c $(LIBFT)ft_striteri.c $(LIBFT)ft_isalnum.c $(LIBFT)ft_isalpha.c\
	$(LIBFT)ft_isascii.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_isprint.c $(LIBFT)ft_strlen.c  $(LIBFT)ft_tolower.c\
	$(LIBFT)ft_toupper.c $(LIBFT)ft_strchr.c $(LIBFT)ft_strrchr.c $(LIBFT)ft_strncmp.c $(LIBFT)ft_strnstr.c\
	$(LIBFT)ft_atoi.c $(LIBFT)ft_strlcpy.c $(LIBFT)ft_strlcat.c $(LIBFT)ft_strdup.c $(LIBFT)ft_bzero.c\
	$(LIBFT)ft_memset.c $(LIBFT)ft_memcpy.c $(LIBFT)ft_memchr.c $(LIBFT)ft_memcmp.c\
	$(LIBFT)ft_memmove.c $(LIBFT)ft_calloc.c
CFILES = $(SRC)so_long.c $(SRC)check_map1.c $(SRC)check_map2.c $(SRC)$(UTILS)utils.c\
		$(SRC)$(UTILS)utils2.c $(SRC)$(UTILS)utils3.c $(SRC)$(UTILS)utils4.c\
		$(SRC)handle_game_assets.c $(SRC)move.c $(LIBFT_FILES) $(GNL_FILES)
OFILES = $(CFILES:.c=.o)
RM = rm -f

all: $(NAME)
$(NAME): $(OFILES)
	$(CC) $(OFILES) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@
clean:
	$(RM) $(OFILES)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re

