/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:46:38 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/11 16:02:57 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

void			check_dump_cycle(t_champ *champ_head, t_vm *vm)
{
	if (vm->dump_cycle != 0 && vm->total_cycles >= vm->dump_cycle)
	{
		print_memory((void *)&vm->mem, MEM_SIZE, 64);
		free_structs(&champ_head, &vm);
		exit(0);
	}
}
