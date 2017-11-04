/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 09:03:27 by exam              #+#    #+#             */
/*   Updated: 2017/09/20 09:46:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_strrev(char *str)
{
	int i;
	int len;
	char temp;
	
	i = 0;
	len = ft_strlen(str) - 1;
	while (i < (len + 1 / 2))
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		++i;
		--len;
	}
}

char	*ft_itoa_base(int value, int base)
{
	int i;
	long number;
	char *str;
	char *map = "0123456789ABCDEF";

	if (!(base >= 2 && base <= 16))
		return (NULL);
	i = 0;
	number = value;
	str = (char *)malloc(sizeof(char) * (100));
	while (i < 100)
		str[i++] = '\0';
	if (value < 1)
		number *= -1;	
	i = 0;
	while (number != 0)
	{
		str[i++] = map[number % base];
		number /= base;
	}
	if (value < 1 && base == 10)
		str[i] = '-';
	if (value == 0)
		str[i] = '0';
	ft_strrev(str);
	return (str);
}
