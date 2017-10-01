/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:51:54 by hstander          #+#    #+#             */
/*   Updated: 2017/09/13 15:36:43 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

void		ft_zjmp(t_vm *vm, t_champ *champ)
{
	int				c_pc;
	int				arg1;
	unsigned char	temp[2];

	c_pc = champ->pc + 1;
	c_pc = mem_check(c_pc);
	champ->exec_cycle = g_op_tab[8].no_cycles;
	if (champ->carry == 1)
	{
		temp[0] = (0x00ff & vm->mem[c_pc++]);
		c_pc = mem_check(c_pc);
		temp[1] = (0x00ff & vm->mem[c_pc++]);
		c_pc = mem_check(c_pc);
		arg1 = to_signed_ind(temp);
		champ->pc = mem_check(champ->pc + (arg1 % IDX_MOD));
	}
	else
		champ->pc = mem_check(champ->pc + 3);
}
