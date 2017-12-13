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

NAME =	libft.a
INCL =	-I ../includes

SRCS =	ft_isprint.c	ft_memset.c			ft_strcat.c		\
		ft_striteri.c	ft_tolower.c		ft_itoa.c		\
		ft_putchar.c	ft_strchr.c			ft_strnew.c		\
		ft_toupper.c	ft_memalloc.c		ft_putchar_fd.c	\
		ft_strclr.c		ft_strlcat.c		ft_strnstr.c	\
		ft_bzero.c		ft_putendl.c		ft_strcmp.c		\
		ft_strlen.c		ft_strrchr.c		ft_memchr.c		\
		ft_strcpy.c		ft_strmap.c			ft_strsplit.c	\
		ft_isalnum.c	ft_memcmp.c			ft_putnbr.c		\
		ft_strdel.c		ft_putnbr_fd.c		ft_strstr.c		\
		ft_isalpha.c	ft_memcpy.c			ft_strncat.c	\
		ft_strsub.c		ft_isascii.c		ft_memdel.c		\
		ft_strequ.c		ft_strncmp.c		ft_strtrim.c	\
		ft_isdigit.c	ft_putstr_fd.c		ft_striter.c	\
		ft_strncpy.c	ft_strtrim_char.c	ft_countint.c	\
		ft_wordlen.c	ft_lstnew.c			ft_putendl_fd.c	\
		ft_lstdelone.c	ft_lstdel.c			ft_lstadd.c		\
		ft_lstiter.c	ft_strnequ.c		ft_strjoin.c	\
		ft_memccpy.c	ft_atoi.c			ft_countwords.c	\
		ft_strmapi.c	ft_strdup.c			ft_putstr.c		\
		ft_memmove.c	ft_pow.c 			ft_strrev.c		\
		ft_lstmap.c		ft_skipspace.c 		ft_arrayrev.c	\
		ft_get_line.c

OBJS =	$(SRCS:c=o)

GR = \033[1;32m # green
LB = \033[1;34m # light blue
NC = \033[0m   # no Color

all:	$(NAME)

$(NAME):
	@cd srcs; $(CC) $(INCL) -c $(SRCS)
	@cd srcs; ar -rc $(NAME) $(OBJS)
	@cd srcs; ranlib $(NAME)
	@mkdir -p objs
	@cd srcs; mv $(OBJS) ../objs
	@cd srcs; mv $(NAME) ../
	@echo "Completed $(GR)[Libft build]$(NC)"

clean:
	@rm -rf objs
	@rm -rf $(NAME)
	@echo "Completed $(LB)[Libft clean]$(NC)"

re: clean all
