/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_offset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 10:33:24 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/08/28 16:59:41 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
**	Takes a 2d array containing an opcode and its arguments
**	and calculates the number of bytes the opcode, argument
**	coding byte and arguments will require, and returns the
**	total.
*/

static int		calc_bytes(int op_ctr, char **list_data)
{
	int			ctr;
	int			index;

	ctr = 1;
	index = 1;
	if (g_op_tab[op_ctr].id == 1)
		return (5);
	if (g_op_tab[op_ctr].has_acb == 1)
		ctr++;
	while (list_data[index])
	{
		if (list_data[index][0] == 'r')
			ctr++;
		else if (list_data[index][0] == '%')
		{
			if (g_op_tab[op_ctr].is_index == 0)
				ctr += 4;
			else
				ctr += 2;
		}
		else
			ctr += 2;
		index++;
	}
	return (ctr);
}

/*
**	Takes a list element which contain opcodes, looks up the opcode
**	in the optab, and calls calc_bytes function to calc the number
**	of bytes the specific opcode requires. Error check if the opcode
**	was not found. Returns the count received from calc_bytes.
*/

static int		if_data(t_prog *lst, t_args *ag)
{
	int			ctr;
	int			byte_count;

	ctr = 0;
	byte_count = 0;
	while (ctr < 16)
	{
		if (ft_strcmp(lst->data[0], g_op_tab[ctr].name) == 0)
		{
			byte_count += calc_bytes(ctr, lst->data);
			break ;
		}
		ctr++;
	}
	if (ctr == 16)
		my_error(7, ag);
	return (byte_count);
}

/*
**	Function iterates through the list of lines from read program
**	and if there is data which needs to be converted to bytecode
**	it call if_data function to calculate the number of bytes for
**	that line. The total number of bytes in the file to that point
**	is added to that list element, and the grand total number of
**	bytes the bytecode will require is returned.
*/

int				label_offset(t_prog *lst, t_args *ag)
{
	int			tot_bytes;

	tot_bytes = 0;
	while (lst)
	{
		lst->bytes = tot_bytes;
		ag->lst = lst;
		if (lst->data != NULL && lst->data[0])
			tot_bytes += if_data(lst, ag);
		lst = lst->next;
	}
	return (tot_bytes);
}
