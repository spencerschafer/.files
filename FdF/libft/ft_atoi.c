/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:01:27 by sschafer          #+#    #+#             */
/*   Updated: 2017/12/10 15:28:21 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long		total;
	long		temp;

	sign = 0;
	total = 0;
	str = ft_skipwhitespace((char *)str);
	if ((str[0] == '+') || (sign = (str[0] == '-')))
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		temp = (total * 10) + (*str++ - '0');
		if (temp / 10 != total)
			return (!sign ? -1 : 0);
		total = temp;
	}
	return (sign ? (int)-total : (int)total);
}
