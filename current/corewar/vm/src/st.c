/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:51:54 by hstander          #+#    #+#             */
/*   Updated: 2017/09/13 15:35:38 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

static void	ft_to_mem(t_vm *vm, t_champ *champ, int arg2, int arg1)
{
	int		c_pc;

	c_pc = champ->pc;
	vm->mem[mem_check(c_pc + (arg2 % IDX_MOD))] = (arg1 & 0xff000000) >> 24;
	c_pc++;
	vm->mem[mem_check(c_pc + (arg2 % IDX_MOD))] = (arg1 & 0x00ff0000) >> 16;
	c_pc++;
	vm->mem[mem_check(c_pc + (arg2 % IDX_MOD))] = (arg1 & 0x0000ff00) >> 8;
	c_pc++;
	vm->mem[mem_check(c_pc + (arg2 % IDX_MOD))] = (arg1 & 0x000000ff);
}

void		ft_st(t_vm *vm, t_champ *champ)
{
	int				c_pc;
	unsigned char	dec[4];
	int				arg1;
	int				arg2;

	c_pc = mem_check(champ->pc + 1);
	champ->exec_cycle = g_op_tab[2].no_cycles;
	ft_decode(vm->mem[c_pc++], dec);
	c_pc = mem_check(c_pc);
	arg1 = ft_reg(vm, &c_pc, champ);
	if (dec[1] == 1)
	{
		arg2 = vm->mem[c_pc++];
		mem_check(c_pc);
		champ->reg[arg2] = arg1;
	}
	else
	{
		arg2 = ft_indirect(vm, &c_pc);
		ft_to_mem(vm, champ, arg2, arg1);
	}
	champ->pc = c_pc;
}
