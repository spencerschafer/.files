# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sschafer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 15:01:03 by sschafer          #+#    #+#              #
#    Updated: 2017/12/07 13:25:27 by sschafer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf
INCL_FDF = -I ../includes
INCL_LIBFT = -I ../libft/includes -L ../libft -lft
INCL_MLX = -I includes -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

SRCS =	*.c
OBJS =	$(SRCS:c=o)

GR = \033[1;32m # green
LB = \033[1;34m # light blue
NC = \033[0m   # no Color

all:	$(NAME)

$(NAME):
	@cd srcs; cd mlx; make -s all
	@cd libft;  make all
	@cd srcs; $(CC) $(INCL_FDF) $(INCL_MLX) $(INCL_LIBFT) $(SRCS) -o $(NAME)  
	@cd srcs;  mv $(NAME) ../
	@echo "Completed $(GR)[FdF build]$(NC)"

clean:
	@cd srcs; cd mlx; make clean
	@cd libft; make clean
	@rm -rf $(NAME)
	@echo "Completed $(LB)[FdF clean]$(NC)"

re: clean all
