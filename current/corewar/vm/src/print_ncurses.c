/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ncurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 16:07:23 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/12 16:15:03 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vm.h"

/*
**	Function for printing out bytes in hexadecimal
*/

static void				ft_print_hex_nc(int c)
{
	char				*map;

	map = ft_strdup("0123456789abcdef");
	addch(*(map + (c / 16)));
	addch(*(map + (c % 16)));
	free(map);
}

/*
**	Subfunction of print memory
**	bit is the amount of bytes printed on a single nine
*/

static unsigned char	*print_line_nc(unsigned char *mem, size_t size, int bit)
{
	unsigned char		*mem_c;

	mem_c = mem;
	while ((size_t)(mem_c - mem) < size && (mem_c - mem) < bit)
	{
		ft_print_hex_nc(*mem_c);
		printw(" ");
		++mem_c;
	}
	while ((mem_c - mem) < bit)
	{
		printw("   ");
		++mem_c;
	}
	return (mem_c);
}

/*
**	Function for printing out the memory of at address addr
**	of size size.
*/

void					print_mem_nc(const void *addr, size_t size, int bit)
{
	unsigned char		*mem;

	mem = (unsigned char *)addr;
	while ((long int)size > 0)
	{
		mem = print_line_nc(mem, size, bit);
		printw("\n");
		refresh();
		size -= bit;
	}
}
