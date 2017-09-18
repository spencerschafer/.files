/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:06:59 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/06/02 08:51:02 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t d_len;
	size_t s_len;
	size_t ctr;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	ctr = 0;
	if (size < d_len)
		return (s_len + size);
	ctr = d_len;
	while ((ctr + 1) < size && src)
	{
		dest[ctr] = *src;
		ctr++;
		src++;
	}
	dest[ctr] = '\0';
	return (d_len + s_len);
}
