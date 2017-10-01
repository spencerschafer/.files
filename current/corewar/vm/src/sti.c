/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:51:54 by hstander          #+#    #+#             */
/*   Updated: 2017/09/13 15:36:14 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

static void	ft_to_mem(int arg1, int arg2, t_champ *champ, t_vm *vm)
{
	int		c_pc;

	c_pc = champ->pc;
	vm->mem[mem_check(c_pc++ + (arg2 % IDX_MOD))] = (arg1 & 0xff000000) >> 24;
	vm->mem[mem_check(c_pc++ + (arg2 % IDX_MOD))] = (arg1 & 0x00ff0000) >> 16;
	vm->mem[mem_check(c_pc++ + (arg2 % IDX_MOD))] = (arg1 & 0x0000ff00) >> 8;
	vm->mem[mem_check(c_pc++ + (arg2 % IDX_MOD))] = (arg1 & 0xff0000ff);
}

static int	ft_get_arg(unsigned char dec, int *c_pc, t_vm *vm, t_champ *champ)
{
	int				arg;
	int				tmp;
	unsigned char	temp[2];

	if (dec == 1)
		arg = ft_reg(vm, c_pc, champ);
	else if (dec == 2)
		arg = ft_indirect(vm, c_pc);
	else
	{
		tmp = ft_indirect(vm, c_pc);
		temp[0] = (vm->mem[mem_check(champ->pc + (tmp % IDX_MOD))]);
		temp[1] = (vm->mem[mem_check((champ->pc + 1) + (tmp % IDX_MOD))]);
		arg = to_signed_ind(temp);
	}
	return (arg);
}

void		ft_sti(t_vm *vm, t_champ *champ)
{
	int				c_pc;
	unsigned char	dec[4];
	int				arg1;
	int				arg2;
	int				arg3;

	c_pc = champ->pc + 1;
	c_pc = mem_check(c_pc);
	champ->exec_cycle = g_op_tab[10].no_cycles;
	ft_decode(vm->mem[c_pc++], dec);
	c_pc = mem_check(c_pc);
	arg1 = ft_reg(vm, &c_pc, champ);
	arg2 = ft_get_arg(dec[1], &c_pc, vm, champ);
	arg3 = ft_get_arg(dec[2], &c_pc, vm, champ);
	ft_to_mem(arg1, (arg2 + arg3), champ, vm);
	champ->pc = c_pc;
}
