#!/bin/sh
make -C libft fclean
make -C libft
gcc -Wall -Wextra -Werror -I libft/includes/ -c get_next_line.c -g
gcc -Wall -Wextra -Werror -I libft/includes/ -c main.c -g
gcc -o test_gnl get_next_line.o main.o -L libft/ -lft -g
