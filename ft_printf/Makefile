NAME = libftprintf.a

CC = cc
SRC = ft_print_hex.c \
		ft_print_i_d.c \
		ft_print_p.c \
		ft_print_u.c \
		ft_printf.c \
		ft_print_utils.c  

O_FILES = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(O_FILES)
	ar -rcs $(NAME) $(O_FILES)

%.o: %.c
	$(CC)	$(CFLAGS)  -c $< -o $@

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
