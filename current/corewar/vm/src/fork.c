/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:51:54 by hstander          #+#    #+#             */
/*   Updated: 2017/09/14 08:22:03 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

void		ft_fork(t_vm *vm, t_champ *champ)
{
	int				c_pc;
	int				arg1;
	unsigned char	temp[2];
	t_champ			*new_champ;

	new_champ = (t_champ *)ft_memalloc(sizeof(t_champ));
	champ->exec_cycle = g_op_tab[11].no_cycles;
	init_champ(champ, new_champ);
	c_pc = champ->pc + 1;
	c_pc = mem_check(c_pc);
	temp[0] = (0x00ff & vm->mem[c_pc++]);
	c_pc = mem_check(c_pc);
	temp[1] = (0x00ff & vm->mem[c_pc++]);
	c_pc = mem_check(c_pc);
	arg1 = to_signed_ind(temp);
	new_champ->pc = mem_check(champ->pc + (arg1 % IDX_MOD));
	champ->pc = c_pc;
	while (champ->next)
		champ = champ->next;
	champ->next = new_champ;
}
