/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:15:44 by hstander          #+#    #+#             */
/*   Updated: 2017/09/14 08:47:35 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
**  Swops the bits of an int from little endian to big endian
**  and prints to file the correct number of bytes
*/

static int			swop_int_bits(int fd, int i, char c)
{
	unsigned char	byte_swop;

	if (c == '%')
	{
		i = (i >> 24 & 0xFF) | (i >> 8 & 0xFF00) |
		(i << 8 & 0xFF0000) | (i << 24 & 0xFF000000);
		write(fd, (void *)&i, 4);
	}
	else if (c == 'r')
	{
		byte_swop = i & 0xFF;
		write(fd, (void *)&byte_swop, 1);
	}
	else
	{
		i = (i >> 8 & 0x00FF) | (i << 8 & 0xFF00);
		write(fd, (void *)&i, 2);
	}
	return (i);
}

/*
** checks if the current argument is a label and returns correct value if true.
*/

static int			check_if_label(t_prog *lst, int arg, t_args *ag)
{
	char			*sub;
	int				arg_param;
	char			*temp;

	sub = NULL;
	if (lst->data[arg][1] == ':')
	{
		temp = ft_strsub(lst->data[arg], 2, (ft_strlen(lst->data[arg]) - 1));
		sub = ft_strjoin(temp, ":");
		free(temp);
		arg_param = get_label_offset(sub, ag, lst);
	}
	else
	{
		sub = ft_strsub(lst->data[arg], 1, (ft_strlen(lst->data[arg]) - 1));
		arg_param = ft_checknum(sub, ag);
	}
	free(sub);
	return (arg_param);
}

/*
**  Receives the file descriptor and ld's parameters as arguments.
**  Processes the parameters to get the int value of them, and
**  prints the first parameter's 4 bytes to file, and the second's
**  parameter's (a register) last byte to the file
*/

static void			create_param(t_args *ag, t_prog *lst)
{
	int				arg_param;
	char			*sub;

	sub = NULL;
	arg_param = 0;
	if (lst->data[1][0] == '%')
		arg_param = check_if_label(lst, 1, ag);
	else
		my_error(2, ag);
	arg_param = swop_int_bits(ag->fd, arg_param, lst->data[1][0]);
}

/*
**  Main function handling st opcode. Writes st's opcode to
**  the file indicated by fd, and call relevant functions to
**  write the argument coding byte and parameter values to file.
*/

void				ft_live(t_args *ag, t_prog *lst)
{
	unsigned char	hex;

	hex = 0x01;
	if (write(ag->fd, (void *)&hex, 1) < 0)
		my_error(3, ag);
	if (ft_arrlen(lst->data) != 2)
		my_error(4, ag);
	create_param(ag, lst);
}
