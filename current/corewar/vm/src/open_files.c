/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:17:54 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/11 18:08:43 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

int					get_next_player_number(t_champ *champ_head)
{
	int				ctr;
	t_champ			*champ_ptr;
	int				flag;

	ctr = 1;
	champ_ptr = champ_head;
	while (ctr <= 4)
	{
		flag = 1;
		while (champ_ptr)
		{
			if (ctr == champ_ptr->player_num)
				flag = 0;
			champ_ptr = champ_ptr->next;
		}
		if (flag)
			break ;
		ctr++;
		champ_ptr = champ_head;
	}
	return (ctr);
}

int					check_availible_num(t_champ *champ_head, int nbr)
{
	t_champ			*champ_ptr;

	champ_ptr = champ_head;
	while (champ_ptr)
	{
		if (champ_ptr->player_num == nbr)
		{
			ft_printf("Player number %i already in use -", nbr);
			ft_printf(" system generating a new one\n");
			return (1);
		}
		champ_ptr = champ_ptr->next;
	}
	return (0);
}

static void			handle_flags(t_info *info, int *ctr)
{
	if (ft_strcmp(info->av[*ctr], "-dump") == 0)
	{
		if ((*ctr + 1) < info->ac)
			info->vm->dump_cycle = ft_atoi(info->av[*ctr + 1]);
		*ctr += 2;
	}
	if ((*ctr < info->ac) && ft_strcmp(info->av[*ctr], "-n") == 0)
	{
		if ((*ctr + 1) < info->ac)
		{
			info->p_num = ft_atoi(info->av[*ctr + 1]);
			if (info->p_num < 1 || info->p_num > 4)
			{
				ft_printf("Invalid player number %i - number", info->p_num);
				ft_printf(" must be between 1 and 4. A player number ");
				ft_printf("will be system generated\n");
				info->p_num = get_next_player_number(info->champ_head);
			}
			else if (check_availible_num(info->champ_head, info->p_num))
				info->p_num = get_next_player_number(info->champ_head);
		}
		*ctr += 2;
	}
}

/*
** Checks if a next champ will be needed, and if so
** mallocs a new champ, and moves the pointer to the
** new node. Sets the next pointer to null.
*/

void				malloc_new_champ(t_info *info, int ctr, t_champ **champ_ptr)
{
	if (ctr < info->ac && (ft_strcmp(info->av[ctr], "-dump") != 0 ||
				(ctr + 2) < info->ac))
	{
		(*champ_ptr)->next = ft_memalloc(sizeof(t_champ));
		*champ_ptr = (*champ_ptr)->next;
	}
	(*champ_ptr)->next = NULL;
}

/*
**	Tries to open files passed as arguments to main. If successfull
**	mallocs space for a new champion, and call read function which
**	reads the file info into the champion struct.
*/

void				open_files(t_info *info)
{
	int				ctr;
	int				fd;
	t_champ			*champ_ptr;

	ctr = 1;
	champ_ptr = info->champ_head;
	while (ctr < info->ac)
	{
		if ((ft_strcmp(info->av[ctr], "-dump") == 0) ||
				(ft_strcmp(info->av[ctr], "-n") == 0))
		{
			handle_flags(info, &ctr);
			continue ;
		}
		if (info->p_num == 0)
			info->p_num = get_next_player_number(info->champ_head);
		if ((fd = open(info->av[ctr], O_RDONLY)) < 0)
			unable_to_open(info, ctr);
		read_champ(fd, champ_ptr, info);
		info->p_num = 0;
		close(fd);
		ctr++;
		malloc_new_champ(info, ctr, &champ_ptr);
	}
}
