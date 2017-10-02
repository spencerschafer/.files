/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:02:36 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/09 08:19:26 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	space_skipper(char *str)
{
	int ctr;

	ctr = 0;
	while (str[ctr] == ' ' || str[ctr] == '\t' || str[ctr] == '\f'
			|| str[ctr] == '\v' || str[ctr] == '\n' || str[ctr] == '\r')
		ctr++;
	return (ctr);
}

int			ft_atoi(char *str)
{
	int		ctr;
	long	total;
	int		neg_mult;
	long	temp;

	neg_mult = 1;
	ctr = space_skipper(str);
	total = 0;
	temp = 0;
	if (str[ctr] == '-' || str[ctr] == '+')
	{
		if (str[ctr] == '-')
			neg_mult *= -1;
		ctr++;
	}
	while (str[ctr] >= '0' && str[ctr] <= '9')
	{
		temp = total;
		total = total * 10 + (int)str[ctr] - '0';
		if (total < temp)
			return ((neg_mult < 0) ? 0 : -1);
		ctr++;
	}
	return (total * neg_mult);
}
