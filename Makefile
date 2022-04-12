# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 15:08:35 by ablaamim          #+#    #+#              #
#    Updated: 2022/04/11 17:51:14 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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

OBJ = $(patsubst %.c,%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:	%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) 

fclean:	clean
	$(RM) push_swap

re: fclean all

.PHONY: all clean fclean re
