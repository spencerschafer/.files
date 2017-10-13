# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/22 22:05:05 by sasiedu           #+#    #+#              #
#*   Updated: 2016/10/02 12:39:03 by sasiedu          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell ls | grep '.c')

BIN = $(SRC:.c=.o)

HEAD = libft

CC = gcc

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo "	Libft: \033[36mCreating bin files\033[0m"
	@ $(CC) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(BIN)
	@ranlib $(NAME)
	@echo "	Libft: \033[36mCompiled Successfully\033[0m"

clean:
	@echo "	Libft: \033[33mCleaning .o files\033[0m"
	@rm -rf $(BIN)

fclean: clean
	@echo "	Libft: \033[33mFcleaning\033[0m"
	@rm -rf $(NAME)

re: fclean all
