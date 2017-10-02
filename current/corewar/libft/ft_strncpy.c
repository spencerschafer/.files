/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:11:13 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/05/29 11:29:39 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t ctr;

	ctr = 0;
	while (src[ctr] && (ctr < n))
	{
		dest[ctr] = src[ctr];
		ctr++;
	}
	while (ctr < n)
	{
		dest[ctr] = '\0';
		ctr++;
	}
	return (dest);
}
