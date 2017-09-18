# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/13 13:39:56 by gvan-roo          #+#    #+#              #
#    Updated: 2017/09/14 08:20:25 by gvan-roo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_A		=	asm

SDIR_A		=	./assembler/src
ODIR_A		=	./assembler/obj
IDIR_A		=	./assembler/headers
CFLAGS_A	=	-I$(IDIR_A)
LDIR		=	./libft
LIBS_A		=	-lft

_DEPS_A		=	asm.h op.h
DEPS_A		=	$(patsubst %,$(IDIR_A)/%,$(_DEPS_A))

_OBJ_A		=	asm_main.o\
				check.o\
				list.o\
				extras.o\
				parse_line.o\
				free.o\
				label_offset.o\
				name_comment.o\
				init.o\
				op.o\
				st.o\
				and.o\
				or.o\
				xor.o\
				find_offset.o\
				ld.o\
				zjmp.o\
				ldi.o\
				sti.o\
				ft_fork.o\
				lld.o\
				lldi.o\
				lfork.o\
				add.o\
				sub.o\
				live.o\
				aff.o\
				error.o\
				extras2.o
OBJ_A		=	$(patsubst %,$(ODIR_A)/%,$(_OBJ_A))


NAME_C		=	corewar

SDIR_C		=	./vm/src
ODIR_C		=	./vm/obj
IDIR_C		=	./vm/headers
CFLAGS_C	=	-I$(IDIR_C)
LIBS_C		=	-lft -lncurses

_DEPS_C		=	vm.h
DEPS_C		=	$(patsubst %,$(IDIR_C)/%,$(_DEPS_C))

_OBJ_C		=	vm_main.o\
				open_files.o\
				read_champs.o\
				print_mem.o\
				print_ncurses.o\
				init_vm.o\
				print_champ_mem.o\
				st.o\
				run_machine_run.o\
				op.o\
				utils_vm.o\
				utils2_vm.o\
				add.o\
				sub.o\
				and.o\
				or.o\
				xor.o\
				zjmp.o\
				extras.o\
				ldi.o\
				sti.o\
				fork.o\
				lldi.o\
				lfork.o\
				aff.o\
				ld.o\
				lld.o					
OBJ_C		=	$(patsubst %,$(ODIR_C)/%,$(_OBJ_C))

all:	$(NAME_A) $(NAME_C)

$(ODIR_A)/%.o:	$(SDIR_A)/%.c
	@mkdir -p $(ODIR_A)
	gcc -c -o $@ $< $(CFLAGS_A)

$(NAME_A):	$(OBJ_A)
	make -C $(LDIR) re
	gcc -o $@ $^ $(CFLAGS_A) -L$(LDIR) $(LIBS_A)

$(ODIR_C)/%.o:	$(SDIR_C)/%.c
	@mkdir -p $(ODIR_C)
	gcc -c -o $@ $< $(CFLAGS_C)

$(NAME_C):	$(OBJ_C)
	gcc -o $@ $^ $(CFLAGS_C) -L$(LDIR) $(LIBS_C)

.PHONY:	clean fclean re
clean:
	rm -f $(ODIR_C)/*.o $(ODIR_A)/*.o
	make -C $(LDIR) clean
fclean:	clean
	rm -f $(NAME_C) $(NAME_A)
	make -C $(LDIR) fclean
re:	fclean
	make
