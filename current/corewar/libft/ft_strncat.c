/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:10:55 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/05/29 11:35:55 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t ctr;
	size_t src_ctr;

	ctr = ft_strlen(dest);
	src_ctr = 0;
	while (src[src_ctr] && src_ctr < n)
	{
		dest[ctr] = src[src_ctr];
		ctr++;
		src_ctr++;
	}
	dest[ctr] = '\0';
	return (dest);
}
