# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 15:08:35 by ablaamim          #+#    #+#              #
#    Updated: 2022/04/19 11:53:53 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER = ./includes/push_swap.h

SRC = ./sources/main.c \
	  ./sources/ft_args_unified.c \
	  ./sources/lib_utils.c \
	  ./sources/ft_split_and_array_free.c \
	  ./sources/ft_parser.c \
	  ./sources/lib_utils_1.c \
	  ./sources/lib_mem_utils.c \
	  ./sources/exit.c \
	  ./sources/ft_printf.c \
	  ./sources/debug.c \
	  ./sources/ft_stacks_constructor.c \
	  ./sources/ft_algorithm.c \
	  ./sources/ft_operations.c \
	  ./sources/ft_swap.c \
	  ./sources/ft_small_list_sort.c \
	  ./sources/ft_rotate.c \
	  ./sources/ft_reverse_rotate.c \
	  ./sources/ft_min_max_utils.c \
	  ./sources/ft_markup_elements.c \
	  ./sources/ft_orthodox.c \
	  ./sources/push.c \
	  ./sources/ft_optimize.c \
	  ./sources/ft_attribute_and_operate.c \
	  ./sources/ft_regularize_stack_a.c 

SRC_B = ./sources/ft_args_unified.c \
	  ./sources/lib_utils.c \
	  ./sources/ft_split_and_array_free.c \
	  ./sources/ft_parser.c \
	  ./sources/lib_utils_1.c \
	  ./sources/lib_mem_utils.c \
	  ./sources/exit.c \
	  ./sources/ft_printf.c \
	  ./sources/debug.c \
	  ./sources/ft_stacks_constructor.c \
	  ./sources/ft_algorithm.c \
	  ./sources/ft_operations.c \
	  ./sources/ft_swap.c \
	  ./sources/ft_small_list_sort.c \
	  ./sources/ft_rotate.c \
	  ./sources/ft_reverse_rotate.c \
	  ./sources/ft_min_max_utils.c \
	  ./sources/ft_markup_elements.c \
	  ./sources/ft_orthodox.c \
	  ./sources/push.c \
	  ./sources/ft_optimize.c \
	  ./sources/ft_attribute_and_operate.c \
	  ./sources/ft_regularize_stack_a.c \
	  ./sources/get_next_line.c \
	  ./sources/checker_bonus.c

OBJ = $(patsubst %.c,%.o,$(SRC))

OBJ_B = $(patsubst %.c,%.o,$(SRC_B))

all : $(NAME)

bonus : $(NAME_B)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(NAME_B) : $(OBJ_B)
	$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_B)

%.o:	%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) 

fclean:	clean
	$(RM) push_swap

re: fclean all

.PHONY: all clean fclean re bonus
