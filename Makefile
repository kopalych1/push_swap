# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostian <akostian@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 14:25:34 by akostian          #+#    #+#              #
#    Updated: 2024/07/30 15:06:49 by akostian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= push_swap

SRCS		= src/main.c \
			  src/parse.c \
			  src/libft.c

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