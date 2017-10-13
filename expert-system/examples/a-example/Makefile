# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/10/15 14:35:51 by arnovan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	exp_sys
INCLUDE		=	-I includes
CFLAGS		=	-Wall -Wextra -Werror -g $(INCLUDE)
LFLAGS		=	$(INCLUDE)
CC			=	gcc
LD			=	gcc 

INC			=	includes/ex_system.h

SRC			=	srcs/ex_system.c			\
				srcs/ft_read_file.c			\
				srcs/ft_strnew.c			\
				srcs/ft_eval_brackets.c		\
				srcs/ft_read_file_extras.c	\
				srcs/ft_validate.c			\
				srcs/ft_eval_cond.c			\
				srcs/ft_solve_for.c			\
				srcs/operations.c

OBJ			=	$(SRC:srcs/%.c=build/%.o)

all: exp_sys

build/%.o: srcs/%.c $(INC)
	@echo "\033[92m    CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

exp_sys: $(OBJ)
	@echo "\033[92m    LD    $(NAME)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME)

clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -rf build

fclean: clean
	@echo "\033[92m    RM    $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re: fclean all
