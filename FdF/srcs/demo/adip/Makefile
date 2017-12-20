# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/05 13:18:57 by adippena          #+#    #+#              #
#    Updated: 2016/06/05 15:13:01 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRC			=	src/main.c				\
				src/objects.c			\
				src/transformations.c	\
				src/rotate_object.c		\
				src/draw.c				\
				src/normalize.c			\
				src/hooks.c				\
				src/draw_line.c

CFLAGS		=	-Wall -Wextra -Werror #-g3
INCLUDES	=	-I includes
LIBFT		=	-I libft/includes -L libft -lft -I ../../mlx \
				-L ../../mlx -lmlx -framework OpenGL -framework AppKit
MINILIBX	=	-lmlx

all: $(NAME)

$(NAME):
	cd libft; make all
	gcc $(CFLAGS) $(INCLUDES) $(SRC) $(MINILIBX) $(LIBFT) -o $(NAME) -lm

clean:
	cd libft; make clean

fclean: clean
	cd libft; make fclean
	rm -f $(NAME)

re: fclean all

run:
	rm -f $(NAME)
	@$(MAKE) all
	@clear
	@./$(NAME) ../input/42.fdf
