/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etermeau <etermeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:26:23 by etermeau          #+#    #+#             */
/*   Updated: 2014/11/18 16:46:47 by etermeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_slen(const char *str)
{
	size_t	o;

	o = 0;
	while (str[o])
		o++;
	return (o);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_slen(dst) + ft_slen((char *)src);
	while (dst[i] != '\0')
		i++;
	if (i > size)
		return (size + ft_slen((char *)src));
	while (src[j] != '\0' && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (len);
}
