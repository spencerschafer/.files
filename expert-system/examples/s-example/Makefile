#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/10/02 11:43:03 by sasiedu           #+#    #+#             *#
#*   Updated: 2016/10/02 23:26:57 by sasiedu          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = expert_system

SRC = main.c and.c not.c or.c xor.c fact.c kb.c rules.c tools.c \
	  work_memory.c logic.c rhs.c logic2.c questions.c ask.c reason.c \
	  print.c why.c what.c statement.c read_file.c read_tools.c rules2.c \
	  verify_rules.c verify_rules1.c

BIN = $(SRC:.c=.o)

CC = clang

FLAGS = -Wall -Wextra -Werror

INC = -I ./include/

LIB = -L ./libft/ -lft 


all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@echo "	$(NAME): \033[31mCreating bin files\033[0m"
	@$(CC) $(FLAGS) $(INC) -c $(SRC)
	@$(CC) -o $(NAME) $(BIN) $(INC) $(LIB)
	@ echo "	$(NAME): \033[31mCompiled\033[0m"

clean:
	@echo "	$(NAME): \033[33mCleaning .o files\033[0m"
	@make -C libft/ clean
	@rm -rf $(BIN)

fclean:
	@echo "	$(NAME): \033[33mCleaning .o files\033[0m"
	@echo "	$(NAME): \033[33mFcleaning binary file\033[0m"
	@make -C libft/ fclean
	@rm -rf $(BIN)
	@rm -rf $(NAME)

re: fclean all
	@echo "	$(NAME): \033[33mRe done\033[0m"
