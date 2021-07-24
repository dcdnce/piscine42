sources = main.c ft_display_file.c
OBJS = $(sources:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean
