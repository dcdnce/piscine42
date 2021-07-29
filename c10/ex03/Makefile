sources = $(wildcard *.c)
OBJS = $(sources:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_hexdump

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

debug: $(OBJS)
	$(CC) $(CFLAGS) -g $^ 

re: fclean all

.PHONY: all clean fclean re
