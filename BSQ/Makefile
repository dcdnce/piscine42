sources = $(wildcard *.c)
OBJS = $(sources:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

debug: 
	${CC} -g ${sources}

clean:
	rm -f $(OBJS)
	rm -f stdin.bsq.tmp

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re debug
