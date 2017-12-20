# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/27 18:18:00 by etermeau          #+#    #+#              #
#    Updated: 2015/01/03 12:25:24 by etermeau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

#PATH_SRC = ./

#PATH_OBJ = ./

#PATH_INC = ./libft/Includes/

#CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes/

LIBFT		=	-I libft/Includes -L libft -lft \
				-I ../../mlx	-L ../../mlx -lmlx \
			   	-framework OpenGL -framework AppKit

SRC = srcs/main.c \
	  srcs/ft_erreur.c \
	  srcs/ft_info.c \
	  srcs/ft_fdf.c \
	  srcs/ft_draw.c 

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): #$(OBJ) $(HEAD)
	cd libft; make all	
	gcc $(CFLAGS) $(INCLUDES) $(SRC) -lmlx $(LIBFT) -o $(NAME) -lm
	#$(CC) -o $(NAME) $(OBJ)	 -I ../../../mlx -L /../../../mlx -lmlx \
		-framework OpenGL -framework AppKit 

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
