/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:13:07 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/10 14:29:58 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s > d)
	{
		while (i < len)
		{
			d[i] = s[i];
			++i;
		}
		return (d);
	}
	while (len > 0)
	{
		d[len - 1] = s[len - 1];
		--len;
	}
	return (d);
}
