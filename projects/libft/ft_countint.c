/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 07:04:12 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/26 09:27:29 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**If input is negative the negative sign will be counted
**Therefore, when using this function, make note to remove 1 from the
**returned value in the program that calls the function i.e (i--).
*/

#include "libft.h"

size_t		ft_countint(int n)
{
	size_t	mod;
	size_t	number;
	size_t	i;

	i = 1;
	mod = 1;
	number = n;
	(n < 0) ? (number *= -1) : (number);
	while ((mod *= 10) <= number)
		i++;
	if (n < 0)
		i++;
	return (i);
}
