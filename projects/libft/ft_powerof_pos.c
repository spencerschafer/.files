/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topowerof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 07:34:10 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/26 09:15:00 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_powerof_pos(int n, int power)
{
	int		i;
	size_t	number;

	if (power == 0)
		return (number = 1);
	i = 1;
	number = n;
	while (i++ < power)
		number = (number * n);
	return (number);
}
