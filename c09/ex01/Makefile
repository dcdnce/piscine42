sources = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS = ${sources:.c=.o}
HEAD = -I includes
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

.c.o:
	${CC} ${CFLAGS} -c $(HEAD) $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs $@ $^

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean: clean 
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
