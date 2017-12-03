/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:44:43 by sschafer          #+#    #+#             */
/*   Updated: 2017/06/10 14:07:12 by sschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int buffer;
	size_t src_len;
	size_t dst_len;

	i = 0;
	src_len = ft_strlen((char *)src);
	dst_len = ft_strlen(dst);
	buffer = size - dst_len;
	if (dst_len >= size)
		return (size + src_len);
	while ((src[i] != '\0') && (buffer > 1))
	{
		dst[dst_len + i] = src[i];
		++i;
		--buffer;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
