/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:02:17 by rojones           #+#    #+#             */
/*   Updated: 2016/10/04 13:07:43 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_system.h"

char	*ft_strnew(size_t size)
{
	char	*re;
	int		i;

	i = 0;
	if (!(re = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i <= (int)size)
	{
		re[i] = '\0';
		i++;
	}
	return (re);
}
