/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:51:54 by hstander          #+#    #+#             */
/*   Updated: 2017/09/13 15:34:54 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

void		ft_lfork(t_vm *vm, t_champ *champ)
{
	int				c_pc;
	int				arg1;
	unsigned char	temp[2];
	t_champ			*new_champ;

	new_champ = (t_champ *)ft_memalloc(sizeof(t_champ));
	c_pc = champ->pc + 1;
	c_pc = mem_check(c_pc);
	champ->exec_cycle = g_op_tab[14].no_cycles;
	temp[0] = (0x00ff & vm->mem[c_pc++]);
	c_pc = mem_check(c_pc);
	temp[1] = (0x00ff & vm->mem[c_pc++]);
	c_pc = mem_check(c_pc);
	arg1 = to_signed_ind(temp);
	if (arg1 == 0)
		champ->carry = 1;
	else
		champ->carry = 0;
	init_champ(champ, new_champ);
	new_champ->pc = mem_check(champ->pc + arg1);
	champ->pc = c_pc;
	while (champ->next)
		champ = champ->next;
	champ->next = new_champ;
}
