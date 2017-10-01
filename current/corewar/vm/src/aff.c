/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 16:51:54 by hstander          #+#    #+#             */
/*   Updated: 2017/09/13 15:33:55 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

int			ft_pow(int num, int power)
{
	int		pow;

	pow = 1;
	while (power > 0)
	{
		pow *= num;
		power--;
	}
	return (pow);
}

int			oct_to_dec(int octet)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (octet > 0)
	{
		ret += (octet % 10) * ft_pow(8, i);
		i++;
		octet /= 10;
	}
	return (ret);
}

void		ft_aff(t_vm *vm, t_champ *champ)
{
	int				c_pc;
	int				arg1;

	c_pc = champ->pc + 2;
	c_pc = mem_check(c_pc);
	champ->exec_cycle = g_op_tab[15].no_cycles;
	arg1 = vm->mem[c_pc++];
	champ->pc = mem_check(c_pc);
	ft_printf("%c\n", (oct_to_dec(champ->reg[arg1]) % 256));
}
