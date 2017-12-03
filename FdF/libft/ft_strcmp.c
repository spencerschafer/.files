/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:46:50 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/08 15:56:55 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int value;

	i = 0;
	while (s1[i] != '\0')
	{
		if ((value = (unsigned char)s1[i] - (unsigned char)s2[i]) != 0)
			return (value);
		++i;
	}
	if (s2[i] != '\0')
		return (0 - (unsigned char)s2[i]);
	return (0);
}
