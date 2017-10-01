/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champ_mem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:14:45 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/11 15:26:11 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

/*
**	Function for printing out the current state of the vm.
**	in Ncurses Mode.
*/

void				print_vm_nc(t_vm vm, int bit)
{
	initscr();
	move(0, 0);
	printw("Deluxe Virtual Machine Current State :   ");
	printw("Current cycle :%i   ", vm.cur_cycle);
	printw("Cycle to die  :%i   ", vm.cycle_to_die);
	printw("Cycle delta   :%i   \n", vm.cycle_delta);
	refresh();
	print_mem_nc((void *)&vm.mem, MEM_SIZE, bit);
}

/*
**	Function for printing out the current state of the vm.
**	For debugging and testing like dump cycle etc.
*/

void				print_vm(t_vm vm, int bit)
{
	ft_printf("Deluxe Virtual Machine Current State :\n\n");
	ft_printf("Current cycle :%i\n", vm.cur_cycle);
	ft_printf("Cycle to die  :%i\n", vm.cycle_to_die);
	ft_printf("Cycle delta   :%i\n", vm.cycle_delta);
	print_memory((void *)&vm.mem, MEM_SIZE, bit);
}

/*
**	Prints out champ variables. Testing and debug function
*/

void				print_champ(t_champ *champ_ptr)
{
	int				ctr;

	while (champ_ptr)
	{
		ctr = 0;
		ft_printf("Player num               :%i\n", champ_ptr->player_num);
		ft_printf("Program name             :%s\n", champ_ptr->head.prog_name);
		ft_printf("Program size             :%i\n", champ_ptr->head.prog_size);
		ft_printf("Program comment          :%s\n", champ_ptr->head.comment);
		ft_printf("Program alive?           :%i\n", champ_ptr->alive);
		ft_printf("Program called alive?    :%i\n", champ_ptr->called_alive);
		ft_printf("Prog carry               :%i\n", champ_ptr->carry);
		ft_printf("Prog pc                  :%i\n", champ_ptr->pc);
		ft_printf("Prog next cycle          :%i\n", champ_ptr->exec_cycle);
		while (++ctr < 17)
			ft_printf("Reg[%i]              :%i\n", ctr, champ_ptr->reg[ctr]);
		ft_printf("Program binary:\n");
		print_memory((void *)&champ_ptr->prog, champ_ptr->head.prog_size, 32);
		champ_ptr = champ_ptr->next;
	}
}
