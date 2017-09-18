/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/18 11:04:39 by hstander          #+#    #+#             */
/*   Updated: 2017/09/14 08:41:32 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/asm.h"

/*
** gets the length of a 2D array.
*/

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/*
** swaps bytes for BIG ENDIAN.
*/

void	swap_bytes(unsigned int i, int fd)
{
	unsigned char	buf[4];

	buf[0] = (i & 0xff000000) >> 24;
	buf[1] = (i & 0x00ff0000) >> 16;
	buf[2] = (i & 0x0000ff00) >> 8;
	buf[3] = (i & 0x000000ff);
	write(fd, buf, sizeof(i));
}

/*
** finds the first occurence of c in str and returns the index of where it was
** found, else it returns -1
*/

int		ft_chr_i(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
** finds the last occurence of c in str and returns the index of where it was
** found, else it returns -1
*/

int		ft_chrn_i(char *str, char c)
{
	int		i;

	i = ft_strlen(str);
	while (i > -1)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

int		ft_checknum(char *sub, t_args *ag)
{
	int		i;

	i = 0;
	while (sub[i])
	{
		if (ft_isdigit(sub[i]) == 0)
		{
			if (sub[i] != '-')
			{
				my_error(2, ag);
			}
		}
		i++;
	}
	return (ft_atoi(sub));
}
