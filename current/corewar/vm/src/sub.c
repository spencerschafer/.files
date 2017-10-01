/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:51:54 by hstander          #+#    #+#             */
/*   Updated: 2017/09/13 15:36:23 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

void		ft_sub(t_vm *vm, t_champ *champ)
{
	int				c_pc;
	int				arg1;
	int				arg2;
	int				arg3;

	c_pc = champ->pc + 2;
	c_pc = mem_check(c_pc);
	champ->exec_cycle = g_op_tab[4].no_cycles;
	arg1 = vm->mem[c_pc++];
	c_pc = mem_check(c_pc);
	arg2 = vm->mem[c_pc++];
	c_pc = mem_check(c_pc);
	arg3 = vm->mem[c_pc++];
	c_pc = mem_check(c_pc);
	if ((champ->reg[arg3] = champ->reg[arg1] - champ->reg[arg2]))
		champ->carry = 0;
	else
		champ->carry = 1;
	champ->pc = c_pc;
}
