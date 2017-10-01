/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:48:01 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/09/14 08:51:58 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
**	Swops the bits of an int from little endian to big endian
**	and prints to file the correct number of bytes
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
		free(sub);
	}
	else
	{
		sub = ft_strsub(lst->data[arg], 1, (ft_strlen(lst->data[arg]) - 1));
		arg_param = ft_checknum(sub, ag);
		free(sub);
		if (lst->data[arg][0] == 'r' && (arg_param < 1 || arg_param > 16))
			my_error(1, ag);
	}
	return (arg_param);
}

/*
**	Receives the file descriptor and ld's parameters as arguments.
**	Processes the parameters to get the int value of them, and
**	prints the first parameter's 4 bytes to file, and the second's
**	parameter's (a register) last byte to the file
*/

static void			create_param(t_args *ag, t_prog *lst)
{
	int				arg_param;
	char			*sub;

	arg_param = 0;
	if (lst->data[1][0] == 'r' || lst->data[1][0] == '%')
		arg_param = check_if_label(lst, 1, ag);
	else if (lst->data[1][0] == ':')
		arg_param = arg_label(1, ag, lst);
	else
		arg_param = ft_atoi(lst->data[1]);
	arg_param = swop_int_bits(ag->fd, arg_param, lst->data[1][0]);
	if (lst->data[2][0] == 'r' || lst->data[2][0] == '%')
		arg_param = check_if_label(lst, 2, ag);
	else if (lst->data[2][0] == ':')
		arg_param = arg_label(2, ag, lst);
	else
		arg_param = ft_checknum(lst->data[2], ag);
	arg_param = swop_int_bits(ag->fd, arg_param, lst->data[2][0]);
	sub = ft_strsub(lst->data[3], 1, (ft_strlen(lst->data[3]) - 1));
	arg_param = ft_checknum(sub, ag);
	free(sub);
	if (arg_param < 1 || arg_param > 16)
		my_error(1, ag);
	arg_param = swop_int_bits(ag->fd, arg_param, lst->data[3][0]);
}

/*
**	Function receives file descriptor and ld's parameters as arguments.
**	Processes the parameters into an argument code byte, and writes the
**	acb to the file indicated by fd.
*/

static void			create_acb(t_args *ag, char *arg1, char *arg2, char *arg3)
{
	unsigned char	hex;

	if (arg3[0] != 'r')
		my_error(2, ag);
	if (arg1[0] == '%')
		hex = 0b10000000;
	else if (arg1[0] == 'r')
		hex = 0b01000000;
	else
		hex = 0b11000000;
	if (arg2[0] == 'r')
		hex = hex | 0b00010000;
	else if (arg2[0] == '%')
		hex = hex | 0b00100000;
	else
		hex = hex | 0b00110000;
	hex = hex | 0b00000100;
	if (write(ag->fd, (void *)&hex, 1) < 0)
		my_error(3, ag);
}

/*
**	Main function handling st opcode. Writes st's opcode to
**	the file indicated by fd, and call relevant functions to
**	write the argument coding byte and parameter values to file.
*/

void				ft_or(t_args *ag, t_prog *lst)
{
	unsigned char	hex;

	hex = 0x07;
	if (write(ag->fd, (void *)&hex, 1) < 0)
		my_error(3, ag);
	if (ft_arrlen(lst->data) != 4)
		my_error(4, ag);
	create_acb(ag, lst->data[1], lst->data[2], lst->data[3]);
	create_param(ag, lst);
}
