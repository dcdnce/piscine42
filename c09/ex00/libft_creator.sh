#!/bin/sh
gcc -c -Wall -Wextra -Werror ft_*.c
ar -rcs libft.a ft*.o

