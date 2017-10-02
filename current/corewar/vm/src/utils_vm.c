/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_untils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 11:45:26 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/11 16:11:40 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

/*
**  Frees all malloced champion structs and the malloced vm
*/

void				free_structs(t_champ **head, t_vm **vm)
{
	t_champ			*champ_temp;

	while (*head)
	{
		champ_temp = (*head)->next;
		free(*head);
		*head = champ_temp;
	}
	free(*vm);
}

/*
**  Swops the bytes of a passed argument int
*/

int					swop_bytes(int i, int no_bytes)
{
	if (no_bytes == 4)
	{
		i = (i >> 24 & 0xFF) | (i >> 8 & 0xFF00) |
			(i << 8 & 0xFF0000) | (i << 24 & 0xFF0000);
	}
	return (i);
}

/*
**	Prints program usage and exits
*/

void				print_usage_exit(void)
{
	ft_printf("Usage with max %i champs: ./corewar <champ1.cor> <...>\n",
			MAX_PLAYERS);
	ft_printf("    -dump <nbr_cycles> - dumps memory after nbr_cycles\n");
	ft_printf("    -n <player_nbr> - assigns the next player player_nbr\n");
	exit(0);
}

/*
**	Reads basic global info into a t_info struct
*/

void				read_main_info(char **argv, t_champ *champ_head,
						t_vm *vm, t_info *info)
{
	int				ctr;

	ctr = 0;
	while (argv[ctr])
		ctr++;
	info->ac = ctr;
	info->av = argv;
	info->champ_head = champ_head;
	info->vm = vm;
	info->p_num = 0;
	info->vm->dump_cycle = 0;
	info->champ_head->player_num = 0;
}

/*
**	Prints error message, frees malloc memory and exits
*/

void				unable_to_open(t_info *info, int ctr)
{
	ft_printf("Unable to open file %s - exiting\n", info->av[ctr]);
	free_structs(&(info->champ_head), &(info->vm));
	free(info);
	exit(0);
}
