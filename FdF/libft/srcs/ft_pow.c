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

int		ft_pow(int number, int power)
{
	int		i;
	int		num;

	if (power == 0)
		return (number = 1);
	i = 1;
	num = number;
	while (i++ < power)
		num *= number;
	return (num);
}
