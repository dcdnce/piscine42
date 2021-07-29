sources = ft_doop.c ft_tools.c ft_ops.c
OBJS = $(sources:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean
