/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 16:01:27 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/18 15:28:21 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(char *str)
{
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	return (str);
}

int			ft_atoi(const char *str)
{
	int		sign;
	long	total;
	long	temp;

	str = ft_check((char *)str);
	total = 0;
	temp = 0;
	sign = (*str == '-') ? 1 : 0;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		temp = (total * 10) + (*str++ - '0');
		if (temp / 10 != total)
			return ((sign == 0) ? -1 : 0);
		total = temp;
	}
	return ((sign) ? (-total) : (total));
}
