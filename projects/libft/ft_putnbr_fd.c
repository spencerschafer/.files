/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 14:28:07 by sschafer          #+#    #+#             */
/*   Updated: 2017/07/03 11:26:41 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Formula is as follows:
**(number / (10^(length of number - 1)) % 10;
**This obtains the first digit, decrement the length to iterate through int.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	size_t	number;
	size_t	n_cpy;

	i = ft_countint(n);
	n_cpy = n;
	if (n < 0)
	{
		ft_putchar_fd(('-'), fd);
		n_cpy *= -1;
		i--;
	}
	while (--i >= 0)
	{
		number = (n_cpy / (ft_powerof_pos(10, i))) % 10;
		ft_putchar_fd((number + '0'), fd);
	}
}
