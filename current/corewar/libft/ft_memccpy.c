/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvan-roo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 11:27:51 by gvan-roo          #+#    #+#             */
/*   Updated: 2017/05/30 14:02:19 by gvan-roo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*ptr_d;
	const char	*ptr_s;
	size_t		ctr;

	ptr_d = dest;
	ptr_s = src;
	ctr = 0;
	while (ctr < n)
	{
		ptr_d[ctr] = ptr_s[ctr];
		if (ptr_s[ctr] == c)
		{
			ctr++;
			return ((char *)&ptr_d[ctr]);
		}
		ctr++;
	}
	return (NULL);
}
