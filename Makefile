# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostian <akostian@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 14:25:34 by akostian          #+#    #+#              #
#    Updated: 2024/09/02 04:21:13 by akostian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= push_swap

SRC_DIR		= src
SRCS		= main.c \
			  parse.c \
			  utils.c \
			  strict_atoi.c \
			  stack_functions.c \
			  stack_functions2.c \
			  stack_utils.c \
			  find_closest.c \
			  calc_cost.c \
			  rotate_stacks.c \
			  sort_three.c \
			  algo_min_push.c \
			  algo_turk.c
INCLUDES	= -Iinclude

BUILD_DIR	= build
LIBFT_DIR	= libft
OBJS		= $(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf



all: $(NAME)
#


$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)

	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT_DIR)/libft.a
#


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
#


$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)

	$(CC) $(CFLAGS) -c $< -o $@
#


clean:
	make clean -C $(LIBFT_DIR)

	$(RM) $(BUILD_DIR)
#


fclean:
	make fclean -C $(LIBFT_DIR)

	$(RM) $(BUILD_DIR) $(NAME)
#


re: fclean all
#



.PHONY: all clean fclean re