/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 08:34:55 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/13 16:01:50 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

/*
**	Subfunction of count_flags. Checks for correct usage
**	of flags, and if not prints out correct usage, frees
**	struct memory and exits.
*/

void				print_usage_flags(int argc, char **argv, int arg_count)
{
	if (ft_strcmp(argv[argc], "-n") == 0)
	{
		if ((arg_count >= argc + 1) && (ft_atoi(argv[argc + 1]) == 0))
		{
			ft_printf("-n usage: -n <player_number> - exiting\n");
			exit(0);
		}
	}
	else if (ft_strcmp(argv[argc], "-dump") == 0)
	{
		if ((arg_count >= argc + 1) && (ft_atoi(argv[argc + 1]) == 0))
		{
			ft_printf("-dump usage: -dump <num_cycles> - exiting\n");
			exit(0);
		}
	}
}

/*
**	Counts the number of flag arguments, and checks for correct
**	usage with subfunction print_usage.
*/

int					count_flags(int argc, char **argv)
{
	int				ret;
	int				arg_count;

	ret = 0;
	argc--;
	arg_count = argc;
	while (argc > 0)
	{
		if (ft_strcmp(argv[argc], "-n") == 0 ||
				ft_strcmp(argv[argc], "-dump") == 0)
		{
			print_usage_flags(argc, argv, arg_count);
			ret += 2;
		}
		argc--;
	}
	return (ret);
}

/*
**	Finds the struct with the last live call (if any) and prints
**	out the winner
*/

void				find_winner_struct(t_champ *champ_head, int ll)
{
	t_champ			*champ_ptr;

	if (ll == 0)
	{
		ft_printf("No live calls\n");
		return ;
	}
	champ_ptr = champ_head;
	while (champ_ptr && champ_ptr->player_num != ll)
		champ_ptr = champ_ptr->next;
	ft_printf("Player %i (%s) is the winner\n", champ_ptr->player_num,
			champ_ptr->head.prog_name);
}

/*
**	Reverses the champion list as last player plays first
*/

void				reverse_list(t_champ **champ_head)
{
	t_champ			*champ_ptr;
	t_champ			*new_head;

	new_head = *champ_head;
	while (new_head->next)
		new_head = new_head->next;
	while (1)
	{
		champ_ptr = *champ_head;
		while (champ_ptr->next && champ_ptr->next->next)
			champ_ptr = champ_ptr->next;
		if (champ_ptr == *champ_head)
		{
			if (champ_ptr->next)
				champ_ptr->next->next = champ_ptr;
			champ_ptr->next = NULL;
			break ;
		}
		champ_ptr->next->next = champ_ptr;
		champ_ptr->next = NULL;
	}
	*champ_head = new_head;
}

int					main(int argc, char **argv)
{
	t_champ			*champ_head;
	t_vm			*vm;
	t_info			*info;

	if (argc - count_flags(argc, argv) < 2 ||
			(argc - count_flags(argc, argv)) > MAX_PLAYERS + 1)
		print_usage_exit();
	champ_head = ft_memalloc(sizeof(t_champ));
	vm = ft_memalloc(sizeof(t_vm));
	info = ft_memalloc(sizeof(t_info));
	read_main_info(argv, champ_head, vm, info);
	open_files(info);
	free(info);
	init_vm(vm, champ_head, (argc - count_flags(argc, argv)));
	reverse_list(&champ_head);
	run_machine_run(champ_head, vm);
	find_winner_struct(champ_head, vm->last_live);
	free_structs(&champ_head, &vm);
	return (0);
}
