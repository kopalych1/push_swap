# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostian <akostian@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 14:25:34 by akostian          #+#    #+#              #
#    Updated: 2024/08/13 11:14:49 by akostian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= push_swap

SRCS		= src/main.c \
			  src/parse.c \
			  src/libft.c \
			  src/stack_functions.c \
			  src/stack_functions2.c \
			  src/stack_utils.c \
			  src/find_closest.c \
			  src/calc_cost.c \
			  src/rotate_stacks.c \
			  src/sort_three.c \
			  src/algo.c
INCLUDES	= -Iinclude

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:
	make -C libft/
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) libft/libft.a

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/

	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re