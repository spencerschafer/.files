/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 07:21:01 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/10 14:32:53 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	char	*pd;
	char	*ps;

	i = 0;
	pd = (char *)dst;
	ps = (char *)src;
	while (i < n)
	{
		pd[i] = ps[i];
		if (ps[i] == (char)c)
			return (pd + (i + 1));
		++i;
	}
	return (NULL);
}
