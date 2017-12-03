/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 07:01:23 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/26 09:29:59 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**Formula is as follows:
**(number / (10^(length of number - 1)) % 10;
**This obtains the first digit, decrement the length to iterate through int.
*/

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	size_t	j;
	size_t	number;
	size_t	n_cpy;
	char	*newstr;

	i = ft_countint(n);
	j = 0;
	n_cpy = n;
	if (!(newstr = ft_strnew(i)))
		return (NULL);
	if (n < 0)
	{
		newstr[j++] = '-';
		n_cpy *= -1;
		--i;
	}
	while (--i >= 0)
	{
		number = (n_cpy / (ft_pow(10, i))) % 10;
		newstr[j++] = number + '0';
	}
	newstr[j] = '\0';
	return (newstr);
}
