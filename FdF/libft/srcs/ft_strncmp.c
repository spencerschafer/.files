/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:41:49 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/10 14:26:26 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		value;

	i = 0;
	while (i < n)
	{
		if ((value = (unsigned char)s1[i] - (unsigned char)(s2[i])) != 0)
			return (value);
		if (s1[i] == '\0' || s2[i] == '\0')
			return (value);
		++i;
	}
	return (0);
}
