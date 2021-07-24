sources = main.c ft_tools.c ft_atoi.c
OBJS = $(sources:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_tail

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
