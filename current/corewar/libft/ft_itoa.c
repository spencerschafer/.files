/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:20:59 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/09 13:44:54 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_neg(int n, char *str)
{
	char	*temp;

	if (n < 0)
	{
		temp = (char *)ft_memalloc(2);
		if (temp == NULL)
			return (NULL);
		temp[0] = '-';
		temp = ft_strjoin(temp, str);
		free(str);
	}
	else if (n == 0)
	{
		temp = (char *)ft_memalloc(2);
		if (temp == NULL)
			return (NULL);
		temp[0] = '0';
		temp = ft_strjoin(temp, str);
		free(str);
	}
	else
		return (str);
	return (temp);
}

static int	neg_checker(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);
	return (1);
}

char		*ft_itoa(int n)
{
	char	*str;
	char	*nbr;
	char	*temp;
	int		neg;

	str = (char *)ft_memalloc(1);
	nbr = (char *)ft_memalloc(2);
	if (nbr == NULL || str == NULL)
		return (NULL);
	neg = neg_checker(n);
	while (n)
	{
		if (n < 0)
			nbr[0] = (n % 10) * -1 + '0';
		else
			nbr[0] = n % 10 + '0';
		temp = str;
		str = ft_strjoin(nbr, str);
		free(temp);
		if (str == NULL)
			return (NULL);
		n /= 10;
	}
	return (if_neg(neg, str));
}
