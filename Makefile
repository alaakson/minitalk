NAME_CLIENT = client
NAME_SERVER = server

SOURCES = client.c server.c utils.c
OBJS = $(SOURCES:.c=.o)

CFLAGS = -Werror -Wextra -Wall -I$(PRINTF)/headers
CC = gcc
LDFLAGS = -L$(PRINTF) -lftprintf

PRINTF = ft_printf

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): client.o utils.o
	@make -C $(PRINTF)
	$(CC) $(CFLAGS) client.o utils.o $(LDFLAGS) -o $(NAME_CLIENT)

$(NAME_SERVER): server.o utils.o
	@make -C $(PRINTF)
	$(CC) $(CFLAGS) server.o utils.o $(LDFLAGS) -o $(NAME_SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.o
	@make -C $(PRINTF) clean
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@make -C $(PRINTF) fclean
	@echo "All cleaned."

re: fclean all

.PHONY: all clean fclean re
